//
//  AWFRequest.h
//  AerisCore
//
//  Created by Nicholas Shipes on 6/9/16.
//  Copyright © 2016 AerisWeather. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AerisCore/AWFResponseSerializer.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString *AWFRequestMethod NS_TYPED_ENUM;
FOUNDATION_EXPORT AWFRequestMethod const AWFRequestMethodGet;
FOUNDATION_EXPORT AWFRequestMethod const AWFRequestMethodHead;
FOUNDATION_EXPORT AWFRequestMethod const AWFRequestMethodPost;
FOUNDATION_EXPORT AWFRequestMethod const AWFRequestMethodPut;
FOUNDATION_EXPORT AWFRequestMethod const AWFRequestMethodPatch;
FOUNDATION_EXPORT AWFRequestMethod const AWFRequestMethodDelete;

typedef NS_ENUM(NSUInteger, AWFParameterEncoding) {
	AWFParameterEncodingURL = 0,
	AWFParameterEncodingURLEncodedInURL,
	AWFParameterEncodingJSON,
	AWFParameterEncodingPropertyList,
	AWFParameterEncodingCustom
};

typedef void (^AWFRequestProgress)(double fractionCompleted, int64_t bytesRecieved, int64_t totalBytesReceived, int64_t totalBytesExpectedToReceive);

@class AWFResponse, AWFResponseSerializer, AWFURLSessionTaskDelegate;

@interface AWFRequest : NSObject

@property (readonly, nonatomic, strong) AWFURLSessionTaskDelegate *delegate;
@property (nonatomic) NSURLSessionTask *task;
@property (readonly, nonatomic, strong) NSURLSession *session;
@property (nonatomic, nullable) NSURLRequest *request;
@property (nonatomic, nullable) NSHTTPURLResponse *response;
@property (nonatomic) NSProgress *progress;

- (instancetype)initWithSession:(NSURLSession *)session task:(NSURLSessionTask *)task;

- (void)resume;
- (void)suspend;
- (void)cancel;

- (void)setProgressHandler:(AWFRequestProgress)progressHandler;

//-----------------------------------------------------------------------------
// @name Responses
//-----------------------------------------------------------------------------

- (void)responseInQueue:(nullable dispatch_queue_t)queue completionHandler:(AWFResponseSerializerBlock)completionHandler;
- (void)responseWithSerializer:(AWFResponseSerializer *)serializer inQueue:(nullable dispatch_queue_t)queue completionHandler:(void (^)(AWFResponse *response))completionHandler;

- (void)responseAsData:(nullable dispatch_queue_t)queue completionHandler:(void (^)(AWFResponse *response))completionHandler;
- (void)responseAsString:(nullable dispatch_queue_t)queue encoding:(NSStringEncoding)encoding completionHandler:(void (^)(AWFResponse *response))completionHandler;
- (void)responseAsJSON:(nullable dispatch_queue_t)queue options:(NSJSONReadingOptions)options completionHandler:(void (^)(AWFResponse *response))completionHandler;
- (void)responseAsImage:(nullable dispatch_queue_t)queue completionHandler:(void (^)(AWFResponse *response))completionHandler;

//-----------------------------------------------------------------------------
// @name Response Serializers
//-----------------------------------------------------------------------------

+ (AWFResponseSerializer<NSData *> *)dataResponseSerializer;
+ (AWFResponseSerializer<NSString *> *)stringResponseSerializerWithEncoding:(NSStringEncoding)encoding;
+ (AWFResponseSerializer<NSObject *> *)JSONResponseSerializerWithOptions:(NSJSONReadingOptions)options;
+ (AWFResponseSerializer<UIImage *> *)imageResponseSerializer;

@end

NS_ASSUME_NONNULL_END
