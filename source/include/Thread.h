/**
 
Copyright (c) 2014-2015 National Instruments Corp.
 
This software is subject to the terms described in the LICENSE.TXT file
 
SDG
*/

/*! \file
    \brief Tools for working in a multithreaded process.
 */

#ifndef Thread_h
#define Thread_h

namespace Vireo
{

//------------------------------------------------------------
// In pure single thread environments like bare-metal, or
// single thread command line apps, no mutex infrastrucutre is
// needed. These macros help remove all overhead for those
// simple cases.
#ifdef  VIREO_MULTI_THREAD
    #define MUTEX_CLASS_MEMBER      Mutex _mutex;
    #define MUTEX_SCOPE()           MutexedScope mutexScope(&_mutex);
#else
    #define MUTEX_CLASS_MEMBER
    #define MUTEX_SCOPE()
#endif

#ifdef VIREO_MULTI_THREAD
//------------------------------------------------------------
class Mutex
{
private:
    void* _nativeMutex;
public:
    Mutex();
    ~Mutex();
    void Acquire();
    void Release();
};

//------------------------------------------------------------
class MutexedScope
{
private:
    Mutex *_mutex;
public:
    MutexedScope(Mutex* pMutex)
        { _mutex = pMutex; _mutex->Acquire(); }
    ~MutexedScope()
        { _mutex->Release(); }
};
#endif

}

#endif // Thread_h
