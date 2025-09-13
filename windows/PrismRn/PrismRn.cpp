#include "pch.h"

#include "PrismRn.h"

namespace winrt::PrismRn
{

// See https://microsoft.github.io/react-native-windows/docs/native-platform for help writing native modules

void PrismRn::Initialize(React::ReactContext const &reactContext) noexcept {
  m_context = reactContext;
}

double PrismRn::multiply(double a, double b) noexcept {
  return a * b;
}

} // namespace winrt::PrismRn