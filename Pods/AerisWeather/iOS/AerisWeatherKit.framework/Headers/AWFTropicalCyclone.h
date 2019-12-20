//
//  AWFTropicalCyclone.h
//  AerisWeatherKit
//
//  Created by Nicholas Shipes on 8/9/18.
//  Copyright © 2018 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherObject.h>
#import <AerisWeatherKit/AWFGeoPolygon.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString *AWFTropicalBasin NS_TYPED_EXTENSIBLE_ENUM;
FOUNDATION_EXPORT AWFTropicalBasin const AWFTropicalBasinAtlantic;
FOUNDATION_EXPORT AWFTropicalBasin const AWFTropicalBasinEastPacific;
FOUNDATION_EXPORT AWFTropicalBasin const AWFTropicalBasinCentralPacific;
FOUNDATION_EXPORT AWFTropicalBasin const AWFTropicalBasinWestPacific;
FOUNDATION_EXPORT AWFTropicalBasin const AWFTropicalBasinIndian;
FOUNDATION_EXPORT AWFTropicalBasin const AWFTropicalBasinSouthernHemisphere;

typedef NSString *AWFTropicalStormType NS_TYPED_EXTENSIBLE_ENUM;
FOUNDATION_EXPORT AWFTropicalStormType const AWFTropicalStormTypeLow;
FOUNDATION_EXPORT AWFTropicalStormType const AWFTropicalStormTypeDepression;
FOUNDATION_EXPORT AWFTropicalStormType const AWFTropicalStormTypeStorm;
FOUNDATION_EXPORT AWFTropicalStormType const AWFTropicalStormTypeHurricane;
FOUNDATION_EXPORT AWFTropicalStormType const AWFTropicalStormTypeHurricaneCat1;
FOUNDATION_EXPORT AWFTropicalStormType const AWFTropicalStormTypeHurricaneCat2;
FOUNDATION_EXPORT AWFTropicalStormType const AWFTropicalStormTypeHurricaneCat3;
FOUNDATION_EXPORT AWFTropicalStormType const AWFTropicalStormTypeHurricaneCat4;
FOUNDATION_EXPORT AWFTropicalStormType const AWFTropicalStormTypeHurricaneCat5;
FOUNDATION_EXPORT AWFTropicalStormType const AWFTropicalStormTypeTyphoon;
FOUNDATION_EXPORT AWFTropicalStormType const AWFTropicalStormTypeSuperTyphoon;

@class AWFTropicalCycloneProfile;
@class AWFTropicalCyclonePosition;
@class AWFAdvisoryBreakpoint;
@class AWFCoordinateBounds;

/**
 An `AWFTropicalCyclone` object represents data returned by the [**tropicalcyclones** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/tropicalcyclones/)
 of the Aeris Weather API.
 */
@interface AWFTropicalCyclone : AWFWeatherObject

/**
 The tropical system identifier. The system identifier will be in the format `:year-:basin-:event`, e.g. `2017-AL-16`.
 */
@property (nonatomic, copy) NSString *systemId;

/**
 The tropical system profile, such as name, basin and lifespan statistics.
 */
@property (nonatomic, strong) AWFTropicalCycloneProfile *profile;

/**
 The latest storm position information when the tropical system is active, otherwise `nil`.
 */
@property (nonatomic, strong, nullable) AWFTropicalCyclonePosition *position;

/**
 An array containing the historical track information for the tropical system.
 */
@property (nonatomic, strong, nullable) NSArray<AWFTropicalCyclonePosition *> *track;

/**
 An array containing the forecast track information when the system is active and a forecast is available.
 */
@property (nonatomic, strong, nullable) NSArray<AWFTropicalCyclonePosition *> *forecast;

/**
 Array of coordinates (latitude, longitude) defining a cone of error along the forecast path which can be used
 to better determine locations along the forecast path of the system.
 */
@property (nonatomic, strong, nullable) NSArray<AWFGeoPolygonCoordValue> *forecastErrorCone;

/**
 An array of NHC-issued watches and warnings along coastlines for active systems, or `nil` if not available. Only available for the Atlantic and East
 Pacific tropical basins.
 */
@property (nonatomic, strong) NSArray<AWFAdvisoryBreakpoint *> *advisoryBreakpoints;

/**
 Current time zone for the cyclone. If the system is active, the time zone value will be that of its current position, otherwise the time zone of the system's
 first position will be used.
 */
@property (nonatomic, strong) NSTimeZone *timeZone;

@end


/**
 An `AWFTropicalCycloneProfile` object contains general profile information for a tropical cyclone.
 */
@interface AWFTropicalCycloneProfile : AWFWeatherObject

@property (nonatomic, weak) AWFTropicalCyclone *cyclone;

/**
 System name without the storm type prefix.
 */
@property (nonatomic, copy) NSString *name;

/**
 The tropical season year during which the system originated.
 */
@property (nonatomic, assign) NSUInteger year;

/**
 The basin in which the system originated.
 */
@property (nonatomic, copy) AWFTropicalBasin basinOrigin;

/**
 The basin in which the system is currently located if the system is currently active, otherwise `nil`.
 */
@property (nonatomic, copy, nullable) AWFTropicalBasin basinCurrent;

/**
 An array of basins that the system has existed within during its lifetime. Typically this will contain a single basin except for systems in the Pacific Ocean
 that may traverse multiple basins.
 */
@property (nonatomic, strong) NSArray<AWFTropicalBasin> *basins;

/**
 Event number of the system for the basin of origin.
 */
@property (nonatomic, assign) NSUInteger event;

/**
 Whether or not the system is currently active.
 */
@property (nonatomic, assign) BOOL isActive;

/**
 Date of the first advisory issued for the system by the NHC or JTWC.
 */
@property (nonatomic, strong) NSDate *lifespanStart;

/**
 Date of the last advisory issued for the system by the NHC or JTWC.
 */
@property (nonatomic, strong) NSDate *lifespanEnd;

/**
 Maximum type of storm based on wind speed during its lifetime.
 */
@property (nonatomic, copy) AWFTropicalStormType maxStormType;

/**
 Maximum strength category the system achieved during its lifetime.
 */
@property (nonatomic, copy) AWFTropicalStormType maxStormCategory;

/**
 Maximum reported wind speed of the system during its lifetime in knots.
 */
@property (nonatomic, assign) CGFloat maxWindSpeedKTS;

/**
 Maximum reported wind speed of the system during its lifetime in kilometers per hour when available.
 */
@property (nonatomic, assign) CGFloat maxWindSpeedKMH;

/**
 Maximum reported wind speed of the system during its lifetime in miles per hour when available.
 */
@property (nonatomic, assign) CGFloat maxWindSpeedMPH;

/**
 Date/time when the maximum wind speed was reported when available.
 */
@property (nonatomic, strong, nullable) NSDate *maxWindSpeedDate;

/**
 Minimum reported surface pressure of the system during its lifetime in millibars when available.
 */
@property (nonatomic, assign) CGFloat minPressureMB;

/**
 Minimum reported surface pressure of the system during its lifetime in inches of mercury when available.
 */
@property (nonatomic, assign) CGFloat minPressureIN;

/**
 Date/time when the minimum surface pressure was reported when available.
 */
@property (nonatomic, strong, nullable) NSDate *minPressureDate;

/**
 The bounding box that encloses the system's historical track and forecast components when the system is active.
 */
@property (nonatomic, strong, nullable) AWFCoordinateBounds *bounds;

/**
 Current time zone for the cyclone. If the system is active, the time zone value will be that of its current position, otherwise the time zone of the system's
 first position will be used.
 */
@property (nonatomic, strong, nullable) NSTimeZone *timeZone;

@end


/**
 An `AWFTropicalCyclonePosition` object contains information about a tropical cyclone at a specific observation or forecast based on a single tropical advisory.
 */
@interface AWFTropicalCyclonePosition : AWFWeatherObject

@property (nonatomic, weak) AWFTropicalCyclone *cyclone;

/**
 Advisory number identifier the position information is based on.
 */
@property (nonatomic, copy) NSString *advisoryId;


/**
 Returns whether the position is the system's current/latest position (only when active).
 */
@property (nonatomic, assign) BOOL isCurrent;

/**
 Returns whether the position is part of the tropical cyclone forecast track.
 */
@property (nonatomic, assign) BOOL isForecast;

/**
 Location coordinate of the position.
 */
@property (nonatomic, assign) CLLocationCoordinate2D coordinate;

/**
 The storm type at this position.
 */
@property (nonatomic, copy) AWFTropicalStormType stormType;

/**
 The storm category at this position.
 */
@property (nonatomic, copy) AWFTropicalStormType category;

/**
 Full name of the system at the time of the advisory, including the storm type prefix.
 */
@property (nonatomic, copy) NSString *name;

/**
 System name without the storm type prefix.
 */
@property (nonatomic, copy) NSString *shortName;

/**
 Basin the system is located within.
 */
@property (nonatomic, copy) AWFTropicalBasin basin;

/**
 Direction the system is moving at the time of the advisory in degrees.
 */
@property (nonatomic, assign) CGFloat movingDirection;

/**
 Direction the system is moving at the time of the advisory as a Cardinal coordinate value.
 */
@property (nonatomic, copy) NSString *movingDirectionENG;

/**
 Speed the system is moving at the time of the advisory in knots.
 */
@property (nonatomic, assign) CGFloat movingSpeedKTS;

/**
 Speed the system is moving at the time of the advisory in kilometers per hour.
 */
@property (nonatomic, assign) CGFloat movingSpeedKMH;

/**
 Speed the system is moving at the time of the advisory in miles per hour.
 */
@property (nonatomic, assign) CGFloat movingSpeedMPH;

/**
 Maximum sustained wind speed reported at the time of the advisory in knots.
 */
@property (nonatomic, assign) CGFloat windSpeedKTS;

/**
 Maximum sustained wind speed reported at the time of the advisory in kilometers per hour.
 */
@property (nonatomic, assign) CGFloat windSpeedKMH;

/**
 Maximum sustained wind speed reported at the time of the advisory in miles per hour.
 */
@property (nonatomic, assign) CGFloat windSpeedMPH;

/**
 Maximum wind gust speed reported at the time of the advisory in knots.
 */
@property (nonatomic, assign) CGFloat windGustKTS;

/**
 Maximum wind gust speed reported at the time of the advisory in kilometers per hour.
 */
@property (nonatomic, assign) CGFloat windGustKMH;

/**
 Maximum wind gust speed reported at the time of the advisory in miles per hour.
 */
@property (nonatomic, assign) CGFloat windGustMPH;

/**
 Minimum surface pressure reported at the time of the advisory in millibars.
 */
@property (nonatomic, assign) CGFloat pressureMB;

/**
 Minimum surface pressure reported at the time of the advisory in inches of mercury.
 */
@property (nonatomic, assign) CGFloat pressureIN;

/**
 Date/time of the advisory for this position as issued by the NHC or JTWC.
 */
@property (nonatomic, strong, nullable) NSDate *timestamp;

/**
 Time zone for the position. If the system is active, the time zone value will be that of its current position, otherwise the time zone of the system's
 first position will be used.
 */
@property (nonatomic, strong, nullable) NSTimeZone *timeZone;

@end

NS_ASSUME_NONNULL_END
