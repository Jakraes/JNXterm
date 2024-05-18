#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <stdio.h>

static FILE* f;

#define LOG_INIT                                                            \
    f = fopen("log.txt", "w");                                              \
    fprintf(f, "LOG START | %s\n", __TIMESTAMP__);                          \
    fprintf(f, "--------------------------------------------\n");           \
    fclose(f);

#define LOG_END                                                             \
    f = fopen("log.txt", "a");                                              \
    fprintf(f, "--------------------------------------------\n");           \
    fprintf(f, "LOG END | %s\n", __TIMESTAMP__);                            \
    fclose(f);

#define LOG_EXIT(code)                                                      \
    f = fopen("log.txt", "a");                                              \
    fprintf(f, "%s %d | EXIT\n", __FILE__, __LINE__);                       \
    fclose(f);                                                              \
    exit(code);

#define LOG_MSG(msg, ...)                                                   \
    f = fopen("log.txt", "a");                                              \
    fprintf(f, "%s %d | LOG: " msg "\n", __FILE__, __LINE__, __VA_ARGS__);  \
    fclose(f);

#define LOG_WARN(msg, ...)                                                  \
    f = fopen("log.txt", "a");                                              \
    fprintf(f, "%s %d | WARN: " msg "\n", __FILE__, __LINE__, __VA_ARGS__); \
    fclose(f);

#define LOG_ERR(msg, ...)                                                   \
    f = fopen("log.txt", "a");                                              \
    fprintf(f, "%s %d | ERR: " msg "\n", __FILE__, __LINE__, __VA_ARGS__);    \
    fclose(f);

#endif


