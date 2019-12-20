//
//  AWFAirQuality.h
//  AerisWeatherKit
//
//  Created by Nicholas Shipes on 5/17/18.
//  Copyright © 2018 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherEndpoint.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString * AWFAirQualityFilter NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT AWFAirQualityFilter const AWFAirQualityFilterChina;
FOUNDATION_EXPORT AWFAirQualityFilter const AWFAirQualityFilterIndia;
FOUNDATION_EXPORT AWFAirQualityFilter const AWFAirQualityFilterPM2P5;
FOUNDATION_EXPORT AWFAirQualityFilter const AWFAirQualityFilterPM10;
FOUNDATION_EXPORT AWFAirQualityFilter const AWFAirQualityFilterNO2;
FOUNDATION_EXPORT AWFAirQualityFilter const AWFAirQualityFilterCO;
FOUNDATION_EXPORT AWFAirQualityFilter const AWFAirQualityFilterSO2;
FOUNDATION_EXPORT AWFAirQualityFilter const AWFAirQualityFilterO3;

/**
 `AWFAirQuality` provides convenience methods for interacting with the
 [`airquality` endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/airquality) of the Aeris API. All requests will
 return instances of `AWFAirQualityReport` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFAirQuality : AWFWeatherEndpoint
@end

/**
 `AWFAirQualityForecasts` provides convenience methods for interacting with the
 [`airquality/forecasts` endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/airquality/forecasts) of the Aeris API. All requests will
 return instances of `AWFAirQualityReport` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFAirQualityForecasts : AWFWeatherEndpoint
@end

NS_ASSUME_NONNULL_END

