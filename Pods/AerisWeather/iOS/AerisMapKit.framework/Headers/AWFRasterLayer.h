//
//  AWFMapLayer.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 7/19/17.
//  Copyright © 2017 AerisWeather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AerisMapKit/AWFMapLayer.h>

NS_ASSUME_NONNULL_BEGIN

//-----------------------------------------------------------------------------
// @name Radar/sat
//-----------------------------------------------------------------------------

/**
 Current and past preciptiation-type radar. Use `AWFMapLayerFutureRadar` for the future/forecast layer associated with this type.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerRadar;

/**
 Black and white infrared satellite. Use `AWFMapLayerFutureSatellite` for the future/forecast layer associated with this type.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerSatellite;

/**
 Geocolor satellite.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerSatelliteGeocolor;

/**
 Color-enhanced infrared satellite.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerSatelliteInfraredColor;

/**
 Color-enhanced infrared satellite for the Continental US region.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerSatelliteInfraredColorUS;

/**
 Black and white visible satellite. This layer uses a non-transparent black background.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerSatelliteVisible;

/**
 Color-enhanced water vapor satellite.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerSatelliteWaterVapor;


//-----------------------------------------------------------------------------
// @name Forecasts
//-----------------------------------------------------------------------------

/**
 Forecast surface dew points.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureDewPoints;

/**
 Forecast feels like temperature.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureFeelsLike;

/**
 Forecast surface heat index.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureHeatIndex;

/**
 Forecast surface humidity.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureHumidity;

/**
 Forecast ice accumulation.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureIce;

/**
 Forecast jet stream.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureJetStream;

/**
 Forecast precipitation.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFuturePrecip;

/**
 Forecast precipitation at 1-hour intervals.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFuturePrecip1Hour;

/**
 Forecast precipitation at 6-hour intervals.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFuturePrecip6Hour;

/**
 Forecast simulated radar.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureRadar;

/**
 Forecast road conditions based on expected precipitation.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureRoadConditions;

/**
 Forecast road condition index based on expected precipitation.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureRoadConditionsIndex;

/**
 Forecast midterm road condition index based on expected precipitation.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureRoadConditionsIndexMidterm;

/**
 Forecast midterm road conditions based on expected precipitation.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureRoadConditionsMidterm;

/**
 Forecast simulated satellite and cloud cover.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureSatellite;

/**
 Forecast snowfall accumulation.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureSnow;

/**
 Forecast snowfall accumulation using the 10:1 method.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureSnow10To1;

/**
 Forecast snowfall at 1-hour intervals.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureSnow1Hour;

/**
 Forecast snowfall at 1-hour intervals using the 10:1 method.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureSnow1Hour10To1;

/**
 Forecast snowfall at 1-hour intervals using the Kuchera method.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureSnow1HourKuchera;

/**
 Forecast ground snow depth.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureSnowDepth;

/**
 Forecast snowfall accumulation using the Kuchera method.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureSnowKuchera;

/**
 Forecast frontal and high/low pressure positions.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureSurfaceAnalysis;

/**
 Forecast frontal positions.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureSurfaceAnalysisFronts;

/**
 Forecast high/low pressure positions.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureSurfaceAnalysisPressure;

/**
 Mean sea level surface pressure.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureSurfacePressure;

/**
 Mean sea level surface pressure as isobars.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureSurfacePressureIsobars;

/**
 Forecast surface temperatures.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureTemperatures;

/**
 Forecast surface high temperatures.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureTemperaturesMax;

/**
 Forecast surface low temperatures.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureTemperaturesMin;

/**
 Forecast surface visibility.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureVisibility;

/**
 Forecast surface wind chill.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureWindChill;

/**
 Forecast surface wind gusts.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureWindGusts;

/**
 Forecast surface wind speeds.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFutureWindSpeeds;


//-----------------------------------------------------------------------------
// @name Tropical
//-----------------------------------------------------------------------------

/**
 Coastal areas under cyclone watches or warnings
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerTropicalCyclonesBreakPoints;

/**
 Forecast error cone for the forecast track of an active tropical cyclone
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerTropicalCyclonesForecastErrorCones;

/**
 Forecast track of a tropical cyclone as a polyline
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerTropicalCyclonesForecastLines;

/**
 Forecast track of a tropical cyclone as icons
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerTropicalCyclonesForecastPointIcons;

/**
 Forecast track of a tropical cyclone as points
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerTropicalCyclonesForecastPoints;

/**
 Active tropical invests, which are tropical disturbances under investigation for potential development.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerTropicalCyclonesInvests;

/**
 Active tropical invest names
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerTropicalCyclonesInvestsNames;

/**
 Active tropical invest positions as icons
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerTropicalCyclonesInvestsPositionIcons;

/**
 Active tropical invest positions as points
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerTropicalCyclonesInvestsPositions;

/**
 Active tropical cyclone names
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerTropicalCyclonesNames;

/**
 Active tropical cyclone positions as icons
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerTropicalCyclonesPositionIcons;

/**
 Active tropical cyclone positions
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerTropicalCyclonesPositions;

/**
 Active tropical cyclone tracks as polylines
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerTropicalCyclonesTrackLines;

/**
 Active tropical cyclone tracks as icons
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerTropicalCyclonesTrackPointIcons;

/**
 Active tropical cyclone tracks as points
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerTropicalCyclonesTrackPoints;


//-----------------------------------------------------------------------------
// @name Severe
//-----------------------------------------------------------------------------

/**
 
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerAdvisories;

/**
 Active wildfires as icons.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFiresObsIcons;

/**
 Active wildfires as points.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFiresObsPoints;

/**
 Lightning strike density measured as the number of lightning strikes per square meter per second.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerLightningStrikeDensity;

/**
 Cloud-to-ground lightning strikes in the last 15 minutes.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerLightningStrikes15Minute;

/**
 Cloud-to-ground lightning strikes in the last 15 minutes.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerLightningStrikes15MinuteIcons;

/**
 Cloud-to-ground lightning strikes in the last 5 minutes.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerLightningStrikes5Minute;

/**
 Cloud-to-ground lightning strikes in the last 5 minutes.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerLightningStrikes5MinuteIcons;


//-----------------------------------------------------------------------------
// @name Observations
//-----------------------------------------------------------------------------

/**
 Observed surface dew points.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerDewPoints;

/**
 Surface feels like temperature. This value is either the actual temperature, wind chill or heat index value depending on conditions.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFeelsLike;

/**
 Surface heat index. This value is only shown when surface temperatures are at or above 80 degrees Fahrenheit.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerHeatIndex;

/**
 Observed surface humidity.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerHumidity;

/**
 Observed precipitation.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecip;

/**
 14-day observed precipitation.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecip14Day;

/**
 180-day observed precipitation.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecip180Day;

/**
 1-day observed precipitation.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecip1Day;

/**
 1-hour observed precipitation.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecip1Hour;

/**
 30-day observed precipitation.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecip30Day;

/**
 60-day observed precipitation.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecip60Day;

/**
 7-day observed precipitation.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecip7Day;

/**
 90-day observed precipitation.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecip90Day;

/**
 Precipitation departure from normal.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepart;

/**
 14-day precipitation departure from normal.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepart14Day;

/**
 180-day precipitation departure from normal.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepart180Day;

/**
 1-day precipitation departure from normal.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepart1Day;

/**
 30-day precipitation departure from normal.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepart30Day;

/**
 60-day precipitation departure from normal.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepart60Day;

/**
 7-day precipitation departure from normal.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepart7Day;

/**
 90-day precipitation departure from normal.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepart90Day;

/**
 Precipitation departure from normal for the current month to date.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepartMTD;

/**
 Precipitation departure from normal as a percentage.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepartPercent;

/**
 14-day precipitation departure from normal as a percentage.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepartPercent14Day;

/**
 180-day precipitation departure from normal as a percentage.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepartPercent180Day;

/**
 1-day precipitation departure from normal as a percentage.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepartPercent1Day;

/**
 30-day precipitation departure from normal as a percentage.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepartPercent30Day;

/**
 60-day precipitation departure from normal as a percentage.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepartPercent60Day;

/**
 7-day precipitation departure from normal as a percentage.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepartPercent7Day;

/**
 90-day precipitation departure from normal as a percentage.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepartPercent90Day;

/**
 Precipitation departure from normal for the current month to date as a percentage.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepartPercentMTD;

/**
 Precipitation departure from normal for the current water year to date as a percentage.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepartPercentWYTD;

/**
 Precipitation departure from normal for the current year to date as a percentage.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepartPercentYTD;

/**
 Precipitation departure from normal for the current water year to date.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepartWYTD;

/**
 Precipitation departure from normal for the current year to date.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipDepartYTD;

/**
 Observed precipitation for the current month to date.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipMTD;

/**
 Normal precipitation.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipNormals;

/**
 14-day normal precipitation.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipNormals14Day;

/**
 180-day normal precipitation.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipNormals180Day;

/**
 1-day normal precipitation.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipNormals1Day;

/**
 30-day normal precipitation.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipNormals30Day;

/**
 60-day normal precipitation.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipNormals60Day;

/**
 7-day normal precipitation.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipNormals7Day;

/**
 90-day normal precipitation.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipNormals90Day;

/**
 Normal precipitation for the current month to date.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipNormalsMTD;

/**
 Normal precipitation for the current water year to date.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipNormalsWYTD;

/**
 Normal precipitation for the current year to date.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipNormalsYTD;

/**
 Observed precipitation for the current water year to date.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipWYTD;

/**
 Observed precipitation for the current year to date.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipYTD;

/**
 Estimated ground snow depth.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerSnowDepth;

/**
 Global estimated ground snow depth.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerSnowDepthGlobal;

/**
 Observed surface frontal and high/low pressure positions.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerSurfaceAnalysis;

/**
 Observed surface frontal positions.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerSurfaceAnalysisFronts;

/**
 Observed surface high/low pressure positions.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerSurfaceAnalysisPressure;

/**
 Observed surface temperatures.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerTemperatures;

/**
 Surface visibility.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerVisibility;

/**
 Surface wind chill. This value is only shown when surface temperatures are below 50 degrees Fahrenheit.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerWindChill;

/**
 Observed surface wind direction.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerWindDirection;

/**
 Observed surface wind gusts.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerWindGusts;

/**
 Observed surface wind speeds.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerWindSpeeds;


//-----------------------------------------------------------------------------
// @name Outlooks
//-----------------------------------------------------------------------------

/**
 Fire outlook for fires caused by dry lightning.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerFiresDryLightningOutlook;

/**
 CPC 6-10 day outlook for above/below normal precipitation.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipOutlook6To10Day;

/**
 CPC 8-14 day outlook for above/below normal precipitation.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerPrecipOutlook8To14Day;

/**
 CPC 6-10 day outlook for above/below normal temperatures.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerTempOutlook6To10Day;

/**
 CPC 8-14 day outlook for above/below normal temperatures.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerTempOutlook8To14Day;


//-----------------------------------------------------------------------------
// @name Ocean
//-----------------------------------------------------------------------------

/**
 Sea chlorophyll concentrations.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerChlorophyll;

/**
 Sea surface temperatures.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerSeaSurfaceTemps;


//-----------------------------------------------------------------------------
// @name Roads
//-----------------------------------------------------------------------------

/**
 Road conditions based on current and recent precipitation.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerRoadConditions;

/**
 Index used to determine state of roads: wet, snowy, or icy.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerRoadConditionsIndex;


//-----------------------------------------------------------------------------
// @name Base
//-----------------------------------------------------------------------------

/**
 Base map using NASA Blue Marble surface imagery.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerBaseBlueMarble;

/**
 Flat base map. Available in light and dark themes.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerBaseFlat;

/**
 Shaded terrain base map.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerBaseTerrain;


//-----------------------------------------------------------------------------
// @name Overlays
//-----------------------------------------------------------------------------

/**
 Overlay consisting of administration boundaries and labels, including labels for countries, states and major cities.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerOverlayAdmin;

/**
 Overlay consisting of administration boundaries and labels with emphasis on city labels versus state/country labels.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerOverlayAdminCities;

/**
 Overlay consisting of county/parish outlines within the US.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerOverlayCounties;

/**
 Overlay consisting of US interstate highways.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerOverlayInterstates;

/**
 Overlay consisting of rivers.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerOverlayRivers;

/**
 Overlay consisting of primary and secondary roads.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerOverlayRoads;

/**
 Overlay consisting of state/province outlines and text labels.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerOverlayStates;

/**
 Overlay consisting of state/province outlines only.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerOverlayStatesOutlines;


//-----------------------------------------------------------------------------
// @name Masks
//-----------------------------------------------------------------------------

/**
 Mask using the Blue Marble map theme that only renders the US transparent.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerMaskClipUSBlueMarble;

/**
 Mask using the flat base map theme that only renders the US transparent.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerMaskClipUSFlat;

/**
 Mask using the shaded terrain map theme that only renders the US transparent.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerMaskClipUSTerrain;

/**
 Mask using the Blue Marble base map theme that renders bodies of water transparent.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerMaskLandBlueMarble;

/**
 Mask using the flat base map theme that renders bodies of water transparent.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerMaskLandFlat;

/**
 Mask using the shaded terrain base map theme that renders bodies of water transparent.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerMaskLandTerrain;

/**
 Mask using the flat base map theme that renders everything other than the US transparent.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerMaskLandUSFlat;

/**
 Mask using the Bathymetry ocean theme that renders land transparent.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerMaskWaterDepth;

/**
 Mask using the flat base map theme that renders land transparent.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerMaskWaterFlat;	

//-----------------------------------------------------------------------------
// @name AMP Point/Shape Layers
//-----------------------------------------------------------------------------

/**
 Current and future convective outlooks using the raster AMP layer.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerAmpConvectiveOutlook;

/**
 Current and past drought index using the raster AMP layer.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerAmpDroughtIndex;

/**
 
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerAmpFireOutlook;

/**
 Displays lightning strikes on a weather map using the raster AMP layer. Using this layer instead of `AWFMapLayerStormCells` does not allow interacting
 with the points as you would when selecting an annotation associated with the point layer.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerAmpLightningStrikes;

/**
 Displays storm cells on a weather map using the raster AMP layer. Using this layer instead of `AWFMapLayerStormCells` does not allow interacting with the
 points as you would when selecting an annotation associated with the point layer.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerAmpStormCells;

/**
 Displays storm reports on a weather map using the raster AMP layer. Using this layer instead of `AWFMapLayerStormCells` does not allow interacting with the
 points as you would when selecting an annotation associated with the point layer.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerAmpStormReports;

/**
 Active tropical cyclones and tracks using the raster AMP layer. Using this layer instead of `AWFMapLayerTropicalCyclones` does not allow interactive with
 the points as you would when selecting an annotation associated with the point layer.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerAmpTropicalCyclones;

/**
 Current severe weather warnings using the raster AMP layer.
 */
FOUNDATION_EXPORT AWFMapLayer const AWFMapLayerAmpWarnings;

/**
 Prefix used for all future data layers.
 */
FOUNDATION_EXPORT NSString * const AWFFutureLayerPrefix;

NS_ASSUME_NONNULL_END
