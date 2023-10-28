#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char** argv) {
  int fd_creat = creat("../assets/creat.txt", 0644);
  if (fd_creat == -1) {
  }

  int fd_raven = open("../assets/raven.txt", O_RDONLY);
  if (fd_raven == -1) {
  }

  //   unsigned long word;
  //   ssize_t nr = read(fd, &word, sizeof(unsigned long));

  ssize_t ret;
  ssize_t len = 1024 * 1024;
  char* buf = malloc(len * sizeof(char));
  char* buf_pos = buf;
  while (len != 0 && (ret = read(fd_raven, buf_pos, len)) != 0) {
    if (ret == -1) {
      if (errno == EINTR) continue;
      perror("read");
      break;
    }
    
    len -= ret;
    buf_pos += ret;
  }

  //   printf("%s\n", buf);

  const char* buf2 = "My ship is solid!";
  ssize_t nr = write(fd_creat, buf2, strlen(buf2));

  return 0;
}
