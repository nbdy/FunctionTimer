//
// Created by nbdy on 10.11.21.
//

#include "FunctionTimer.h"
#include <iostream>

int main() {
  FunctionTimer<void()> ft0([] {
    std::cout << "abc" << 123 << 0.420 << std::endl;
  });
  std::cout << "ft0 " << ft0.getExecutionTimeNs() << std::endl;

  FunctionTimer<void()> ft1([] {
    std::cout << "abc" << 123 << 0.420 << '\n';
  });
  std::cout << "ft1 " << ft1.getExecutionTimeNs() << std::endl;

  FunctionTimer<void()> ft2([] {
    std::cout << "abc" << 123 << 0.420 << '\n' << std::flush;
  });
  std::cout << "ft2 " << ft2.getExecutionTimeNs() << std::endl;
  return 0;
}