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
    int matchLength = 15;
    while (matchLength >= 1) {
        if ( endColumn-matchLength >= 0 ) {
            NSRange targetRange = NSMakeRange(endColumn-matchLength, matchLength);
            NSString *key = [originalLine substringWithRange:targetRange];
            //映射的模板代码
            NSString *templateString = [[CRTemplateManager sharedInstance].editTemplate valueForKey:key];
            
            if (templateString.length > 0) {
                NSArray *templateArray = [templateString componentsSeparatedByString:@"\n"];
                //替换模板第一行代码
                lines[startLine] = [originalLine stringByReplacingOccurrencesOfString:key withString:templateArray[0] options:NSBackwardsSearch range:targetRange];
                
                //偏移空格是为了处理多行代码映射的时候，格式化问题
                NSInteger offsetSpace = [originalLine rangeOfString:key].location;
                NSString *space = @"";
                while (offsetSpace > 0) {
                    space = [space stringByAppendingString:@" "];
                    offsetSpace --;
                }
                
                for (NSInteger j=1; j<templateArray.count; j++) {
                    NSString *insertLine = [NSString stringWithFormat:@"%@%@", space, templateArray[j]];
                    [lines insertObject:insertLine atIndex:startLine+j];
                }
                break;
            }
        }
        matchLength --;
    }
    
    
}









































@end





