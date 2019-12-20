//
//  AWFApiObject.h
//  AerisApiLibrary
//
//  Created by Nicholas Shipes on 3/24/15.
//  Copyright (c) 2015 AerisWeather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AerisCore/AWFAutoCodingObject.h>

@interface AWFApiObject : AWFAutoCodingObject

@property (readonly, nonatomic) id identifier;

- (void)updateWithObject:(AWFApiObject *)object;
- (NSDictionary *)toDictionary;

@end
