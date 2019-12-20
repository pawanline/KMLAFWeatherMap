//
//  AWFPolyline.h
//  AerisMap
//
//  Created by Nicholas Shipes on 8/15/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AerisWeatherKit.h>
#import <AerisMapKit/AWFDataRepresentable.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFGeographicObject;

/**
 The `AWFPolyline` protocol defines the required properties and methods for polyline overlay objects for a specific mapping SDK.
 */
@protocol AWFPolyline <AWFDataRepresentable>
@required

/**
 Creates and returns a new polyline instance initialized with the `object`.
 
 This method must be implemented by a base class for each map strategy in order to create the proper polyline overlay instance
 required by the strategy's map view.
 
 @param object The `AWFGeographicObject` instance to create a polyline from.
 @return An initialized polyline object.
 */
+ (instancetype)polylineWithGeographicObject:(AWFGeographicObject *)object;

/**
 Creates and returns a new polyline instance initialized with the `geoPolygon`.
 
 This method must be implemented by a base class for each map strategy in order to create the proper polyline overlay instance 
 required by the strategy's map view.
 
 @param geoPolygon The `AWFGeoPolygon` instance to create a polyline from.
 @return An initialized polyline object.
 */
+ (instancetype)polylineWithGeoPolygon:(AWFGeoPolygon *)geoPolygon;

/**
 Creates and returns a new polyline instance initialized with the `geoPolygon` and `object`.
 
 @param geoPolygon The `AWFGeoPolygon` instance to create a polyline from
 @param object The model object to associate with the polygon
 @return An initialized polyline object
 */
+ (instancetype)polylineWithGeoPolygon:(AWFGeoPolygon *)geoPolygon object:(nullable AWFWeatherObject *)object;

/**
 Creates and returns an empty polyline instance. This instance will not create a polyline overlay instance required for the map.
 
 @return An initialized empty polyline object.
 */
+ (instancetype)polyline;

@end

NS_ASSUME_NONNULL_END
