//
//  AWFTropicalCycloneAnnotationStyle.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 8/9/18.
//  Copyright © 2018 AerisWeather, LLC. All rights reserved.
//

#import <AerisMapKit/AerisMapKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString *AWFTropicalCycloneAnnotationType NS_TYPED_EXTENSIBLE_ENUM;
FOUNDATION_EXPORT AWFTropicalCycloneAnnotationType const AWFTropicalCycloneAnnotationTypeLow;
FOUNDATION_EXPORT AWFTropicalCycloneAnnotationType const AWFTropicalCycloneAnnotationTypeDepression;
FOUNDATION_EXPORT AWFTropicalCycloneAnnotationType const AWFTropicalCycloneAnnotationTypeStorm;
FOUNDATION_EXPORT AWFTropicalCycloneAnnotationType const AWFTropicalCycloneAnnotationTypeCat1;
FOUNDATION_EXPORT AWFTropicalCycloneAnnotationType const AWFTropicalCycloneAnnotationTypeCat2;
FOUNDATION_EXPORT AWFTropicalCycloneAnnotationType const AWFTropicalCycloneAnnotationTypeCat3;
FOUNDATION_EXPORT AWFTropicalCycloneAnnotationType const AWFTropicalCycloneAnnotationTypeCat4;
FOUNDATION_EXPORT AWFTropicalCycloneAnnotationType const AWFTropicalCycloneAnnotationTypeCat5;
FOUNDATION_EXPORT AWFTropicalCycloneAnnotationType const AWFTropicalCycloneAnnotationTypeTyphoon;
FOUNDATION_EXPORT AWFTropicalCycloneAnnotationType const AWFTropicalCycloneAnnotationTypeSuperTyphoon;

@interface AWFTropicalCycloneAnnotationStyle : AWFAnnotationStyle <AWFGroupedStyle, AWFDataRepresentableStyleProvider>

/**
 The style specifications for multiple map representable types.
 */
@property (nonatomic, strong) AWFDataRepresentableStyle *styleProvider;

@end

NS_ASSUME_NONNULL_END
