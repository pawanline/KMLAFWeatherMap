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
   
    
    // MARK: - Properties
    private var kmlParser: KMLParser!
    let afWeatherMapView = AWFWeatherMap(mapType: .apple)

    
    // MARK: - View Life Cycle
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.configureMap()
        self.kmlSetup()
    }

    
    // MARK: - Helper methods
    
    func configureMap() {
        self.afWeatherMapView.config.refreshInterval = 2 * AWFSecondInterval
        self.afWeatherMapView.weatherMapView.frame = view.bounds
        self.view.addSubview(afWeatherMapView.weatherMapView)
        self.afWeatherMapView.delegate = self
        
        // FIXME: Not Working with radar type
     //   self.afWeatherMapView.addSource(forLayerType: .airQuality)
        
        
        self.afWeatherMapView.addSources(forLayerTypes: [.airQuality])
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
            mapView.delegate = self
        }
    }
    
}


extension ViewController: MKMapViewDelegate {
  func mapView(_ mapView: MKMapView, rendererFor overlay: MKOverlay) -> MKOverlayRenderer {
   if let renderer = self.kmlParser.rendererForOverlay(overlay) {
          return renderer
   } else if overlay is AWFMKTileOverlay {
        return MKOverlayRenderer(overlay: overlay)
      }
    return MKOverlayRenderer(overlay: overlay)
  }
}

extension ViewController: AWFWeatherMapDelegate {
    func weatherMap(_ weatherMap: AWFWeatherMap, didAddLayerForType layerType: AWFMapLayer) {
        print("layer type added \(layerType)")
    }
}
