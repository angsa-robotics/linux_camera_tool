#pragma once
#ifndef _SHORTCUTS_H_
#define _SHORTCUTS_H_

#include <pthread.h>
#include <inttypes.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/ioctl.h>
#include <linux/videodev2.h>
#include <linux/usb/video.h>
#include <errno.h>
#include <iconv.h>
#include <linux/uvcvideo.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <sys/mman.h>

#define CLEAR(x) memset(&(x), 0, sizeof(x))
#define SIZE(a) (sizeof(a) / sizeof(*a))

/*clip value between 0 and 255*/
#define CLIP(value) (uint8_t)(((value)>0xFF)?0xff:(((value)<0)?0:(value)))

#define __THREAD_TYPE pthread_t
#define __THREAD_CREATE(t,f,d) (pthread_create(t,NULL,f,d))
#define __THREAD_CREATE_ATTRIB(t,a,f,d) (pthread_create(t,a,f,d))
#define __THREAD_JOIN(t) (pthread_join(t, NULL))

#define __MUTEX_TYPE pthread_mutex_t
#define __STATIC_MUTEX_INIT PTHREAD_MUTEX_INITIALIZER
#define __INIT_MUTEX(m) ( pthread_mutex_init(m, NULL) )
#define __CLOSE_MUTEX(m) ( pthread_mutex_destroy(m) )
#define __LOCK_MUTEX(m) ( pthread_mutex_lock(m) )
#define __UNLOCK_MUTEX(m) ( pthread_mutex_unlock(m) )

#define _1MS    1
#define _ESC_KEY 27

struct device
{
    int fd;
    struct buffer *buffers;
    enum v4l2_buf_type type;
    enum v4l2_memory memtype;
    unsigned int nbufs;
    unsigned int width;
    unsigned int height;
    unsigned int bytesperline;
    unsigned int imagesize;
};

struct device_info
{
    unsigned int hw_rev;
    unsigned int fw_rev;
    char uuid[40];
   // char fuseid[16]; - some camera has fuse id
};
#endif