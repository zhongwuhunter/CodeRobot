//
//  CRManager.m
//  CR
//
//  Created by tiger on 2018/11/29.
//  Copyright © 2018年 tiger. All rights reserved.
//

#import "CRManager.h"
#import "CRLazyload.h"
#import "CRCodeEditor.h"

@implementation CRManager

+ (void)handleInvocation:(XCSourceEditorCommandInvocation *)invocation{
    if ([CRLazyload addLazyCodeWithInvocation:invocation]) {
        
    }else{
        [[CRCodeEditor sharedInstance] handleInvocation:invocation];
    }
    
}

@end


