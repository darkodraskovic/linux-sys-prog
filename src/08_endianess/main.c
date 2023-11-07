// Code to print the byte representation of program objects

#include <stdio.h>

typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
  int i;
  for (i = 0; i < len; i++) printf(" %.2x", start[i]);
  printf("\n");
}

void show_int(int x) { show_bytes((byte_pointer)&x, sizeof(int)); }

void show_float(float x) { show_bytes((byte_pointer)&x, sizeof(float)); }

void show_pointer(void* x) { show_bytes((byte_pointer)&x, sizeof(void*)); }

void test_show_bytes(int val) {
  int ival = val;
  float fval = (float)ival;
  int* pval = &ival;
  show_int(ival);
  show_float(fval);
  show_pointer(pval);
}

int main(int argc, char** argv) {
  printf("test show bytes func:\n");
  test_show_bytes(0x12345678);

  printf("solution to 2.5:\n");
  int a = 0x12345678;
  show_int(0x12345678);

  byte_pointer ap = (byte_pointer)&a;
  show_bytes(ap, 1);
  show_bytes(ap, 2);
  show_bytes(ap, 3);

  printf("solution to 2.6:\n");
  int b = 2607352;
  show_int(b);
  float c = 3510593.0;
  show_float(c);

  printf("solution to 2.7:\n");
  const char* m = "mnopqr";
  show_bytes((byte_pointer)m, strlen(m));

  return 0;
}
