//
//  CRCodeEditor.m
//  CR
//
//  Created by tiger on 2018/11/28.
//  Copyright © 2018年 tiger. All rights reserved.
//

#import "CRCodeEditor.h"
#import "CRTemplateManager.h"

@implementation CRCodeEditor

+ (instancetype)sharedInstance{
    static CRCodeEditor* instance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        instance = [CRCodeEditor new];
    });
    return instance;
}

- (void)handleInvocation:(XCSourceEditorCommandInvocation *)invocation{
    
    XCSourceTextRange *selection = invocation.buffer.selections.firstObject;
    NSMutableArray* lines = invocation.buffer.lines;
    NSInteger startLine = selection.start.line;
    //截取字符串的时候 由右向左截取
    NSInteger endColumn = selection.end.column;
    
    NSString* originalLine = lines[startLine];
    //匹配输入词的最大长度 例如 bun, dsay等
    int matchLength = 7;
    while (matchLength >= 1) {
        if ( endColumn-matchLength >= 0 ) {
            NSRange targetRange = NSMakeRange(endColumn-matchLength, matchLength);
            NSString *key = [originalLine substringWithRange:targetRange];
            NSString *targetString = [[CRTemplateManager sharedInstance].editTemplate valueForKey:key];
            if (targetString.length > 0) {
                lines[startLine] = [originalLine stringByReplacingOccurrencesOfString:key withString:targetString options:NSBackwardsSearch range:targetRange];
                NSLog(@"%@", targetString);
                break;
            }
        }
        matchLength --;
    }
    
    
}









































@end





