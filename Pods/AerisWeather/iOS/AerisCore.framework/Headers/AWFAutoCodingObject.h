//
//  AWFAutoCodingObject.h
//  AerisCore
//
//  Created by Nicholas Shipes on 8/29/18.
//  Copyright © 2018 AerisWeather. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AWFAutoCodingObject : NSObject <NSCoding, NSCopying>

//-----------------------------------------------------------------------------
// @name Auto Coding
//-----------------------------------------------------------------------------

+ (instancetype)awf_objectWithContentsOfFile:(NSString *)path;
+ (NSDictionary *)awf_codableProperties;
- (void)awf_setWithCoder:(NSCoder *)aDecoder;
- (NSDictionary *)awf_codableProperties;
- (NSDictionary *)awf_dictionaryRepresentation;
- (BOOL)awf_writeToFile:(NSString *)filePath atomically:(BOOL)useAuxiliaryFile;

@end

NS_ASSUME_NONNULL_END
