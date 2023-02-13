#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#define TIMEOUT 5
#define BUF_LEN 1024

int main(int argc, char *argv[]) {
  struct timeval tv;
  fd_set readfds;
  int ret;

  FD_ZERO(&readfds);
  FD_SET(STDIN_FILENO, &readfds);

  tv.tv_sec = TIMEOUT;
  tv.tv_usec = 0;

  ret = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &tv);
  if (ret < 0) {
    perror("select");
    return 1;
  } else if (ret == 0) {
    fprintf(stderr, "Timeout\n");
    return 1;
  }

  if (FD_ISSET(STDIN_FILENO, &readfds)) {
    char buf[BUF_LEN];

    ret = read(STDIN_FILENO, buf, BUF_LEN);
    if (ret < 0) {
      perror("read");
      return 1;
    } else if (ret == 0) {
      fprintf(stderr, "Timeout\n");
      return 1;
    }

    printf("%s", buf);

    return 0;
  }
}