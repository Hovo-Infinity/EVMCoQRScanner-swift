//
//  DescriptionViewController.swift
//  EMVCQRScanner
//
//  Created by Hovhannes Stepanyan on 7/17/18.
//  Copyright © 2018 Hovhannes Stepanyan. All rights reserved.
//

import UIKit

class DescriptionViewController: UIViewController {
    @IBOutlet private var desctiptionView: UITextView!
    var descriptionText: String?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        desctiptionView.text = descriptionText ?? ""
        automaticallyAdjustsScrollViewInsets = false
    }

}
