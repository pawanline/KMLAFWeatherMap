//
//  AWFWeatherMapViewController.h
//  AerisMap
//
//  Created by Nicholas Shipes on 5/6/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisMapKit/AWFWeatherMap.h>
#import <AerisMapKit/AWFTimelineView.h>
#import <AerisMapKit/AWFMapOptionsViewController.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFWeatherMapConfig, AWFTimelineView, AWFBasicControlView, AWFLegendView;

/**
 An `AWFWeatherMapViewController` provides a easy way to display a fully-functional weather map that automatically sets up the necessary map view and control 
 views associated with a weather map.
 */
@interface AWFWeatherMapViewController : UIViewController <AWFWeatherMapDelegate, AWFWeatherMapDataSource, AWFTimelineViewDelegate, AWFMapOptionsViewControllerDelegate>

/**
 The base map type to use for the weather map.
 */
@property (nonatomic, assign) AWFWeatherMapType weatherMapType;

/**
 The configuration for the weather map.
 */
@property (nonatomic, strong) AWFWeatherMapConfig *config;

/**
 The weather map that is displayed.
 */
@property (readonly, nonatomic, strong) AWFWeatherMap *weatherMap;

/**
 The timeline view for the weather map. This view displays a timeline control allowing the user to scrub between the start and end times.
 */
@property (readonly, nonatomic, strong) AWFTimelineView *timelineView;

/**
 The basic control view for the weather map. This view displays a basic play/stop button and current date and time of the timeline.
 */
@property (readonly, nonatomic, strong) AWFBasicControlView *controlView;

/**
 The legend view for the weather map, which is dynamic based on the data layers currently visible on the map.
 */
@property (readonly, nonatomic, strong) AWFLegendView *legendView;

/**
 Whether or not the weather map should auto-refresh its active data layers at regular intervals. The default is `YES`.
 */
@property (nonatomic, assign, getter=isAutorefreshEnabled) BOOL autorefreshEnabled;

/// Options view controller associated with the map.
@property (nonatomic, strong, readonly) AWFMapOptionsViewController *optionsController;

/**
 Presents the map options view controller as a modal view.
 */
- (void)showOptions;

/**
 Controls the visibility of the legend view.

 @param show `YES` if the legend view should be shown, otherwise `NO`.
 @param animated A Boolean value indicating whether the update should be animated.
 */
- (void)showLegendView:(BOOL)show animated:(BOOL)animated;

@end

NS_ASSUME_NONNULL_END
