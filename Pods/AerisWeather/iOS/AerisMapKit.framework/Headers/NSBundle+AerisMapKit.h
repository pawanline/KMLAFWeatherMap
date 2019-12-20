//
//  NSBundle+AerisMapKit.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 3/23/18.
//Copyright © 2018 AerisWeather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Helpers and utilities on `NSBundle` for use within the Aeris SDK.
 */
@interface NSBundle (AerisMapKit)

/**
 Returns the main framework bundle.
 */
+ (NSBundle *)awf_aerisMapKitBundle;

/**
 Returns the resource bundle associated with the library.
 */
+ (NSBundle *)awf_aerisMapKitResourcesBundle;

/**
 Returns the bundle containing the language strings files associated with the library.
 */
+ (NSBundle *)awf_aerisMapKitStringsBundle;

@end
