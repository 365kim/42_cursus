## STRLEN(3) BSD Library Functions Manual STRLEN(3)

### NAME
strlen, strnlen -- find length of string

### LIBRARY
Standard C Library (libc, -lc)

### SYNOPSIS
```
#include <string.h>

     size_t
     strlen(const char *s);

     size_t
     strnlen(const char *s, size_t maxlen);
```

### DESCRIPTION
- The strlen() function computes the length of the string s. 
- The strnlen() function attempts to compute the length of s, but never scans beyond the first maxlen bytes of s.

### RETURN VALUES
- The strlen() function returns the number of characters that precede the terminating NUL character. 
- The strnlen() function returns either the same result as strlen() or maxlen, whichever is smaller.

### SEE ALSO
- string(3), wcslen(3), wcswidth(3)

### STANDARDS
- The strlen() function conforms to ISO/IEC 9899:1990 (`ISO C90''). 
- The strnlen() function conforms to IEEE Std 1003.1-2008 (`POSIX.1'').

### BSD February 28, 2009 BSD
