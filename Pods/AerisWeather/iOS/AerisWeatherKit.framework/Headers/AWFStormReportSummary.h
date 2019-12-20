//
//  AWFStormReportSummary.h
//  Aeris
//
//  Created by Nicholas Shipes on 11/3/15.
//  Copyright © 2015 Aeris Weather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherObject.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFStormReportSummaryType;
@class AWFGeoPolygon;
@class AWFRangeSummary;

/**
 An `AWFStormReportSummary` object represents data returned by the [**stormreports/summary** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/stormreports-summary/)
 of the Aeris Weather API.
 */
@interface AWFStormReportSummary : AWFWeatherObject

/**
 Starting date and time for the period.
 */
@property (nonatomic, strong, nullable) NSDate *rangeStartDate;

/**
 Ending date and time for the period.
 */
@property (nonatomic, strong, nullable) NSDate *rangeEndDate;

/**
 Total number of storm reports for the period.
 */
@property (nonatomic, assign) NSInteger totalReports;

/**
 Array of states that have one or more storm reports for the period as abbreviations.
 */
@property (nonatomic, strong, nullable) NSArray<NSString *> *states;

/**
 An array of `AWFGeoPolygon` instances that define the groups of reports used within the summary.
 
 In order to return polygons with your request, you must also include the `geo` filter with your request options. If this filter is not included and/or
 there are no report groups, then this value will be `nil`.
 */
@property (nonatomic, strong, nullable) NSArray<AWFGeoPolygon *> *polygons;

/**
 Array of storm report summary types according to their report code/type.
 */
@property (nonatomic, strong, nullable) NSArray<AWFStormReportSummaryType *> *types;

@end


/**
 An `AWFStormReportSummaryType` object contains summary information for a single storm report type.
 */
@interface AWFStormReportSummaryType : AWFWeatherObject

/**
 Starting date and time for the period.
 */
@property (nonatomic, strong, nullable) NSDate *rangeStartDate;

/**
 Ending date and time for the period.
 */
@property (nonatomic, strong, nullable) NSDate *rangeEndDate;

/**
 Total number of storm reports for the period.
 */
@property (nonatomic, assign) NSInteger totalReports;

/**
 Array of states that have one or more storm reports for the period as abbreviations.
 */
@property (nonatomic, strong, nullable) NSArray<NSString *> *states;

/**
 Report code as assigned by the National Weather Service (NWS).
 */
@property (nonatomic, copy, nullable) NSString *code;

/**
 For wind-related events, the value range for all reports in knots.
 */
@property (nonatomic, strong, nullable) AWFRangeSummary *valueKTS;

/**
 For wind-related events, the value range for all reports in miles per hour.
 */
@property (nonatomic, strong, nullable) AWFRangeSummary *valueMPH;

/**
 For wind-related events, the value range for all reports in kilometers per hour.
 */
@property (nonatomic, strong, nullable) AWFRangeSummary *valueKMH;

/**
 For rain/flooding-related events, the value range observed for all reports in millimeters.
 */
@property (nonatomic, strong, nullable) AWFRangeSummary *valueMM;

/**
 For snow or sleet-related events, the value range observed for all reports in centimeters.
 */
@property (nonatomic, strong, nullable) AWFRangeSummary *valueCM;

/**
 For rain/flood, snow or sleet-related events, the value range observed for all reports in inches.
 */
@property (nonatomic, strong, nullable) AWFRangeSummary *valueIN;

@end

NS_ASSUME_NONNULL_END
