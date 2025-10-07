#ifndef PRISMRN_H
#define PRISMRN_H

#include <memory>
#include <string>

#include "RNPrismRnSpecJSI.h"

#ifndef _WIN32
#include <ReactCommon/CxxTurboModuleUtils.h>
#endif //  _WIN32

namespace prismrn
{

static const char *const Name = "Prism-Rn";

class JSI_EXPORT PrismrnModule
    : public facebook::react::NativePrismRnCxxSpec<PrismrnModule>
{
  public:
    PrismrnModule();
    PrismrnModule(std::shared_ptr<facebook::react::CallInvoker> jsInvoker);
    double multiply(facebook::jsi::Runtime &rt, double a, double b);
    double multiply2(facebook::jsi::Runtime &rt, double a, double b);
};

#ifndef _WIN32
struct RegisterPrismrnModule
{

    RegisterPrismrnModule()
    {
        facebook::react::registerCxxModuleToGlobalModuleMap(
            Name, [](std::shared_ptr<facebook::react::CallInvoker> jsInvoker)
            { return std::make_shared<PrismrnModule>(jsInvoker); });
    }
};

static inline RegisterPrismrnModule _RegisterPrismrnModule;
#endif

} // namespace prismrn

#endif /* PRISMRN_H */
