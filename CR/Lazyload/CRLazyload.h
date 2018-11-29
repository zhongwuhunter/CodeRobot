//
//  CRLazyload.h
//  CR
//
//  Created by tiger on 2018/11/26.
//  Copyright © 2018年 tiger. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <XcodeKit/XcodeKit.h>

@interface CRLazyload : NSObject

+ (BOOL)addLazyCodeWithInvocation:(XCSourceEditorCommandInvocation *)invocation;



@end
