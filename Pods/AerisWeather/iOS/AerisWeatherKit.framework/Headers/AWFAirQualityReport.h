//
//  AWFAirQualityReport.h
//  AerisWeatherKit
//
//  Created by Nicholas Shipes on 5/17/18.
//  Copyright © 2018 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFGeographicObject.h>

@class AWFAirQualityPeriod;
@class AWFAirPollutant;
@class AWFAirQualitySource;

NS_ASSUME_NONNULL_BEGIN

/**
 An `AWFAirQualityReport` object represents data returned by the [**airquality** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/airquality/)
 of the Aeris Weather API.
 */
@interface AWFAirQualityReport : AWFGeographicObject

/**
 The station id the report is for. This value will be `nil` if the requested place is not a specific station identifer.
 */
@property (nonatomic, copy, nullable) NSString *stationId;

/**
 An array of air quality report periods returned for this item.
 */
@property (nonatomic, strong, nullable) NSArray<AWFAirQualityPeriod *> *periods;

/**
 An array of data sources used for air quality information at this location.
 */
@property (nonatomic, strong, nullable) NSArray<AWFAirQualitySource *> *sources;

/**
 An array of observation station ids used to provide the air quality information.
 */
@property (nonatomic, strong, nullable) NSArray<NSString *> *stations;

@end

/**
 An `AWFAirQualityPeriod` object represents data for a single period returned by the [**airquality** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/airquality/)
 of the Aeris Weather API.
 */
@interface AWFAirQualityPeriod : AWFWeatherObject

/**
 GMT date for the period.
 */
@property (nonatomic, strong, nullable) NSDate *timestamp;

/**
 Local timezone for the forecast period.
 */
@property (nonatomic, strong, nullable) NSTimeZone *timeZone;

/**
 The air quality category based on the AQI value.
 
 This value depends on the data method used to calculate the AQI value. The default AQI method is based on the categories from [AirNow](https://airnow.gov/index.cfm?action=aqibasics.aqi).
 
 `china` - https://en.wikipedia.org/wiki/Air_quality_index
 `india` - https://en.wikipedia.org/wiki/Air_quality_index
 */
@property (nonatomic, copy, nullable) NSString *category;

/**
 The six-digit hexadecimal color code for the air quality category.
 */
@property (nonatomic, copy, nullable) NSString *color;

/**
 The standardized Air Quality Index value from `0` to `500`.
 */
@property (nonatomic, assign) CGFloat aqi;

/**
 The dominant pollutant type.
 */
@property (nonatomic, copy, nullable) NSString *dominant;

/**
 An array of pollutants and their levels.
 */
@property (nonatomic, strong, nullable) NSArray<AWFAirPollutant *> *pollutants;

@end


/**
 An `AWFAirPollutant` object represents a single air pollutant and its observed or forecast measurement.
 */
@interface AWFAirPollutant : AWFWeatherObject

/**
 Name of the pollutant.
 */
@property (nonatomic, copy, nullable) NSString *name;

/**
 Air quality category based on the AQI value.
 
 This value depends on the data method used to calculate the AQI value. The default AQI method is based on the categories from [AirNow](https://airnow.gov/index.cfm?action=aqibasics.aqi).
 
 `china` - https://en.wikipedia.org/wiki/Air_quality_index
 `india` - https://en.wikipedia.org/wiki/Air_quality_index
 */
@property (nonatomic, copy, nullable) NSString *category;

/**
 Abbreviated type code of the pollutant.
 
 Possible values:
 - `co`: carbon monoxide
 - `no2` : nitrogen dioxide
 - `o3`: ozone
 - `pm1`: partical matter (< 1µm)
 - `pm10`: partical matter (< 10µm)
 - `pm2.5`: partical matter (< 2.5µm)
 - `so2`: sulfer dioxide
 */
@property (nonatomic, copy, nullable) NSString *type;

/**
 Six-digit hexadecimal color code for the air quality category.
 */
@property (nonatomic, copy, nullable) NSString *color;

/**
 Pollutant measurement converted to a standardized Air Quality Index value from `0` to `500`.
 */
@property (nonatomic, assign) CGFloat aqi;

/**
 Pollutant measurement in parts per billion.
 */
@property (nonatomic, assign) CGFloat valuePPB;

/**
 Pollutant measurement in parts per micrograms per cubic meter.
 */
@property (nonatomic, assign) CGFloat valueUGM3;

@end


/**
 An `AWFAirQualitySource` represents an air quality data source used for a station.
 */
@interface AWFAirQualitySource : AWFWeatherObject

/**
 The name of the data source.
 */
@property (nonatomic, copy, nullable) NSString *name;

@end

NS_ASSUME_NONNULL_END
