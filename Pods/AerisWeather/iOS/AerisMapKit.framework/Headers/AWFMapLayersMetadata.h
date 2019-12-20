//
//  AWFMapLayersMetadata.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 6/7/18.
//  Copyright © 2018 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AerisWeatherKit.h>
#import "AWFMapLayer.h"

NS_ASSUME_NONNULL_BEGIN

typedef NSString *AWFLayerModifierType NS_TYPED_ENUM;
FOUNDATION_EXPORT AWFLayerModifierType const AWFLayerModifierTypeModel;
FOUNDATION_EXPORT AWFLayerModifierType const AWFLayerModifierTypeCategory;
FOUNDATION_EXPORT AWFLayerModifierType const AWFLayerModifierTypeTheme;
FOUNDATION_EXPORT AWFLayerModifierType const AWFLayerModifierTypeFontSize;

@class AWFMapLayerModifier;
@class AWFMapLayerModifierCategory;

@interface AWFMapLayersMetadata : NSObject

typedef NSDictionary<AWFLayerModifierType, AWFMapLayerModifierCategory *> *AWFMapLayerOptions;
typedef void (^AWFLayerMetadataLoadCallback)(void);

/**
 The cached layers metadata keyed by layer type. The identifier will be a `AWFMapLayer` string value.
 */
@property (nonatomic, strong, readonly, nullable) NSDictionary<AWFMapLayer, NSDictionary<NSString *, AWFMapLayerModifierCategory *> *> *metadata;

/**
 A Boolean value indicating whether the layer metadata is currently being requested.
 */
@property (nonatomic, readonly) BOOL isLoading;

/**
 A Boolean value indicating whether the required layers metadata has been loaded and data instantiated.
 */
@property (nonatomic, readonly) BOOL hasLoaded;

/**
 Tells the object to request the map layers metadata from the Aeris Maps API and setup the map layer options.
 
 @param completionBlock The block to execute once all layer option instances have been setup.
 */
- (void)getWithCompletion:(nullable void (^)(void))completionBlock;
- (void)addLoadCompletionCallback:(AWFLayerMetadataLoadCallback)callback;

/**
 Returns whether the specified forecast model type is supported by the layer type.

 @param forecastModel Forecast model type to check support for
 @param layerType Layer type
 @return `YES` if the specified forecast model is supported by the layer type, otherwise `NO`.
 */
- (BOOL)isForecastModel:(AWFForecastModelType)forecastModel supportedByLayerType:(AWFMapLayer)layerType;

@end


@interface AWFMapLayerModifierCategory : NSObject

@property (nonatomic, copy) NSString *label;
@property (nonatomic, copy) NSString *details;
@property (nonatomic, strong) NSArray<AWFMapLayerModifier *> *modifiers;

@end


@interface AWFMapLayerModifier : NSObject

@property (nonatomic, copy) NSString *identifier;
@property (nonatomic, copy) NSString *label;

@end

NS_ASSUME_NONNULL_END
