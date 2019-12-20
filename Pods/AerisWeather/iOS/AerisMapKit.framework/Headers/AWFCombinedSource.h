//
//  AWFCombinedSource.h
//  AerisMap
//
//  Created by Nicholas Shipes on 8/14/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisMapKit/AWFPointSource.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFDataRepresentableStyle;

/**
 An `AWFCombinedSource` object represents a data source that manages a combination of different overlays on a map. Specifically, this layer type
 manages annotations, overlays, polygons and polylines needed to display a specific data layer.
 */
@interface AWFCombinedSource : AWFPointSource

/**
 The overlays being managed by the source (readonly).
 */
@property (readonly, nonatomic, strong, nullable) NSArray *overlays;

/**
 The polygons being managed by the source (readonly).
 */
@property (readonly, nonatomic, strong, nullable) NSArray<NSObject<AWFPolygon> *> *polygons;

/**
 The polylines being managed by the source (readonly).
 */
@property (readonly, nonatomic, strong, nullable) NSArray<NSObject<AWFPolyline> *> *polylines;

/**
 The style to apply to the source's overlays.
 */
@property (nonatomic, strong, nullable) id overlayStyle;

@property (nonatomic, strong, nullable) AWFDataRepresentableStyle *styleProvider;

/**
 An array of animations associated with the content source. For combined sources, each map data representable type will have its own animation instance for
 managing the rendering of data for that map representable type.
 */
@property (nonatomic, strong, nullable) NSArray<AWFAnimation *> *animations;

/**
 Determines whether the map source should show annotations during an animation, which is `YES` by default.
 */
@property (nonatomic, assign) BOOL showAnnotationsDuringAnimation;

/**
 Determines whether the map source should show overlays during an animation, which is `NO` by default.
 */
@property (nonatomic, assign) BOOL showOverlaysDuringAnimation;

/**
 Determines whether the map source should show polygons during an animation, which is `NO` by default.
 */
@property (nonatomic, assign) BOOL showPolygonsDuringAnimation;

/**
 Determines whether the map source should show polylines during an animation, which is `NO` by default.
 */
@property (nonatomic, assign) BOOL showPolylinesDuringAnimation;

/**
 Returns a single overlay representing a set of objects on the map based on a specific group identifier.
 
 @param identifier The group identifier to return an overlay for.
 @return Returns a single map overlay object, which varies depending on the map strategy being used.
 */
- (nullable NSArray *)overlayForIdentifier:(NSString *)identifier;

/**
 Returns an array of polygons representing a set of objects on the map based on a specific group identifier.
 
 @param identifier The group identifier to return polygons for.
 @return Returns an array of map polygon objects, which varies depending on the map strategy being used.
 */
- (nullable NSArray<NSObject<AWFPolygon> *> *)polygonsForIdentifier:(NSString *)identifier;

/**
 Returns an array of polylines representing a set of objects on the map based on a specific group identifier.
 
 @param identifier The group identifier to return polylines for.
 @return Returns an array of map polyline objects, which varies depending on the map strategy being used.
 */
- (nullable NSArray<NSObject<AWFPolyline> *> *)polylinesForIdentifier:(NSString *)identifier;

@end

NS_ASSUME_NONNULL_END
