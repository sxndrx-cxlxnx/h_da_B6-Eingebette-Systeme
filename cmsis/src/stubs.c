/**
 * @file stubs.c
 * @brief Minimal stub functions to facilitate compilation with the C Standard Library.
 *
 * This file contains minimal stub functions that are placeholders and serve the sole purpose
 * of facilitating compilation when the C Standard Library functions are required.
 * These stubs do not provide any functionality and are intended as placeholders
 * or starting points for future development. They are included to ensure successful
 * compilation with the C Standard Library.
 *
 * @author David Heiß
 * @date Fri Sep 22 10:18:39 PM CEST 2023
 */

#include <sys/stat.h>

int _close(int fildes) __attribute__((weak, alias("_close_stub")));
int _close_stub(int fildes) { return 0; }

_off_t _lseek(int fildes, _off_t offset, int whence) __attribute__((weak, alias("_lseek_stub")));
_off_t _lseek_stub(int fildes, _off_t offset, int whence) { return 0l; }

_ssize_t _read(int fildes, void *buf, size_t nbyte) __attribute__((weak, alias("_read_stub")));
_ssize_t _read_stub(int fildes, void *buf, size_t nbyte) { return 0; }

_ssize_t _write(int fildes, const void *buf, size_t nbyte) __attribute__((weak, alias("_write_stub")));
_ssize_t _write_stub(int fildes, const void *buf, size_t nbyte) { return 0; }

void *_sbrk(intptr_t increment) __attribute__((weak, alias("_sbrk_stub")));
void *_sbrk_stub(intptr_t increment) { return NULL; }

void _exit(int status) __attribute__((weak, alias("_exit_stub")));
void _exit_stub(int status)
{
    while (1)
    {
    }
}

int _fstat(int fildes, struct stat *buf) __attribute__((weak, alias("_fstat_stub")));
int _fstat_stub(int fildes, struct stat *buf) { return 0; }

int _isatty(int fd) __attribute__((weak, alias("_isatty_stub")));
int _isatty_stub(int fd) { return 0; }

int _kill(__pid_t pid, int sig) __attribute__((weak, alias("_kill_stub")));
int _kill_stub(__pid_t pid, int sig) { return 0; }

__pid_t _getpid(void) __attribute__((weak, alias("_getpid_stub")));
__pid_t _getpid_stub(void) { return 0; }