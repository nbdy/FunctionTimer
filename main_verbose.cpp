//
// Created by nbdy on 10.11.21.
//

#define ENABLE_VERBOSE
#include "FunctionTimer.h"

int main() {
  FunctionTimer<void()> ft0([] {
    std::cout << "abc" << 123 << 0.420 << std::endl;
  }, true);
  FunctionTimer<void()> ft1([] {
    std::cout << "abc" << 123 << 0.420 << '\n';
  }, true );
  FunctionTimer<void()> ft2([] {
    std::cout << "abc" << 123 << 0.420 << '\n' << std::flush;
  }, true);
  return 0;
}