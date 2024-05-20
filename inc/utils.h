#ifndef _UTILS_H_
#define _UTILS_H_

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#ifdef _WIN32
#define usleep(x) Sleep(x)
#else
#define usleep(x) sleep(x / 1000)
#endif

#endif