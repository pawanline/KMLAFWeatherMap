//
//  AWFObservationSummary.h
//  Aeris
//
//  Created by Nicholas Shipes on 8/20/14.
//  Copyright (c) 2014 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFGeographicObject.h>
#import <AerisWeatherKit/AWFObservation.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFObservationSummaryPeriod;
@class AWFRangeSummary;

/**
 An `AWFObservationSummary` object represents data returned by the [**observations/summary** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/observations-summary/)
 of the Aeris Weather API.
 */
@interface AWFObservationSummary : AWFGeographicObject

/**
 Station identifier for this location, usually an ICAO.
 */
@property (nonatomic, copy, nullable) NSString *stationId;

/**
 Array of `AWFObservationSummaryPeriod` instances.
 */
@property (nonatomic, strong, nullable) NSArray<AWFObservationSummaryPeriod *> *periods;

@end


/**
 An `AWFObservationSummaryPeriod` object represents data for a single period returned by the [**observations/summary** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/observations-summary/)
 of the Aeris Weather API.
 */
@interface AWFObservationSummaryPeriod : AWFWeatherObject

/**
 GMT date for the period.
 */
@property (nonatomic, strong, nullable) NSDate *timestamp;

/**
 Local timezone for the forecast period.
 */
@property (nonatomic, strong, nullable) NSTimeZone *timeZone;

/**
 Starting date and time for the period.
 */
@property (nonatomic, strong, nullable) NSDate *rangeStartDate;

/**
 Ending date and time for the period.
 */
@property (nonatomic, strong, nullable) NSDate *rangeEndDate;

//-----------------------------------------------------------------------------
// @name Weather & Clouds
//-----------------------------------------------------------------------------

/**
 Primary observed weather phrase for the period.
 */
@property (nonatomic, copy, nullable) NSString *weather;

/**
 Coded weather for the primary weather observed during the period.
 */
@property (nonatomic, copy, nullable) NSString *weatherCoded;

/**
 Full observed weather phrase for the period.
 */
@property (nonatomic, copy, nullable) NSString *weatherFull;

/**
 Full set of weather codes for the observed weather during the period.
 */
@property (nonatomic, strong, nullable) NSArray<AWFObservationWeatherCodedItem> *weatherFullCoded;

/**
 Total number of weather records for the period. If no weather other than sky conditions was reported, this value will be zero.
 */
@property (nonatomic, assign) NSInteger weatherCount;

/**
 Array of unique cloud codes that were observed during the period.
 */
@property (nonatomic, strong, nullable) NSArray<NSString *> *cloudsCoded;

/**
 Weather icon representing the observed weather from the default icon set.
 */
@property (nonatomic, copy, nullable) NSString *icon;

/**
 Sky coverage range for the period as a percentage.
 */
@property (nonatomic, strong) AWFRangeSummary *skyCoverPercentage;

//-----------------------------------------------------------------------------
// @name Temperatures
//-----------------------------------------------------------------------------

/**
 Temperature range observed during the period in degrees Celsius.
 */
@property (nonatomic, strong) AWFRangeSummary *tempC;

/**
 Temperature range observed during the period in degrees Fahrenheit.
 */
@property (nonatomic, strong) AWFRangeSummary *tempF;

/**
 Dew point range for the period in degrees Celsius.
 */
@property (nonatomic, strong) AWFRangeSummary *dewpointC;

/**
 Dew point range for the period in degrees Fahrenheit.
 */
@property (nonatomic, strong) AWFRangeSummary *dewpointF;

/**
 Humidity range for the period as a percentage.
 */
@property (nonatomic, strong) AWFRangeSummary *humidity;

//-----------------------------------------------------------------------------
// @name Precipitation
//-----------------------------------------------------------------------------

/**
 Total precipitation observed for the period in inches.
 */
@property (nonatomic, assign) CGFloat precipIN;

/**
 Total precipitation observed for the period in millimeters.
 */
@property (nonatomic, assign) CGFloat precipMM;

/**
 Total number of preciptiation records for the period.
 */
@property (nonatomic, assign) NSInteger precipCount;

//-----------------------------------------------------------------------------
// @name Winds
//-----------------------------------------------------------------------------

/**
 Wind speed range for the period in knots.
 */
@property (nonatomic, strong) AWFRangeSummary *windSpeedKTS;

/**
 Wind speed range for the period in miles per hour.
 */
@property (nonatomic, strong) AWFRangeSummary *windSpeedMPH;

/**
 Wind speed range for the period in kilometers per hour.
 */
@property (nonatomic, strong) AWFRangeSummary *windSpeedKMH;

/**
 Maximum wind gust observed during the period in knots.
 */
@property (nonatomic, assign) CGFloat windGustKTS;

/**
 Maximum wind gust observed during the period in miles per hour.
 */
@property (nonatomic, assign) CGFloat windGustMPH;

/**
 Maximum wind gust observed during the period in kilometers per hour.
 */
@property (nonatomic, assign) CGFloat windGustKMH;

//-----------------------------------------------------------------------------
// @name Barometric Pressure
//-----------------------------------------------------------------------------

/**
 Barometric pressure range for the period in millibars.
 */
@property (nonatomic, strong) AWFRangeSummary *pressureMB;

/**
 Barometric pressure range for the period in inches of mercury.
 */
@property (nonatomic, strong) AWFRangeSummary *pressureIN;

//-----------------------------------------------------------------------------
// @name Visibility
//-----------------------------------------------------------------------------

/**
 Surface visibility range for the period in kilometers.
 */
@property (nonatomic, strong) AWFRangeSummary *visibilityKM;

/**
 Surface visibility range for the period in miles.
 */
@property (nonatomic, strong) AWFRangeSummary *visibilityMI;

//-----------------------------------------------------------------------------
// @name Solar Radiation
//-----------------------------------------------------------------------------

/**
 Solar radiation range for the period in watts per square meter (not provided by all stations).
 */
@property (nonatomic, strong) AWFRangeSummary *solarRadiationKM2;

@end

NS_ASSUME_NONNULL_END
