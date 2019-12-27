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
        
        self.refreshInterval = 1 * AWFSecondInterval
        self.animationEnabled = true
        self.showsCountyLines = true
        self.tileOverlayLevel = .aboveRoads
    }
}
