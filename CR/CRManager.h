//
//  CRManager.h
//  CR
//
//  Created by tiger on 2018/11/29.
//  Copyright © 2018年 tiger. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <XcodeKit/XcodeKit.h>

@interface CRManager : NSObject

+ (void)handleInvocation:(XCSourceEditorCommandInvocation *)invocation;

@end
