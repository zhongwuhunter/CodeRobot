//
//  SourceEditorCommand.m
//  CR
//
//  Created by tiger on 2018/11/26.
//  Copyright © 2018年 tiger. All rights reserved.
//

#import "SourceEditorCommand.h"
#import "CRLazyload.h"

@implementation SourceEditorCommand

- (void)performCommandWithInvocation:(XCSourceEditorCommandInvocation *)invocation completionHandler:(void (^)(NSError * _Nullable nilOrError))completionHandler
{
    [CRLazyload addLazyCodeWithInvocation:invocation];    
    completionHandler(nil);
}

@end
