#include "pch.h"

#include "ReactPackageProvider.h"
#if __has_include("ReactPackageProvider.g.cpp")
#include "ReactPackageProvider.g.cpp"
#endif

#include "../../cpp/prism-rn.h"
#include <TurboModuleProvider.h>

using namespace winrt::Microsoft::ReactNative;

namespace winrt::PrismRn::implementation
{

void ReactPackageProvider::CreatePackage(IReactPackageBuilder const &packageBuilder) noexcept
{
  //AddAttributedModules(packageBuilder, true);
  winrt::Microsoft::ReactNative::AddTurboModuleProvider<prismrn::PrismrnModule>(packageBuilder, L"Prism-Rn");
}

} // namespace winrt::PrismRn::implementation
