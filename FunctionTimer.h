/*
MIT License

Copyright (c) 2021 Pascal Eberlein

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#ifndef TIMEDSECTION__FUNCTIONTIMER_H_
#define TIMEDSECTION__FUNCTIONTIMER_H_

#ifdef FUNCTION_TIMER_VERBOSE
#include <iostream>
#endif

#include <chrono>

using Clock = std::chrono::high_resolution_clock;

#define TIMESTAMP Clock::now().time_since_epoch().count()

template<typename FunctionType>
class FunctionTimer {
  const char* m_sName = nullptr;
  uint64_t m_u64Start = 0U;
  uint64_t m_u64End = 0U;
#ifdef FUNCTION_TIMER_VERBOSE
  bool m_bVerbose = false;
#endif

  void _timeit(FunctionType i_Function) {
    m_u64Start = TIMESTAMP;
    i_Function();
    m_u64End = TIMESTAMP;
#ifdef FUNCTION_TIMER_VERBOSE
    if (m_bVerbose) {
      if (m_sName == nullptr) {
        std::cout << __PRETTY_FUNCTION__ << " " << getExecutionTimeNs() << " ns\n";
      } else {
        std::cout << m_sName << ": " << getExecutionTimeNs() << " ns\n";
      }
    }
#endif
  }

 public:
  enum TimeUnit {
    NanoSeconds = 0,
    MicroSeconds,
    MilliSeconds,
    Seconds
  };

  explicit FunctionTimer(FunctionType i_Function) {
    _timeit(i_Function);
  };

  FunctionTimer(FunctionType i_Function, bool i_bVerbose)
#ifdef FUNCTION_TIMER_VERBOSE
      : m_bVerbose(i_bVerbose)
#endif
  {
    _timeit(i_Function);
  };

  FunctionTimer(const char* i_sName, FunctionType i_Function, bool i_bVerbose = true) : m_sName(i_sName)
#ifdef FUNCTION_TIMER_VERBOSE
    , m_bVerbose(i_bVerbose)
#endif
  {

    _timeit(i_Function);
  }

  uint64_t getExecutionTimeNs() const {
    return m_u64End - m_u64Start;
  }

  uint64_t getExecutionTimeUs() const {
    return getExecutionTimeNs() / 1000;
  }

  uint64_t getExecutionTimeMs() const {
    return getExecutionTimeUs() / 1000;
  }

  uint64_t getExecutionTimeS() const {
    return getExecutionTimeMs() / 1000;
  }

  uint64_t getExecutionTime(TimeUnit i_Unit) const {
    switch (i_Unit) {
      case NanoSeconds:
        return getExecutionTimeNs();
      case MicroSeconds:
        return getExecutionTimeUs();
      case MilliSeconds:
        return getExecutionTimeMs();
      case Seconds:
        return getExecutionTimeS();
      default:
        return getExecutionTimeNs();
    }
  }
};

#endif//TIMEDSECTION__FUNCTIONTIMER_H_
