#pragma once

#include "pch.h"
#include "resource.h"

#if __has_include("codegen/NativePrismRnDataTypes.g.h")
  #include "codegen/NativePrismRnDataTypes.g.h"
#endif
#include "codegen/NativePrismRnSpec.g.h"

#include "NativeModules.h"

namespace winrt::PrismRn
{

// See https://microsoft.github.io/react-native-windows/docs/native-platform for help writing native modules

REACT_MODULE(PrismRn)
struct PrismRn
{
  using ModuleSpec = PrismRnCodegen::PrismRnSpec;

  REACT_INIT(Initialize)
  void Initialize(React::ReactContext const &reactContext) noexcept;

  REACT_SYNC_METHOD(multiply)
  double multiply(double a, double b) noexcept;

private:
  React::ReactContext m_context;
};

} // namespace winrt::PrismRn