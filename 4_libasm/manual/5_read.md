READ(2) BSD System Calls Manual READ(2)

NAME
pread, read, readv -- read input

LIBRARY
Standard C Library (libc, -lc)

SYNOPSIS
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

     ssize_t
     pread(int d, void *buf, size_t nbyte, off_t offset);

     ssize_t
     read(int fildes, void *buf, size_t nbyte);

     ssize_t
     readv(int d, const struct iovec *iov, int iovcnt);

DESCRIPTION
read() attempts to read nbyte bytes of data from the object referenced by the
descriptor fildes into the buffer pointed to by buf. readv() performs the same
action, but scatters the input data into the iovcnt buffers specified by the
members of the iov array: iov[0], iov[1], ..., iov[iovcnt-1]. pread() performs
the same function, but reads from the specified position in the file without
modifying the file pointer.

     For readv(), the iovec structure is defined as:

           struct iovec {
                   char   *iov_base;  /* Base address. */
                   size_t iov_len;    /* Length. */
           };

     Each iovec entry specifies the base address and length of an area in memory
     where data should be placed.  readv() will always fill an area completely
     before proceeding to the next.

     On objects capable of seeking, the read() starts at a position given by the
     pointer associated with fildes (see lseek(2)).  Upon return from read(), the
     pointer is incremented by the number of bytes actually read.

     Objects that are not capable of seeking always read from the current position.

...skipping...
FIFO.

     The read() call may also return the following errors:

     [ECONNRESET]       The connection is closed by the peer during a read attempt
                        on a socket.

     [ENOTCONN]         A read is attempted on an unconnected socket.

     [ETIMEDOUT]        A transmission timeout occurs during a read attempt on a
                        socket.

     The readv() call may also return one of the following errors:

     [EFAULT]           Part of the iov points outside the process's allocated
                        address space.

     [EINVAL]           Iovcnt was less than or equal to 0, or greater than 16.

     [EINVAL]           One of the iov_len values in the iov array was negative.

     [EINVAL]           The sum of the iov_len values in the iov array overflowed a
                        32-bit integer.

LEGACY SYNOPSIS
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

     The include files <sys/types.h> and <sys/uio.h> are necessary for all func-
     tions.

SEE ALSO
dup(2), fcntl(2), open(2), pipe(2), select(2), socket(2), socketpair(2),
compat(5)

STANDARDS
The read() function call is expected to conform to ISO/IEC 9945-1:1990
(`POSIX.1''). The readv() and pread() functions are expected to conform to X/Open Portability Guide Issue 4, Version 2 (`XPG4.2'').

HISTORY
The pread() function call appeared in AT&T System V Release 4 UNIX. The
readv() function call appeared in 4.2BSD. A read() function call appeared in
Version 6 AT&T UNIX.

BSD February 26, 1994 BSD
