//
//  AWFDataRepresentable.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 8/16/18.
//  Copyright © 2018 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AerisWeatherKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, AWFDataRepresentableType) {
	AWFDataRepresentableTypeOverlay = 0,
	AWFDataRepresentableTypeAnnotation,
	AWFDataRepresentableTypePolygon,
	AWFDataRepresentableTypePolyline
};

@protocol AWFDataRepresentable <NSObject>

/**
 The weather model object associated with the representable object, which is used for styling, animating and callout information.
 */
@property (readonly, nonatomic, strong, nullable) AWFWeatherObject *modelObject;

@end

NS_ASSUME_NONNULL_END
