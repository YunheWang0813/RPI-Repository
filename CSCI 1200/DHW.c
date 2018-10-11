#include <stdio.h>
#include <stdlib.h>

int seq1(int x) {
  return 4 * x - 3;
}

void printSeq1Range(int low, int high) {
  if (low >= high) {
    printf("\n");
    return;
  }
  for (int i = low; i < high; i++) {
    if (i == high - 1) {
      printf("%d\n", seq1(i));
    }
    else {
      printf("%d, ", seq1(i));
    }
  }
  return;
}

int main() {
  for (int i = -5; i < 6; i++) {
    printf("seq1(%d) = %d\n", i, seq1(i));
  }

  printf("printSeq1Range(%d, %d)\n", 0, 4);
  printSeq1Range(0, 4);
  printf("printSeq1Range(%d, %d)\n", 0, 0);
  printSeq1Range(0, 0);
  printf("printSeq1Range(%d, %d)\n", 4, 0);
  printSeq1Range(4, 0);
  printf("printSeq1Range(%d, %d)\n", -2, 6);
  printSeq1Range(-2, 6);
  printf("printSeq1Range(%d, %d)\n", 7, 3);
  printSeq1Range(7, 3);

  return EXIT_SUCCESS;
}
