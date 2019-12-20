//
//  AWFOverlayMetadata.h
//  AerisMap
//
//  Created by Nicholas Shipes on 10/17/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AerisMapKit/AWFMapLayer.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An `AWFOverlayMetadata` object loads and stores additional information about an overlay, specifically a tile or 
 image overlay. This information consists of timestamps, dates and intervals that are available from the data source to
 use when displaying the overlay on a map.
 */
@interface AWFOverlayMetadata : NSObject

/**
 The layer type associated with the metadata.
 */
@property (nonatomic) AWFMapLayer layerType;

/**
 The array of available timestamps returned from the data source.
 */
@property (nonatomic, readonly, nullable) NSArray<NSNumber *> *times;

/**
 The array of available dates returned from the data source.
 */
@property (nonatomic, readonly, nullable) NSArray<NSDate *> *dates;

/**
 The array of available offset intervals returned from the data source.
 */
@property (nonatomic, readonly, nullable) NSArray<NSNumber *> *timeIntervals;

/**
 Initializes and returns a metadata object associated with the specified layer type.
 
 @param layerType The `AWFLayerType` associated with the metadata.
 @return The initialized metadata object.
 */
- (id)initWithLayerType:(AWFMapLayer)layerType;

/**
 Requests and stores the latest metadata from the data source for the associated layer type.
 
 @param success The completion block to call when the metadata has been returned from the data source.
 @param failure The completion block to call when an error occurred while requesting the data.
 */
- (void)getMetadataWithSuccess:(void (^)(NSArray<NSNumber *> * _Nullable times, NSArray<NSDate *> * _Nullable dates))success failure:(void (^)(NSError * _Nullable error))failure;

/**
 Returns the most recent date available in the metadata.
 */
- (nullable NSDate *)latestDate;

/**
 Returns the time string associated with the most recent date available in the metadata.
 */
- (nullable NSString *)latestTimeString;

/**
 Determines the closest available date in the metadata relative to the specified date.
 
 @param date The date to get the closest date for.
 @return The closest available date.
 */
- (nullable NSDate *)dateClosestToDate:(NSDate *)date;

/**
 Determines the closest available timestamp string in the metadata relative to the specified date.
 
 @param date The date to get the closest timestamp string for.
 @return The closest available timestamp string.
 */
- (nullable NSString *)timeStringClosestToDate:(NSDate *)date;

/**
 Returns the timestamp string for the specified offset interval.
 
 @param interval The offset interval to return the timestamp string for.
 */
- (nullable NSString *)timeStringForInterval:(NSInteger)interval;

@end

NS_ASSUME_NONNULL_END
