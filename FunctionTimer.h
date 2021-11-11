//
// Created by nbdy on 10.11.21.
//

#ifndef TIMEDSECTION__FUNCTIONTIMER_H_
#define TIMEDSECTION__FUNCTIONTIMER_H_

#define ENDL '\n'
// #define ENABLE_VERBOSE

#ifdef ENABLE_VERBOSE
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
#ifdef ENABLE_VERBOSE
  bool m_bVerbose = false;
#endif

  void _timeit(FunctionType i_Function) {
    m_u64Start = TIMESTAMP;
    i_Function();
    m_u64End = TIMESTAMP;
#ifdef ENABLE_VERBOSE
    if(m_bVerbose) {
      if(m_sName == nullptr) {
        std::cout << __PRETTY_FUNCTION__ << " " << getExecutionTimeNs() << " ns\n";
      } else {
        std::cout << m_sName << " " << getExecutionTimeNs() << " ns\n";
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
  }

  FunctionTimer(FunctionType i_Function, bool i_bVerbose): m_bVerbose(i_bVerbose) {
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
