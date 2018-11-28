//
//  CRTemplateManager.h
//  CR
//
//  Created by tiger on 2018/11/27.
//  Copyright © 2018 tiger. All rights reserved.
//

#import <Foundation/Foundation.h>



@interface CRTemplateManager : NSObject

@property (nonatomic, strong) NSMutableDictionary      *editTemplate;
@property (nonatomic, strong) NSMutableDictionary      *mappingTemplate;


+ (instancetype)sharedInstance;

+ (NSString *)mappingWithClassName:(NSString *)className propertyName:(NSString *)propertyName;

@end


