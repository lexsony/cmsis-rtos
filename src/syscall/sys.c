#include "stm32f1xx_ll_utils.h"
#include "syscall.h"
#include <sys/select.h>

int sys_nanosleep(const struct timespec *rqtp, struct timespec *rmtp)
{
    LL_mDelay(rqtp->tv_sec * 1000 + rqtp->tv_nsec / 1000 / 1000);
    return 0;
}

int sys_select(int nfds, fd_set *restrict readfds,
           fd_set *restrict writefds, fd_set *restrict exceptfds,
           struct timeval *restrict timeout)
{
    return 1;
}

void *syscall_table[512];

void sys_init(void)
{
    syscall_table[SYS_SELECT] = sys_select;
    syscall_table[SYS_NANOSLEEP] = sys_nanosleep;
}
