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


#pragma mark 自定义UI

#define CROC_Edit_Custom_toast @"tot"
#define CROC_Edit_Custom_toast_Value @"\
[QHUIBuilder toast:error.domain];"


#define CROC_Edit_Custom_NmColor @"cor"
#define CROC_Edit_Custom_NmColor_Value @"\
[UIColor nm_colorFromRGB:<#(long)#>]"


// push,  mj插件  cell自定义 view初始化模板

#define CROC_Edit_AttributedString @"atts"
#define CROC_Edit_AttributedString_Value @"\
NSDictionary *attributes = @{NSFontAttributeName:[UIFont nm_FontOfSize:<#(CGFloat)#>], NSForegroundColorAttributeName:[UIColor nm_colorFromRGB:<#(long)#>]};\n\
NSMutableAttributedString *attText = [[NSMutableAttributedString alloc] initWithString:<#(nonnull NSString *)#> attributes:attributes];"


#define CROC_Edit_Bun @"bun"
#define CROC_Edit_Bun_Value @"\
[[NSBundle mainBundle] pathForResource:<#(nullable NSString *)#> ofType:<#(nullable NSString *)#>];"



#define CROC_Edit_Damq @"damq"
#define CROC_Edit_Damq_Value @"\
dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(<#delayInSeconds#> * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{\n\
     <#code to be executed after a specified delay#>\n\
});"



#pragma mark ReactiveCocoa

//创建command
#define CROC_Edit_Rac_Cmd @"rcmd"
#define CROC_Edit_Rac_Cmd_Value @"\
[[RACCommand alloc] initWithSignalBlock:^RACSignal *(id input) {\n\
\n\
    return RACSignal.empty;\n\
}];"

//新信号
#define CROC_Edit_Rac_Sig @"rsig"
#define CROC_Edit_Rac_Sig_Value @"\
- (RACSignal *)<#type#>{\n\
    return [[RACSignal createSignal:^RACDisposable *(id<RACSubscriber> subscriber) {\n\
        \n\
        return nil;\n\
    }] deliverOnMainThread] ;\n\
}"

//普通订阅
#define CROC_Edit_Rac_Obs @"robs"
#define CROC_Edit_Rac_Obs_Value @"\
[RACObserve(<#TARGET#>, <#KEYPATH#>) subscribeNext:^(id x) {\n\
    @strongify(self);\n\
}];"

//command 订阅
#define CROC_Edit_Rac_Robcl @"robcl"
#define CROC_Edit_Rac_Robcl_Value @"\
[.executionSignals switchToLatest subscribeNext:^(id x) {\n\
    @strongify(self);\n\
}];"

//command 错误订阅
#define CROC_Edit_Rac_Robce @"robce"
#define CROC_Edit_Rac_Robce_Value @"\
[.errors subscribeNext:^(NSError *error) {\n\
    @strongify(self);\n\
}];"


//双向绑定
#define CROC_Edit_Rac_Db @"rdb"
#define CROC_Edit_Rac_Db_Value @"\
RAC(<#TARGET#>, <#KEYPATH#>) = RACObserve(self, <#KEYPATH#>)"


#pragma mark Delegate

#define CROC_Edit_Delegate_Dtab @"dtab"
#define CROC_Edit_Delegate_Dtab_Value @"\
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{\n\
    return 0;\n\
}\n\
\n\
- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{\n\
    return 36;\n\
}\n\
\n\
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {\n\
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:[UITableViewCell description]];\n\
    return cell;\n\
}"






























