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
    
    //自定义UI
    [self.editTemplate setValue:CROC_Edit_Custom_toast_Value forKey:CROC_Edit_Custom_toast];
    [self.editTemplate setValue:CROC_Edit_Custom_NmColor_Value forKey:CROC_Edit_Custom_NmColor];
    
    //RAC
    [self.editTemplate setValue:CROC_Edit_Rac_Cmd_Value forKey:CROC_Edit_Rac_Cmd];
    [self.editTemplate setValue:CROC_Edit_Rac_Sig_Value forKey:CROC_Edit_Rac_Sig];
    [self.editTemplate setValue:CROC_Edit_Rac_Obs_Value forKey:CROC_Edit_Rac_Obs];
    [self.editTemplate setValue:CROC_Edit_Rac_Robcl_Value forKey:CROC_Edit_Rac_Robcl];
    [self.editTemplate setValue:CROC_Edit_Rac_Robce_Value forKey:CROC_Edit_Rac_Robce];
    [self.editTemplate setValue:CROC_Edit_Rac_Db_Value forKey:CROC_Edit_Rac_Db];
    
    //tableview
    [self.editTemplate setValue:CROC_Edit_Delegate_Dtab_Value forKey:CROC_Edit_Delegate_Dtab];
    
    
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


