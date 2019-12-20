//
//  AWFDataAnimation.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 8/16/18.
//  Copyright © 2018 AerisWeather, LLC. All rights reserved.
//

#import <AerisMapKit/AWFAnimation.h>
#import <AerisMapKit/AWFDataRepresentable.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFDataAnimation;

/**
 The `AWFDataAnimationDataSource` is adopted by an object that provides the necessary data for an point-based
 overlay to complete its animation.
 */
@protocol AWFDataAnimationDataSource <AWFAnimationDataSource>

/**
 Asks the data source for the data to be used for this animation. (required)

 @param animation The animation object requesting the data
 @return An array of data items to use for the animation. These instances may vary depending on subclasses and what they expect to receive
 */
- (nullable NSArray<id<AWFDataRepresentable>> *)dataObjectsForAnimation:(AWFAnimation *)animation;

/**
 Asks the data source if data needs to be requested for the animation.

 @param animation The animation requesting the data
 @return `YES` if the data source needs to load data, otherwise `NO`
 */
- (BOOL)shouldLoadDataForAnimation:(AWFAnimation *)animation;

@end

/**
 The `AWFDataAnimationDelegate` protocol defines a set of optional methods that can be used to be notified when the point data
 animation data changes.
 */
@protocol AWFDataAnimationDelegate <AWFAnimationDelegate>
@optional

/**
 Tells the delegate the animation has data objects to be added for the current position in the timeline.
 *
 Typically this is used by a `AWFWeatherMap` instance to be notified when data objects should be added to the map.
 *
 @param animation   The animation that added data objects.
 @param objects The data objects that are active for the current timeline range.
 */
- (void)animation:(AWFDataAnimation *)animation didAddDataObjects:(NSArray<id<AWFDataRepresentable>> *)objects;

/**
 Tells the delegate the animation has data objects to be removed for the current position in the timeline.
 *
 Typically this is used by a `AWFWeatherMap` instance to be notified when data objects should be removed from the map.
 *
 @param animation   The animation managing the data objects.
 @param objects The data objects that are inactive for the current timeline range.
 */
- (void)animation:(AWFDataAnimation *)animation didRemoveDataObjects:(NSArray<id<AWFDataRepresentable>> *)objects;

@end

/**
 An `AWFDataAnimation` object manages the animation of of date-specific data across a period of time.
 */
@interface AWFDataAnimation : AWFAnimation

@property (nonatomic, assign) AWFDataRepresentableType representableType;
@property (nonatomic, weak, nullable) id<AWFDataAnimationDataSource> dataSource;

/**
 The object that acts as the data source of the receiving animation.
 */
@property (nonatomic, weak, nullable) id<AWFDataAnimationDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
