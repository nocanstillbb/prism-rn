#include "prism-rn.h"

namespace prismrn
{
PrismrnModule::PrismrnModule(
    std::shared_ptr<facebook::react::CallInvoker> jsInvoker)
    : facebook::react::NativePrismRnCxxSpec<PrismrnModule>(jsInvoker)
{
}
double PrismrnModule::multiply2(facebook::jsi::Runtime &rt, double a, double b)
{
    return 1;
}
double PrismrnModule::multiply(facebook::jsi::Runtime &rt, double a, double b)
{
    return 2;
}

} // namespace prismrn
