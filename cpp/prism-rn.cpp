#include "prism-rn.h"

namespace prismrn
{

PrismrnModule::PrismrnModule(std::shared_ptr<facebook::react::CallInvoker> jsInvoker) : facebook::react::NativePrismRnCxxSpec<PrismrnModule>(std::move(jsInvoker))
{
}
double PrismrnModule::multiply2(facebook::jsi::Runtime &rt, double a, double b)
{
    return a * b + 10;
}
double PrismrnModule::multiply(facebook::jsi::Runtime &rt, double a, double b)
{
    return a * b + 5;
}

} // namespace prismrn
