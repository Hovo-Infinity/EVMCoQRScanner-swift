//
//  TableViewDataSource.swift
//  EMVCQRScanner
//
//  Created by Hovhannes Stepanyan on 7/18/18.
//  Copyright © 2018 Hovhannes Stepanyan. All rights reserved.
//

import Foundation

class TableViewDataSource {

    var numberOfSections: Int!
    var numberOfItemsInSection: ((_ section: Int) -> Int)!
    var descriptionForIndexPath: ((_ indexPath: IndexPath) -> String?)!
    var nameForIndexPath: ((_ indexPath: IndexPath) -> String)!
}
