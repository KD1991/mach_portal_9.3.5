//
//  ViewController.m
//  mach-portal
//
//  Created by Kali on 2017/1/4.
//  Copyright © 2017年 Kali. All rights reserved.
//

#import "ViewController.h"

void exploit();

@interface ViewController ()

@property (weak, nonatomic) IBOutlet UIButton *button;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)button:(UIButton *)sender {
    self.button.enabled = NO;
    
    exploit();
    //kload();
    
    //self.label1.enabled = YES;
    //self.label1.text=@"Now Into the DFU mode";
    //self.label2.text=@"Open a terminal enter:";
    //self.label3.text=@"# idevicediagnostics sleep";
    [self.button setTitle:@"END" forState:UIControlStateNormal];
}

@end
