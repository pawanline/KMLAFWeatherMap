//
//  AFWeatherMapConfig.h
//  AerisMap
//
//  Created by Nicholas Shipes on 10/16/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AerisWeatherKit/AerisWeatherKit.h>
#import <AerisMapKit/AWFWeatherLayer.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFMapItemStyle;
@class AWFStyledAnnotation, AWFPolygon, AWFAnnotationStyle, AWFPolygonStyle, AWFOverlayStyle, AWFLegendStyle;
@protocol AWFPolygon, AWFStyledAnnotation;

/**
 An `AWFWeatherMapConfig` object provides all of the configurable settings to a {@link AWFWeatherMap} instance. This object is
 usually applied to a weather map object at initialization.
 
 The default implementation of a `AWFWeatherMapConfig` object assigns all of the default values needed by a weather map
 instance. In order to override these default settings, you must subclass `AWFWeatherMapConfig` and assign your custom values
 in your subclass's implementation.
 */
@interface AWFWeatherMapConfig : NSObject

/**
 Initializes and returns a map configuration instance with the default settings.
 
 @return The intialized map configuration instance.
 */
+ (instancetype)config;

//-----------------------------------------------------------------------------
// @name General Options
//-----------------------------------------------------------------------------

/**
 Update interval to update active map layers when auto-refresh is enabled for the weather map.
 
 @see AWFWeatherMap
 */
@property (nonatomic, assign) NSTimeInterval refreshInterval;

//-----------------------------------------------------------------------------
// @name Overlays
//-----------------------------------------------------------------------------

/**
 The map level at which to place tile overlays.
 
 The default value for this property is `MKOverlayLevelAboveRoads`.
 */
@property (nonatomic, assign) MKOverlayLevel tileOverlayLevel;

/**
 The opacity to apply to the weather map tile overlays. Default value is `0.9`.
 */
@property (nonatomic, assign) CGFloat tileOverlayAlpha;

/**
 Returns whether higher-quality raster overlay imagery should be requested for retina devices. Note that enabling this will result in sightly longer response
 times for raster tile requests. The default is `YES`.
 */
@property (nonatomic, assign) BOOL shouldUseRetinaImagery;

/**
 Returns whether higher-quality raster overlay imagery should be requested for retina devices for animations. Note that enabling this will result
 in sightly longer response times for raster tiles and animation data requests. The default is `YES`.
 */
@property (nonatomic, assign) BOOL shouldUseRetinaImageryForAnimation;

/**
 Whether to display state province lines over the weather layers. The default value is `NO`.
 */
@property (nonatomic, assign) BOOL showsStateProvinceLines;

/**
 Whether to display county lines over the weather layers. The default value is `NO`.
 */
@property (nonatomic, assign) BOOL showsCountyLines;

/**
 Whether water should be masked out from surface-based weather layers (e.g. surface temperatures, dew points, etc). The default value is `YES`.
 */
@property (nonatomic, assign) BOOL shouldApplyWaterMaskToSurfaceLayers;

/**
 Whether past layers should always remain visible, even for future time intervals. Default value is `NO`.
 */
@property (nonatomic, assign) BOOL shouldAlwaysShowPastLayers;

/**
 Whether future layers should always remain visible, even for past time intervals. Default value is `NO`.
 */
@property (nonatomic, assign) BOOL shouldAlwaysShowFutureLayers;

//-----------------------------------------------------------------------------
// @name Annotations
//-----------------------------------------------------------------------------

/**
 Determines whether point and shape data should be reloaded when the visible map region changes.
 */
@property (nonatomic, assign) BOOL shouldReloadDataOnRegionChange;

/**
 The minimum distance required in screen points the map region must change before point and shape data is reloaded.
 */
@property (nonatomic, assign) CGFloat distanceRequiredToReloadData;

//-----------------------------------------------------------------------------
// @name Animation/Timeline
//-----------------------------------------------------------------------------

/**
 A Boolean that determines whether overlays can be animated on the weather map.
 
 The default value of this property is `YES`.
 */
@property (nonatomic, assign) BOOL animationEnabled;

/**
 The length of the animation in seconds.
 
 The default value of this property is `2.0` seconds.
 */
@property (nonatomic, assign) NSTimeInterval animationDuration;

/**
 The number of seconds to hold the last frame of the animation before replaying from the beginning.
 
 The default value of this property is `2.0` seconds.
 */
@property (nonatomic, assign) NSTimeInterval animationEndDelay;

/**
 A Boolean that determines whether image overlays should crossfade between intervals during animation playback.
 
 The default value of this property is `NO`.
 */
@property (nonatomic, assign) BOOL animationCrossfadeEnabled;

/**
 The maximum number of images to request for an animation.
 
 If the total number of images available within the animation's time range is greater than this value, the image intervals will
 be adjusted to be evenly spaced so that the total number of images never exceeds this value. Assigning a relative low value to this
 property will result in faster animation load times, whereas larger numbers will result in smoother animations for timelines
 with larger time ranges.
 
 The default value of this property is `20`.
 */
@property (nonatomic, assign) NSInteger maximumIntervalsForAnimation;

/**
 The time interval offset to start the animation timeline relative to the current date and time, in seconds.
 
 This value must be less than the value for `timelineEndOffsetFromNow`. A timeline with the same start and end
 time offsets will not animate.
 
 The default value of this property is `-7200`, or `-2 * AWF_HOUR` (2 hours ago).
 */
@property (nonatomic, assign) NSTimeInterval timelineStartOffsetFromNow;

/**
 The time interval offset for the animation timeline to end relative to the current date and time, in seconds.
 
 This value must be greater than the value for `timelineStartOffsetFromNow`. A timeline with the same start and end
 time offsets will not animate.
 
 The default value of this property is `0` (current time).
 */
@property (nonatomic, assign) NSTimeInterval timelineEndOffsetFromNow;

/**
 Determines whether or not scrubbing the timeline also updates the active data layers.
 
 If an animation has successfully loaded all data required for playback, scrubbing the timeline will result in smooth transitions between
 intervals. However, if animation data has not yet been loaded, then scrubbing the timeline will result in a choppy transition between intervals as
 the overlay is invalidated and redrawn at each interval. This applies to image and tile data layers only.
 */
@property (nonatomic, assign) BOOL timelineScrubbingEnabled;

/// A Boolean value that determines whether the weather map should show animation loading progress, meaning the visible data will update to the last
/// loaded interval during the loading process. Default value is `YES`.
@property (nonatomic, assign) BOOL showAnimationLoadingProgress;

/**
 A Boolean value indicating whether to display text point data on the map while tile data is animating. The default is `NO`.
 */
@property (nonatomic, assign) BOOL showTextDataWhileAnimating;

/// A Boolean value that determines if the animation should automatically begin playing when all required data has loaded. Default value is `YES`.
@property (nonatomic, assign) BOOL automaticallyStartAnimationOnLoad;

/// A Boolean value indicating whether an active animation should reload and restart when the visible map region changes. Default value is `YES`.
@property (nonatomic, assign) BOOL shouldRestartAnimationOnRegionChange;

//-----------------------------------------------------------------------------
// @name Long Press Gesture
//-----------------------------------------------------------------------------

/**
 A Boolean value that indicates whether the weather map should show the animated circle during a long press gesture on the map.
 */
@property (nonatomic, assign) BOOL showsAnnotationDuringLongPress;

/**
 A Boolean value that indicates whether the weather map should show an annotation on the map at the location of a long press gesture.
 */
@property (nonatomic, assign) BOOL showsAnnotationForLongPress;

/**
 The annotation style to use for the long press gesture when enabled.
 */
@property (nonatomic, strong, nullable) AWFAnnotationStyle *longPressAnnotationStyle;

//-----------------------------------------------------------------------------
// @name Mapbox Configuration
//-----------------------------------------------------------------------------

/**
 The Mapbox layer identifier under which Aeris tile overlays will be inserted. If this value is `nil`, then Aeris layers will be added at the
 top of the layer stack.
 
 Refer to the Mapbox GL SDK for iOS documentation for additional information.
 */
@property (nonatomic, copy, nullable) NSString *mapboxOverlayInsertionLayerIdentifier;

/**
 Mapbox URL of the map style to display.
 
 Refer to the Mapbox GL SDK for iOS documentation for additional information.
 */
@property (nonatomic, strong, nullable) NSURL *mapboxStyleUrl;

@end

NS_ASSUME_NONNULL_END
