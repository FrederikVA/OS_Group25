
#include <errno.h>
#include <unistd.h>

#include "io.h"

/* Reads next char from stdin. If no more characters, it returns EOF */
int
read_char() {
  char c;
  if (read(0, &c, 1) == 1)
  {
    return c;
  } else {
    return EOF;
  }
}

/* Writes c to stdout.  If no errors occur, it returns 0, otherwise EOF */
int
write_char(char c) {
  if (write(1, &c, 1) == 1)
  {
    return 0;
  } else {
    return EOF;
  }
}

/* Writes a null-terminated string to stdout.  If no errors occur, it returns 0, otherwise EOF */
int
write_string(char* s) {
    int len = 0;
    while (s[len] != '\0') len++; {
        if (write(1, s, len) == len) {
            return 0;
        } else {
      return EOF;
        }
    }
}

int 
write_int(int n) {
  return EOF;
}

/* Writes n to stdout (without any formatting).   
 * If no errors occur, it returns 0, otherwise EOF
 */

/*
int
write_int(int n) {
    char buffer[12];
    int length = 0;
    
    //converting interger to string
    if (n=0) {
        buffer[length++] = '0';
    } else {
        while (n > 0) {
            buffer[length++] = '0' + n % 10;
            n /= 10;
        }
    }

    // Writing buffer
    for (int i = length - 1; i >= 0; i--) {
        if (write(1, %buffer[i], 1) == EOF) {
            return EOF;
        }
    }
    
  write(1, &n, 1);  
  return EOF;
}

*/