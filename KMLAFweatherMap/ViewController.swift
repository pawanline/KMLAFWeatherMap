//
//  ViewController.swift
//  KMLAFweatherMap
//
//  Created by Pawan Kumar on 20/12/19.
//  Copyright © 2019 Pawan Kumar. All rights reserved.
//

import UIKit
import AerisWeatherKit
import AerisMapKit

class ViewController: UIViewController {
   
    // MARK: - IB Outlet
    @IBOutlet weak var switchButton: UISwitch!
    
    // MARK: - Properties
    private var kmlParser: KMLParser!
    let afWeatherMapView = AWFWeatherMap(mapType: .apple,config: MyWeatherAppConfig())
    
    // MARK: - View Life Cycle
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.configureMap()
        self.kmlSetup()
    }

    // MARK: - Helper methods
    
        func configureMap() {
        
        self.afWeatherMapView.weatherMapView.frame = view.bounds
        self.view.insertSubview(afWeatherMapView.weatherMapView, at: 0)
        self.afWeatherMapView.addSources(forLayerTypes: [.radar])
        self.afWeatherMapView.delegate = self
        self.afWeatherMapView.mapViewDelegate = self
       }
    
    
    func kmlSetup() {
        let url = Bundle.main.url(forResource: "USStatePolygons", withExtension: "kml")!
        self.kmlParser = KMLParser(url: url)
        self.kmlParser.parseKML()
        let overlays = self.kmlParser.overlays
        if let mapView = self.afWeatherMapView.strategy.mapView as? MKMapView {
            mapView.addOverlays(overlays)
        }
        
        var flyTo = MKMapRect.null
        for overlay in overlays {
            if flyTo.isNull {
                flyTo = overlay.boundingMapRect
            } else {
                flyTo = flyTo.union(overlay.boundingMapRect)
            }
        }
        
        // Position the map so that all overlays and annotations are visible on screen.
        if let mapView = self.afWeatherMapView.strategy.mapView as? MKMapView {
            mapView.setVisibleMapRect(flyTo, animated: true)
        }
        
        if let mapView = self.afWeatherMapView.strategy.mapView as? MKMapView {
            mapView.setCenterCoordinate( CLLocationCoordinate2D(latitude: 43.075970, longitude: -107.290283), withZoomLevel: 4, animated: true)
        }
    }
    
    // MARK: - IB Action 
    
    @IBAction func overlayLoopChanged(_ sender: UISwitch) {
        if sender.isOn {
            afWeatherMapView.enableAutoRefresh()
        } else {
            afWeatherMapView.disableAutoRefresh()
        }
    }
    
}



// MARK: - Map view delegate
extension ViewController: MKMapViewDelegate {
  func mapView(_ mapView: MKMapView, rendererFor overlay: MKOverlay) -> MKOverlayRenderer {
      if let renderer = self.kmlParser.rendererForOverlay(overlay) {
          return renderer
      } else if let strategy = afWeatherMapView.strategy as? AWFAppleMapStrategy {
          // set mapViewDelegate to nil to prevent recursively calling this method from the map strategy
          // and reassign it after grabbing the default overlay renderer from the strategy
          afWeatherMapView.mapViewDelegate = nil
          let renderer = strategy.mapView(mapView, rendererFor: overlay)
          afWeatherMapView.mapViewDelegate = self
          return renderer
      }
      return MKOverlayRenderer(overlay: overlay)
  }
}

extension ViewController: AWFWeatherMapDelegate {
    func weatherMap(_ weatherMap: AWFWeatherMap, didAddLayerForType layerType: AWFMapLayer) {
        print("layer type added \(layerType)")
    }
}


// MARK: - MK map view

extension MKMapView {
    open var currentZoomLevel: Int {
        let maxZoom: Double = 24
        let zoomScale = visibleMapRect.size.width / Double(frame.size.width)
        let zoomExponent = log2(zoomScale)
        return Int(maxZoom - ceil(zoomExponent))
    }
    
    open func setCenterCoordinate(_ centerCoordinate: CLLocationCoordinate2D,
                                  withZoomLevel zoomLevel: Int,
                                  animated: Bool) {
        let minZoomLevel = min(zoomLevel, 28)
        
        let span = coordinateSpan(centerCoordinate, andZoomLevel: minZoomLevel)
        let region = MKCoordinateRegion(center: centerCoordinate, span: span)
        
        setRegion(region, animated: animated)
    }
}

 

let MERCATOR_OFFSET: Double = 268435456 // swiftlint:disable:this identifier_name
let MERCATOR_RADIUS: Double = 85445659.44705395 // swiftlint:disable:this identifier_name

 

struct PixelSpace {
    public var x: Double // swiftlint:disable:this identifier_name
    public var y: Double // swiftlint:disable:this identifier_name
}

 

fileprivate extension MKMapView {
    func coordinateSpan(_ centerCoordinate: CLLocationCoordinate2D, andZoomLevel zoomLevel: Int) -> MKCoordinateSpan {
        let space = pixelSpace(fromLongitue: centerCoordinate.longitude, withLatitude: centerCoordinate.latitude)
        
        // determine the scale value from the zoom level
        let zoomExponent = 20 - zoomLevel
        let zoomScale = pow(2.0, Double(zoomExponent))
        
        // scale the map’s size in pixel space
        let mapSizeInPixels = self.bounds.size
        let scaledMapWidth = Double(mapSizeInPixels.width) * zoomScale
        let scaledMapHeight = Double(mapSizeInPixels.height) * zoomScale
        
        // figure out the position of the top-left pixel
        let topLeftPixelX = space.x - (scaledMapWidth / 2)
        let topLeftPixelY = space.y - (scaledMapHeight / 2)
        
        var minSpace = space
        minSpace.x = topLeftPixelX
        minSpace.y = topLeftPixelY
        
        var maxSpace = space
        maxSpace.x += scaledMapWidth
        maxSpace.y += scaledMapHeight
        
        // find delta between left and right longitudes
        let minLongitude = coordinate(fromPixelSpace: minSpace).longitude
        let maxLongitude = coordinate(fromPixelSpace: maxSpace).longitude
        let longitudeDelta = maxLongitude - minLongitude
        
        // find delta between top and bottom latitudes
        let minLatitude = coordinate(fromPixelSpace: minSpace).latitude
        let maxLatitude = coordinate(fromPixelSpace: maxSpace).latitude
        let latitudeDelta = -1 * (maxLatitude - minLatitude)
        
        return MKCoordinateSpan(latitudeDelta: latitudeDelta, longitudeDelta: longitudeDelta)
    }
    
    func pixelSpace(fromLongitue longitude: Double, withLatitude latitude: Double) -> PixelSpace {
        let x = round(MERCATOR_OFFSET + MERCATOR_RADIUS * longitude * Double.pi / 180.0)
        let y = round(MERCATOR_OFFSET - MERCATOR_RADIUS * log((1 + sin(latitude * Double.pi / 180.0)) / (1 - sin(latitude * Double.pi / 180.0))) / 2.0) // swiftlint:disable:this line_length
        return PixelSpace(x: x, y: y)
    }
    
    func coordinate(fromPixelSpace pixelSpace: PixelSpace) -> CLLocationCoordinate2D {
        let longitude = ((round(pixelSpace.x) - MERCATOR_OFFSET) / MERCATOR_RADIUS) * 180.0 / Double.pi
        let latitude = (Double.pi / 2.0 - 2.0 * atan(exp((round(pixelSpace.y) - MERCATOR_OFFSET) / MERCATOR_RADIUS))) * 180.0 / Double.pi // swiftlint:disable:this line_length
        return CLLocationCoordinate2D(latitude: latitude, longitude: longitude)
    }
}


