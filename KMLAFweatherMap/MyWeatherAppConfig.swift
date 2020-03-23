//
//  MyWeatherAppConfig.swift
//  KMLAFweatherMap
//
//  Created by Pawan Kumar on 27/12/19.
//  Copyright © 2019 Pawan Kumar. All rights reserved.
//

import Foundation
import AerisWeatherKit
import AerisMapKit


class MyWeatherAppConfig: AWFWeatherMapConfig {
    
    override init() {
        super.init()
        
        self.timelineEndOffsetFromNow = 0
        self.timelineStartOffsetFromNow = -2 * AWFHourInterval
    }
}
