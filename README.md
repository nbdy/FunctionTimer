# FunctionTimer
```c++
#include "FunctionTimer.h"
#include <iostream>

int main() {
  FunctionTimer<void()> ft0("cout endl", [] {
    std::cout << "abc" << 42 << 0.666 << std::endl;
  }, true);
  FunctionTimer<void()> ft1("cout \\n", [] {
    std::cout << "abc" << 42 << 0.666 << '\n';
  }, true );
  FunctionTimer<void()> ft2("cout \\n flush", [] {
    std::cout << "abc" << 42 << 0.666 << '\n' << std::flush;
  }, true);
  FunctionTimer<void()> ft3("printf", [] {
    printf("%s%i%.3f\n", "abc", 42, 0.666);
  }, true);
  return 0;
}
```
outputs
```
abc420.666
cout endl: 27990 ns
abc420.666
cout \n: 1292 ns
abc420.666
cout \n flush: 1032 ns
abc420.666
printf: 3306 ns
```
