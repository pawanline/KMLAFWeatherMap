//
//  AWFMemoryCache.h
//  AerisCore
//
//  Created by Nicholas Shipes on 9/28/15.
//  Copyright © 2015 AerisWeather. All rights reserved.
//

#import <AerisCore/AWFCache.h>

@interface AWFMemoryCache : AWFCache

+ (instancetype)sharedCache;

@end
