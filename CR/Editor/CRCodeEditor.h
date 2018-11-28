//
//  CRCodeEditor.h
//  CR
//
//  Created by tiger on 2018/11/28.
//  Copyright © 2018年 tiger. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <XcodeKit/XcodeKit.h>

@interface CRCodeEditor : NSObject

+ (instancetype)sharedInstance;


- (void)handleInvocation:(XCSourceEditorCommandInvocation *)invocation;






























@end




