#ifndef _SYSCALL_H
# define _SYSCALL_H

// System call numbers
#define SYS_fork    1
#define SYS_exit    2
#define SYS_wait    3
#define SYS_pipe    4
#define SYS_read    5
#define SYS_kill    6
#define SYS_exec    7
#define SYS_fstat   8
#define SYS_chdir   9
#define SYS_dup    10
#define SYS_getpid 11
#define SYS_sbrk   12
#define SYS_sleep  13
#define SYS_uptime 14
#define SYS_open   15
#define SYS_write  16
#define SYS_mknod  17
#define SYS_unlink 18
#define SYS_link   19
#define SYS_mkdir  20
#define SYS_close  21

#ifdef GETPPID
# define SYS_getppid (SYS_close + 1)
#endif // GETPPID
#ifdef PSX
# define SYS_psx (SYS_getppid + 1)
#endif // PSX

#ifdef HALT
# define SYS_halt (SYS_psx + 1)
#endif // HALT

#ifdef VA2PA
# define SYS_va2pa (SYS_halt + 1)
#endif // VA2PA

#ifdef PRINT_PGTBL
# define SYS_print_pgtbl (SYS_va2pa + 1)
#endif // PRINT_PGTBL

#endif // _SYSCALL_H
