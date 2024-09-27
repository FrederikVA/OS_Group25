
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

/* Writes n to stdout (without any formatting).   
 * If no errors occur, it returns 0, otherwise EOF
 */

int write_int(int n) {
    char buffer[12];  // Large enough to store the largest 32-bit int value (-2147483648)
    int length = 0;
    
    // Handle negative numbers
    if (n < 0) {
        buffer[length++] = '-';
        n = -n;
    }

    // Handle the special case where n is 0
    if (n == 0) {
        buffer[length++] = '0';
    } else {
        int temp = n;
        while (temp > 0) {
            buffer[length++] = '0' + temp % 10;
            temp /= 10;
        }
    }

    // Write characters to stdout, in reverse order for the number part
    int bytes_written = 0;
    for (int i = length - 1; i >= 0; i--) {
        if (write(1, &buffer[i], 1) == -1) {
            return -1;  // Error condition
        }
        bytes_written++;
    }
    
    return bytes_written;  // Return the number of bytes written
}