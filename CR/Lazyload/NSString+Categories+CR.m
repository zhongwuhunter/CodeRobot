//
//  NSString+Categories+CR.m
//  CR
//
//  Created by tiger on 2018/11/27.
//  Copyright © 2018 tiger. All rights reserved.
//

#import "NSString+Categories+CR.h"

@implementation NSString (NSString_Categories_CR)



// 不考虑 <>， id 等类型
- (NSString *)cr_className{
    NSString *str = [self copy];
    NSRange startRange = [str localizedStandardRangeOfString:@")"];
    NSRange endRange = [str localizedStandardRangeOfString:@"*"];
    NSString *result = [str substringWithRange:NSMakeRange(startRange.location+1, endRange.location-(startRange.location+1))];
    return result;
}

- (NSString *)cr_propertyName{
    NSString *str = [self copy];
    NSRange startRange = [str localizedStandardRangeOfString:@"*"];
    NSRange endRange = [str localizedStandardRangeOfString:@";"];
    NSString *result = [str substringWithRange:NSMakeRange(startRange.location+1, endRange.location-(startRange.location+1))];
    return result;
}























@end




