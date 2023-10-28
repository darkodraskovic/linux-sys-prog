#include <stdio.h>

int main() {
  FILE *fp;
  char c;

  fp = fopen("../assets/raven.txt", "r");

  if (fp == NULL) {
    printf("Unable to open file\n");
    return 1;
  }

  // Read characters from file
  while ((c = fgetc(fp)) != EOF) {
    printf("%c", c);
  }

  // Check if end-of-file or error occurred
  if (feof(fp)) {
    printf("\nEnd of file reached\n");
  }
  else if (ferror(fp)) {
    printf("\nError reading file\n");
  }

  // Clear the error and end-of-file indicators
  clearerr(fp);

  // Check if end-of-file or error occurred
  if (feof(fp)) {
    printf("\nEnd of file reached\n");
  }
  else if (ferror(fp)) {
    printf("\nError reading file\n");
  }

  // Read more characters from file
  while ((c = fgetc(fp)) != EOF) {
    printf("%c", c);
  }

  // Check if end-of-file or error occurred
  if (feof(fp)) {
    printf("\nEnd of file reached\n");
  }
  else if (ferror(fp)) {
    printf("\nError reading file\n");
  }

  fclose(fp);

  return 0;
}
