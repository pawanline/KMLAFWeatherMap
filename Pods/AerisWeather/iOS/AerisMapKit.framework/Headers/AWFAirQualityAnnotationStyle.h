//
//  AWFAirQualityAnnotationStyle.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 5/17/18.
//  Copyright © 2018 AerisWeather, LLC. All rights reserved.
//

#import <AerisMapKit/AerisMapKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString *AWFAirQualityAnnotationType NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFAirQualityAnnotationType const AWFAirQualityAnnotationTypeGood;
FOUNDATION_EXPORT AWFAirQualityAnnotationType const AWFAirQualityAnnotationTypeModerate;
FOUNDATION_EXPORT AWFAirQualityAnnotationType const AWFAirQualityAnnotationTypeSensitive;
FOUNDATION_EXPORT AWFAirQualityAnnotationType const AWFAirQualityAnnotationTypeUnhealthy;
FOUNDATION_EXPORT AWFAirQualityAnnotationType const AWFAirQualityAnnotationTypeVeryUnhealthy;
FOUNDATION_EXPORT AWFAirQualityAnnotationType const AWFAirQualityAnnotationTypeHazardous;

@interface AWFAirQualityAnnotationStyle : AWFAnnotationStyle <AWFGroupedStyle>

@end

NS_ASSUME_NONNULL_END
