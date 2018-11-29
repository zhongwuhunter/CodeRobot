//
//  CRTemplate.h
//  CR
//
//  Created by tiger on 2018/11/27.
//  Copyright © 2018 tiger. All rights reserved.
//

#import <Foundation/Foundation.h>

#define CROC_Template_UILabel @"\
- (UILabel *)propertyName{\n\
    if (!_propertyName) {\n\
        UILabel *label = [UILabel new];\n\
        label.backgroundColor = [UIColor clearColor];\n\
        label.font = [UIFont nm_FontOfSize:<#(CGFloat)#>];\n\
        label.textColor = [UIColor nm_colorFromRGB:<#type#>];\n\
        _propertyName = label;\n\
    }\n\
    return _propertyName;\n\
}"



#define CROC_Template_UIImageView @"\
- (UIImageView *)propertyName{\n\
    if (!_propertyName) {\n\
        UIImage *image = [UIImage imageNamed:<#type#>];\n\
        UIImageView *imageView = [UIImageView new];\n\
        imageView.image = image;\n\
        _propertyName = imageView;\n\
    }\n\
    return _propertyName;\n\
}"



#define CROC_Template_UIButton @"\
- (UIButton *)propertyName{\n\
    if (!_propertyName) {\n\
        UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];\n\
        [button setTitle:<#type#> forState:UIControlStateNormal];\n\
        [button setTitleColor:[UIColor nm_colorFromRGB:<#type#>] forState:UIControlStateNormal];\n\
        button.titleLabel.font = [UIFont nm_FontOfSize:<#(CGFloat)#>];\n\
        \n\
        UIImage *image = [UIImage imageWithColor:[UIColor nm_colorFromRGB:<#type#>]];\n\
        UIImage *selectedImage = [UIImage imageWithColor:[UIColor nm_colorFromRGB:<#type#>]];\n\
        [button setImage:image forState:UIControlStateNormal];\n\
        [button setImage:selectedImage forState:UIControlStateSelected];\n\
        \n\
        button.clipsToBounds = YES;\n\
        button.layer.cornerRadius = <#type#>;\n\
        button.layer.borderColor = [UIColor nm_colorFromRGB:<#type#>].CGColor;\n\
        button.layer.borderWidth = <#type#>;\n\
        \n\
        _propertyName = button;\n\
    }\n\
    return _propertyName;\n\
}"





#define CROC_Template_UITableView @"\
- (UITableView *)propertyName{\n\
    if (!_propertyName) {\n\
        UITableView *aTableView = [[UITableView alloc] initWithFrame:<#(CGRect)#> style:UITableViewStylePlain];\n\
        aTableView.backgroundColor = [UIColor nm_colorFromRGB:<#(long)#>];\n\
        aTableView.separatorStyle = UITableViewCellSeparatorStyleNone;\n\
        aTableView.rowHeight = <#(CGFloat)#>;\n\
        if (@available(iOS 11.0, *)) {\n\
            aTableView.contentInsetAdjustmentBehavior = UIScrollViewContentInsetAdjustmentNever;\n\
        }\n\
        _propertyName = aTableView;\n\
    }\n\
    return _propertyName;\n\
}"


#define CROC_Template_UITextField @"\
- (UITextField *)propertyName{\n\
    if (!_propertyName) {\n\
        UITextField *atextField = [UITextField new];\n\
        atextField.font = [UIFont nm_FontOfSize:<#(CGFloat)#>];\n\
        atextField.borderStyle = UITextBorderStyleNone;\n\
        atextField.keyboardType = UIKeyboardTypeDefault;\n\
        atextField.backgroundColor = [UIColor clearColor];\n\
        atextField.textColor = [UIColor nm_colorFromRGB:<#(long)#>];\n\
        atextField.tintColor = [UIColor nm_colorFromRGB:<#(long)#>];\n\
        _propertyName = atextField;\n\
    }\n\
    return _propertyName;\n\
}"


#define CROC_Template_Other @"\
- (UIView *)propertyName{\n\
    if (!_propertyName) {\n\
        _propertyName = [className new];\n\
    }\n\
    return _propertyName;\n\
}"



#pragma mark 插入的代码

#define CROC_Edit_Bun @"bun"
#define CROC_Edit_Bun_Value @"\
[[NSBundle mainBundle] pathForResource:<#(nullable NSString *)#> ofType:<#(nullable NSString *)#>];"





#define CROC_Edit_Damq @"damq"
#define CROC_Edit_Damq_Value @"\
dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(<#delayInSeconds#> * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{\n\
     <#code to be executed after a specified delay#>\n\
});"




































