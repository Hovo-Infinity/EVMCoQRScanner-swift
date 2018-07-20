//
//  QRGeneratorViewController.swift
//  EMVCQRScanner
//
//  Created by Hovhannes Stepanyan on 7/19/18.
//  Copyright © 2018 Hovhannes Stepanyan. All rights reserved.
//

import UIKit

class QRGeneratorViewController: UIViewController, UITextViewDelegate {
    
    @IBOutlet weak var imageView: UIImageView!
    @IBOutlet weak var textView: UITextView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        textView.becomeFirstResponder()
    }
    
    // MARK: - UITextViewDelegate
    
    func textViewDidChange(_ textView: UITextView) {
        imageView.image = QRGenerator.generateQRFrom(textView.text)
    }

    @IBAction func backgroundTapped(_ sender: UITapGestureRecognizer) {
        textView.resignFirstResponder()
    }
    
}
