#ifndef PRISMRN_H
#define PRISMRN_H



#include <iostream>
#include <memory>
#include <string>
#include <ReactCommon/CxxTurboModuleUtils.h>

#include "RNPrismRnSpecJSI.h"




namespace prismrn
{

static const char *const Name = "Prism-Rn";

class JSI_EXPORT PrismrnModule :public facebook::react::NativePrismRnCxxSpec<PrismrnModule>
{
public:
  PrismrnModule();
  PrismrnModule(std::shared_ptr<facebook::react::CallInvoker> jsInvoker);
  double multiply(facebook::jsi::Runtime &rt, double a, double b);
  double multiply2(facebook::jsi::Runtime &rt, double a, double b);
};

struct RegisterPrismrnModule
{
  
  RegisterPrismrnModule()
  {
    facebook::react::registerCxxModuleToGlobalModuleMap(Name, [](std::shared_ptr<facebook::react::CallInvoker> jsInvoker) { return std::make_shared<PrismrnModule>(jsInvoker); });
  }
};

static inline RegisterPrismrnModule _RegisterPrismrnModule ;


} // namespace prismrn

#endif /* PRISMRN_H */
