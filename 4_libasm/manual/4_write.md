WRITE(2) BSD System Calls Manual WRITE(2)

NAME
pwrite, write, writev -- write output

LIBRARY
Standard C Library (libc, -lc)

SYNOPSIS
#include <unistd.h>

     ssize_t
     pwrite(int fildes, const void *buf, size_t nbyte, off_t offset);

     ssize_t
     write(int fildes, const void *buf, size_t nbyte);

     #include <sys/uio.h>

     ssize_t
     writev(int fildes, const struct iovec *iov, int iovcnt);

DESCRIPTION
write() attempts to write nbyte of data to the object referenced by the
descriptor fildes from the buffer pointed to by buf. writev() performs the
same action, but gathers the output data from the iovcnt buffers specified by
the members of the iov array: iov[0], iov[1], ..., iov[iovcnt-1]. pwrite()
performs the same function, but writes to the specified position in the file
without modifying the file pointer.

     For writev(), the iovec structure is defined as:

           struct iovec {
                   char   *iov_base;  /* Base address. */
                   size_t iov_len;    /* Length. */
           };

     Each iovec entry specifies the base address and length of an area in memory
     from which data should be written.  writev() will always write a complete area
     before proceeding to the next.

     On objects capable of seeking, the write() starts at a position given by the
     pointer associated with fildes, see lseek(2).  Upon return from write(), the
     pointer is incremented by the number of bytes which were written.

     Objects that are not capable of seeking always write from the current position.
     The value of the pointer associated with such an object is undefined.

     If the real user is not the super-user, then write() clears the set-user-id bit
     on a file.  This prevents penetration of system security by a user who
     ``captures'' a writable set-user-id file owned by the super-user.

     When using non-blocking I/O on objects, such as sockets, that are subject to
     flow control, write() and writev() may write fewer bytes than requested; the
     return value must be noted, and the remainder of the operation should be
     retried when possible.

RETURN VALUES
Upon successful completion the number of bytes which were written is returned.
Otherwise, a -1 is returned and the global variable errno is set to indicate
the error.

ERRORS
The write(), writev(), and pwrite() system calls will fail and the file pointer
will remain unchanged if:

     [EDQUOT]           The user's quota of disk blocks on the file system contain-
                        ing the file is exhausted.

     [EFAULT]           Part of iov or data to be written to the file points outside
                        the process's allocated address space.

     [EINVAL]           The pointer associated with fildes is negative.

     The write() and pwrite() system calls will fail and the file pointer will
     remain unchanged if:

     [EAGAIN]           The file is marked for non-blocking I/O, and no data could
                        be written immediately.

     [EBADF]            fildes is not a valid file descriptor open for writing.

     [ECONNRESET]       A write is attempted on a socket that is not connected.

     [EFBIG]            An attempt is made to write a file that exceeds the
                        process's file size limit or the maximum file size.

     [EFBIG]            The file is a regular file, nbyte is greater than 0, and the
                        starting position is greater than or equal to the offset
                        maximum established in the open file description associated
                        with fildes.

     [EINTR]            A signal interrupts the write before it could be completed.

     [EIO]              An I/O error occurs while reading from or writing to the
                        file system.

     [ENETDOWN]         A write is attempted on a socket and the local network
                        interface used to reach the destination is down.

     [ENETUNREACH]      A write is attempted on a socket and no route to the network
                        is present.

     [ENOSPC]           There is no free space remaining on the file system contain-
                        ing the file.

     [ENXIO]            A request is made of a nonexistent device, or the request is
                        outside the capabilities of the device.

     [EPIPE]            An attempt is made to write to a pipe that is not open for
                        reading by any process.

     [EPIPE]            An attempt is made to write to a socket of type SOCK_STREAM
                        that is not connected to a peer socket.

     The write() and writev() calls may also return the following errors:

     [EAGAIN]           See EWOULDBLOCK, below.

     [EWOULDBLOCK]      The file descriptor is for a socket, is marked O_NONBLOCK,
                        and write would block.  The exact error code depends on the
                        protocol, but EWOULDBLOCK is more common.

     In addition, writev() may return one of the following errors:

     [EDESTADDRREQ]     The destination is no longer available when writing to a
                        UNIX domain datagram socket on which connect(2) or
                        connectx(2) had been used to set a destination address.

     [EINVAL]           Iovcnt is less than or equal to 0, or greater than
                        UIO_MAXIOV.

     [EINVAL]           One of the iov_len values in the iov array is negative.

     [EINVAL]           The sum of the iov_len values in the iov array overflows a
                        32-bit integer.

     [ENOBUFS]          The mbuf pool has been completely exhausted when writing to
                        a socket.

     The pwrite() call may also return the following errors:

     [EINVAL]           The specified file offset is invalid.

     [ESPIPE]           The file descriptor is associated with a pipe, socket, or
                        FIFO.

LEGACY SYNOPSIS
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

     These include files are needed for all three functions.

SEE ALSO
fcntl(2), lseek(2), open(2), pipe(2), select(2), compat(5)

STANDARDS
The write() function call is expected to conform to ISO/IEC 9945-1:1990
(`POSIX.1''). The writev() and pwrite() functions are expected to conform to X/Open Portability Guide Issue 4, Version 2 (`XPG4.2'').

HISTORY
The pwrite() function call appeared in AT&T System V Release 4 UNIX. The
writev() function call appeared in 4.2BSD. A write() function call appeared in
Version 6 AT&T UNIX.

BSD March 18, 2015 BSD
