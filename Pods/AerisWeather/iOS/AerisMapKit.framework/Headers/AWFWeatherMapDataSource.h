//
//  AWFWeatherMapDataSource.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 7/20/17.
//  Copyright © 2017 AerisWeather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AerisMapKit/AWFAnnotation.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFWeatherMap;

/**
 The `AWFWeatherMapDataSource` protocol is adopted by an object that provides a weather map with the information it needs for
 representing data on the map.
 */
@protocol AWFWeatherMapDataSource <NSObject>
@optional

/**
 Asks the data source for the request options to use for the specified layer.
 
 This method allows you to override the default request options for point and shape data sources on a weather map. Returning `nil` will inform the
 weather map to use the default request options for the layer. Request options are not used for raster or tile map content sources.

 @param weatherMap The weather map requesting the options
 @param layerType The layer that will perform the request
 @return The request options to use when requesting data for the layer
 */
- (nullable AWFWeatherRequestOptions *)weatherMap:(AWFWeatherMap *)weatherMap requestOptionsForLayer:(AWFMapLayer)layerType;

/**
 Asks the data source for the content view to display in an annotation's callout view.
 
 @param weatherMap The weather map requesting the object
 @param annotation The annotation associated with the callout view
 @return A view to be displayed in the callout for the annotation
 */
- (nullable UIView *)weatherMap:(AWFWeatherMap *)weatherMap calloutViewForAnnotation:(id<AWFAnnotation>)annotation;

/**
 Asks the data source for the content view to display when a weather map receives a long press gesture.

 @param weatherMap The weather map that received the long press
 @return A view to be displayed in the callout
 */
- (nullable UIView *)weatherMapCalloutContentViewForLongPress:(AWFWeatherMap *)weatherMap;

@end

NS_ASSUME_NONNULL_END
