//
//  CRTemplateManager.m
//  CR
//
//  Created by tiger on 2018/11/27.
//  Copyright © 2018 tiger. All rights reserved.
//

#import "CRTemplateManager.h"
#import "CRTemplate.h"


@implementation CRTemplateManager

+ (NSString *)mappingWithClassName:(NSString *)className propertyName:(NSString *)propertyName{
    
    NSString *tmplString ;
    if ( [@"UILabel" isEqualToString:className] ) {
        tmplString = CROC_Template_UILabel;
    }else if ( [@"UIImageView" isEqualToString:className] ) {
        tmplString = CROC_Template_UIImageView;
    }else if ( [@"UIButton" isEqualToString:className] ) {
        tmplString = CROC_Template_UIButton;
    }else if ( [@"UITableView" isEqualToString:className] ) {
        tmplString = CROC_Template_UITableView;
    }else if ( [@"UITextField" isEqualToString:className] ) {
        tmplString = CROC_Template_UITextField;
    }else{
        tmplString = CROC_Template_Other;
    }
    tmplString = [tmplString stringByReplacingOccurrencesOfString:@"propertyName" withString:propertyName];
    tmplString = [tmplString stringByReplacingOccurrencesOfString:@"className" withString:className];
    return tmplString;
}



@end


