#ifdef __cplusplus
extern "C" {
#endif

#ifndef __MICE_H__
#define __MICE_H__

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

extern char mice_data[3];

extern int fd_mice;

int get_mice();

int open_mice();

int close_mice();

#endif

#ifdef __cplusplus
}
#endif


