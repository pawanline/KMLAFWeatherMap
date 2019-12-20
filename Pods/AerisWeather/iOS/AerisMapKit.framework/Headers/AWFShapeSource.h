//
//  AWFShapeSource.h
//  AerisMap
//
//  Created by Nicholas Shipes on 3/11/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AerisWeatherKit.h>
#import <AerisMapKit/AWFMapContentSource.h>
#import <AerisMapKit/AWFStylable.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFPolygonStyle, AWFLegendStyle;

/**
 An `AWFShapeSource` object represents a map content source that maintains shape/polygon data on a map.
 */
@interface AWFShapeSource : AWFMapContentSource <AWFStylable>

/**
 The polygons being managed by the content source (readonly).
 */
@property (readonly, nonatomic, strong, nullable) NSArray<id<AWFPolygon>> *polygons;

/**
 The polylines being managed by the content source (readonly).
 */
@property (readonly, nonatomic, strong, nullable) NSArray<id<AWFPolyline>> *polylines;

/**
 The combined polygons and polylines managed by this content source (readonly).
 */
@property (readonly, nonatomic, nullable) NSArray *overlays;

/**
 The options to use when requesting data for the overlay.
 */
@property (nonatomic, strong, nullable) AWFWeatherRequestOptions *requestOptions;

/**
 The request action to use when requesting data for the content source.
 */
@property (nonatomic, copy, nullable) NSString *requestAction;

/**
 The style to use when rendering polygons for this content source on the weather map.
 */
@property (nonatomic, strong, nullable) id style;

/**
 The legend style used when rendering polygons for the content source.
 */
@property (nonatomic, strong, nullable) AWFLegendStyle *legendStyle;

/**
 Requests data for the overlay within the region described by the specified coordinate bounds.
 
 @param bounds  The coordinate bounds to request data for.
 @param results The completion block when the request finishes or fails.
 */
- (void)loadForMapBounds:(AWFMapCoordinateBounds *)bounds results:(void (^)(NSArray *results, NSError *error))results;

/**
 Requests data for the overlay within the region described the the specified coordinate bounds and the date range.
 
 @param bounds   The coordinate bounds to request data for
 @param fromDate The starting date to use for the request, or `nil` to use the current date and time
 @param toDate   The ending date to use for the request, or `nil` to use the current date and time
 @param results  The completion block when the request finishes or fails
 */
- (void)loadForMapBounds:(AWFMapCoordinateBounds *)bounds fromDate:(NSDate *)fromDate toDate:(NSDate *)toDate results:(void (^)(NSArray *, NSError *))results;

/**
 Requests data for the overlay using a search request and the specified `requestOptions`.
 
 @param results The completion block when the request completes or fails.
 */
- (void)loadForMapWithResults:(void (^)(NSArray *results, NSError *error))results;

/**
 Cancels any active requests and prepared for a new request.
 */
- (void)reset;

///**
// Performs additional actions on the overlay's polygons after new data has been loaded.
// 
// Subclasses should override this method to provide necessary actions on polygon objects, such as setting additional properties needed
// for annotation views. The default implementation does not do anything.
// 
// @param polygons The polygons to perform the additional actions on.
// @param completion  The completion block when all actions have completed.
// */
//- (void)processPolygons:(NSArray *)polygons completion:(void (^)(NSArray *polygons))completion;

@end

NS_ASSUME_NONNULL_END
