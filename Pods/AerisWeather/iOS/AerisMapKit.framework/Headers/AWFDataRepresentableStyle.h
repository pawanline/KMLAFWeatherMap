//
//  AWFCombinedRepresentableStyle.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 9/5/18.
//  Copyright © 2018 AerisWeather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AerisMapKit/AWFMapItemStyle.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFDataRepresentableStyle;

/**
 The `AWFDataRepresentableStyleProvider` protocol is adopted by an object that provides the style specifications for multiple map representable types.
 */
@protocol AWFDataRepresentableStyleProvider <NSObject>

/**
 The combined style specification provider.
 */
@property (nonatomic, strong) AWFDataRepresentableStyle *styleProvider;

@end

/**
 `AWFDataRepresentableStyle` is responsible for managing multiple instances of `AWFMapItemStyle` that are associated with various map representable
 types associated with a combined overlay.
 */
@interface AWFDataRepresentableStyle : NSObject <AWFStyleProvider>

/**
 The style specification for map annotations.
 */
@property (nonatomic, strong) AWFMapItemStyle *annotations;

/**
 The style specification for map overlays.
 */
@property (nonatomic, strong) AWFMapItemStyle *overlays;

/**
 The style specification for map polygons.
 */
@property (nonatomic, strong) AWFMapItemStyle *polygons;

/**
 The style specification for map polylines.
 */
@property (nonatomic, strong) AWFMapItemStyle *polylines;

@end

NS_ASSUME_NONNULL_END
