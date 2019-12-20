//
//  AWFTropicalBreakpointPolygonStyle.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 8/22/18.
//  Copyright © 2018 AerisWeather, LLC. All rights reserved.
//

#import <AerisMapKit/AWFPolygonStyle.h>
#import <AerisMapKit/AWFGroupedStyle.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString *AWFTropicalBreakpointPolygonType NS_TYPED_EXTENSIBLE_ENUM;
FOUNDATION_EXPORT AWFTropicalBreakpointPolygonType const AWFTropicalBreakpointPolygonTypeTropicalStormWatch;
FOUNDATION_EXPORT AWFTropicalBreakpointPolygonType const AWFTropicalBreakpointPolygonTypeTropicalStormWarning;
FOUNDATION_EXPORT AWFTropicalBreakpointPolygonType const AWFTropicalBreakpointPolygonTypeHurricaneWatch;
FOUNDATION_EXPORT AWFTropicalBreakpointPolygonType const AWFTropicalBreakpointPolygonTypeHurricaneWarning;

/**
 An `AWFTropicalBreakpointPolygonStyle` object provides the style specifications to be used for tropical breakpoint polylines representation on a map.
 */

@interface AWFTropicalBreakpointPolygonStyle : AWFPolygonStyle <AWFGroupedStyle>

@end

NS_ASSUME_NONNULL_END
