//
//  AWFTropicalCyclones.h
//  AerisWeatherKit
//
//  Created by Nicholas Shipes on 8/9/18.
//  Copyright © 2018 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFWeatherEndpoint.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString * AWFTropicalCycloneFilter NS_TYPED_EXTENSIBLE_ENUM;
FOUNDATION_EXPORT AWFTropicalCycloneFilter const AWFTropicalCycloneFilterActive;
FOUNDATION_EXPORT AWFTropicalCycloneFilter const AWFTropicalCycloneFilterNotActive;
FOUNDATION_EXPORT AWFTropicalCycloneFilter const AWFTropicalCycloneFilterAtlantic;
FOUNDATION_EXPORT AWFTropicalCycloneFilter const AWFTropicalCycloneFilterEastPacific;
FOUNDATION_EXPORT AWFTropicalCycloneFilter const AWFTropicalCycloneFilterCentralPacific;
FOUNDATION_EXPORT AWFTropicalCycloneFilter const AWFTropicalCycloneFilterWestPacific;
FOUNDATION_EXPORT AWFTropicalCycloneFilter const AWFTropicalCycloneFilterPacific;
FOUNDATION_EXPORT AWFTropicalCycloneFilter const AWFTropicalCycloneFilterIndian;
FOUNDATION_EXPORT AWFTropicalCycloneFilter const AWFTropicalCycloneFilterSouthern;
FOUNDATION_EXPORT AWFTropicalCycloneFilter const AWFTropicalCycloneFilterPosition;
FOUNDATION_EXPORT AWFTropicalCycloneFilter const AWFTropicalCycloneFilterTrack;
FOUNDATION_EXPORT AWFTropicalCycloneFilter const AWFTropicalCycloneFilterForecast;
FOUNDATION_EXPORT AWFTropicalCycloneFilter const AWFTropicalCycloneFilterGeo;
FOUNDATION_EXPORT AWFTropicalCycloneFilter const AWFTropicalCycloneFilterTest;

/**
 `AWFTropicalCyclones` provides convenience methods for interacting with the
 [`tropicalcyclones` endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/tropicalcyclones) of the Aeris API. All requests will
 return instances of `AWFTropicalCyclone` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFTropicalCyclones : AWFWeatherEndpoint
@end

/**
 `AWFTropicalCyclonesArchive` provides convenience methods for interacting with the
 [`tropicalcyclones/archive` endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/tropicalcyclones/archive) of the Aeris API. All requests will
 return instances of `AWFTropicalCyclone` that will be populated by the data returned by the API unless otherwise indicated.
 */
@interface AWFTropicalCyclonesArchive : AWFWeatherEndpoint

- (void)getWithOptions:(nullable AWFWeatherRequestOptions *)options completion:(AWFWeatherEndpointCompletionBlock)completionBlock NS_UNAVAILABLE;
- (void)getFrom:(nullable NSString *)fromString to:(nullable NSString *)toString options:(nullable AWFWeatherRequestOptions *)options completion:(AWFWeatherEndpointCompletionBlock)completionBlock NS_UNAVAILABLE;
- (void)getForPlace:(AWFPlace *)place options:(nullable AWFWeatherRequestOptions *)options completion:(AWFWeatherEndpointCompletionBlock)completionBlock NS_UNAVAILABLE;

/**
 Requests data for the specified tropical season based on a specific search query and request options. This method requires a valid `query` value on the provided
 options instance.
 
 Note: If no objects were returned from the request, but the request did not contain any errors, then the `completionBlock` block will still
 be executed without errors. Your block handler should verify the total number of objects returned before trying to access them.
 
 @param year The tropical season to search within
 @param options An `AWFWeatherRequestOptions` instance containing additional parameters to be used with the request (optional)
 @param completionBlock The block to be executed on the completion or failure of a request. This block has no return value and takes two arguments:
 the array of `AWFWeatherObject` instances returned by the request and the error that occurred during the request (if any)
 */
- (void)searchUsingYear:(NSUInteger)year options:(nullable AWFWeatherRequestOptions *)options completion:(AWFWeatherEndpointCompletionBlock)completionBlock;

@end

NS_ASSUME_NONNULL_END
