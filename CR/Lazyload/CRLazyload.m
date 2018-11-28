//
//  CRLazyload.m
//  CR
//
//  Created by tiger on 2018/11/26.
//  Copyright © 2018年 tiger. All rights reserved.
//

#import "CRLazyload.h"
#import "NSString+Categories+CR.h"
#import "CRTemplateManager.h"

@implementation CRLazyload


    


+ (void)addLazyCodeWithInvocation:(XCSourceEditorCommandInvocation *)invocation{
    XCSourceTextRange *selection = invocation.buffer.selections.firstObject;
    
        
        NSInteger startLine = selection.start.line;
        NSInteger endLine = selection.end.line;
        //选中缓存区
        NSInteger lineCount = invocation.buffer.lines.count;
        NSMutableArray *templateArray = [NSMutableArray new];
        for ( NSInteger index= startLine ; index<=endLine; index++) {
            NSString *lineString = invocation.buffer.lines[index];
            
            if ([lineString isEqualToString:@"\n"] || ![lineString containsString:@";"]) {
                continue;
            }
            lineString = [lineString stringByReplacingOccurrencesOfString:@" " withString:@""];
            NSString *className = [lineString cr_className];
            NSString *propertyName = [lineString cr_propertyName];
            NSString *templateString = [CRTemplateManager mappingWithClassName:className propertyName:propertyName];
            [templateArray addObject:templateString];
        }
    
        //输出到文件
        for (NSInteger i = 0 ; i < lineCount; i ++) {
            NSString *lineString = invocation.buffer.lines[i];
            if ([lineString containsString:@"#pragma mark lazyload"]){
                for (NSInteger index=templateArray.count-1; index>=0; index--) {
                    [invocation.buffer.lines insertObject:templateArray[index] atIndex:i+1];
                }
                break;
            }
        }
    
}





































@end


