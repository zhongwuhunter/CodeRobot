插件用途

对已经定义的UI控件懒加载 例如 

@property (nonatomic, strong) UILabel                       *lable;
@property (nonatomic, strong) UIImageView                   *imageView;

等已经声明的数学 一键懒加载


辅助功能:  快捷键代码块。 
辅助功能 不如 Xcode 提供的 code snippet 功能。插件提供的快捷键功能没有代码提示。而 code snippet  有代码提示功能。不建议使用p辅助功能



使用注意事项

1   属性懒加载的功能 需要有 #pragma mark lazyload 
2   代码里面 对 UIFont, UIColor 等使用了自定义类别。




