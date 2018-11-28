//
//  CRTemplateManager.m
//  CR
//
//  Created by tiger on 2018/11/27.
//  Copyright © 2018 tiger. All rights reserved.
//

#import "CRTemplateManager.h"
#import "CRTemplate.h"


@interface CRTemplateManager()



@end


@implementation CRTemplateManager


+ (instancetype)sharedInstance{
    static CRTemplateManager* instance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        instance = [CRTemplateManager new];
        [instance setup];
    });
    return instance;
}

- (void)setup{
    [self initEditTemplate];
    
    self.mappingTemplate = [NSMutableDictionary new];
}


- (void)initEditTemplate{
    self.editTemplate = [NSMutableDictionary new];
    NSString *str1 = CROC_Edit_BUN;
    NSString *str2 = CROC_Edit_BUN_Value;
    [self.editTemplate setValue:str2 forKey:str1];
    
}


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


