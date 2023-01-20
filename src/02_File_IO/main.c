#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char** argv) {
   int fd;

   fd = open("../assets/raven.txt", O_RDONLY);

   if (fd == -1) {

   }

   return 0;
}
