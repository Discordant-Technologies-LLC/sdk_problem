#pragma once

#include "pico/mutex.h"

namespace mutexes {

class Mutex {
 public:
  Mutex() { mutex_init(&mutex_); }
  mutex_t* mutex() { return &mutex_; }

  void Lock() { mutex_enter_blocking(&mutex_); }
  void Unlock() { mutex_exit(&mutex_); }

 private:
  mutex_t mutex_;
};

class MutexLock {
 public:
  MutexLock(Mutex& mtx) : mutex_(mtx) { mutex_.Lock(); }
  ~MutexLock() { mutex_.Unlock(); }

 private:
  Mutex& mutex_;
};

}  // namespace mutexes

