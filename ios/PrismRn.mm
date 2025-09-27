#import "PrismRn.h"

@implementation PrismRn
//不注册oc 的turbomodule,但保留代码以供后继有需要时查看对比代码
//RCT_EXPORT_MODULE()


- (NSNumber *)multiply:(double)a b:(double)b {
    //NSNumber *result = @(prismrn::multiply(a, b));
  

    return @3;
}

- (std::shared_ptr<facebook::react::TurboModule>)getTurboModule:
    (const facebook::react::ObjCTurboModule::InitParams &)params
{
    return std::make_shared<facebook::react::NativePrismRnSpecJSI>(params);
}

@end
