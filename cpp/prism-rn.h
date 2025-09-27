#ifndef PRISMRN_H
#define PRISMRN_H

#ifdef __APPLE__
#include "generated/ios/RNPrismRnSpecJSI.h"
#elif defined(__ANDROID__)
#include "RNPrismRnSpec/RNPrismRnSpecJSI.h"
#endif

#include <ReactCommon/CxxTurboModuleUtils.h>

#include <memory>
#include <string>

namespace prismrn
{

static const char *const Name = "PrismRn";

class JSI_EXPORT PrismrnModule : public facebook::react::NativePrismRnCxxSpec<PrismrnModule>
{

  public:
    PrismrnModule();
    PrismrnModule(std::shared_ptr<facebook::react::CallInvoker> jsInvoker);
    double multiply(facebook::jsi::Runtime &rt, double a, double b);
    double multiply2(facebook::jsi::Runtime &rt, double a, double b);
};

struct Register_PrismrnModule
{
    Register_PrismrnModule()
    {
        facebook::react::registerCxxModuleToGlobalModuleMap(Name, [](std::shared_ptr<facebook::react::CallInvoker> jsInvoker) { return std::make_shared<PrismrnModule>(jsInvoker); });
    }
};
static inline Register_PrismrnModule _Register_PrismrnModule;

} // namespace prismrn

#endif /* PRISMRN_H */
