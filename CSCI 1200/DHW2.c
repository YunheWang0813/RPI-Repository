#include <stdio.h>
#include <stdlib.h>

int seq2(int x) {
  int ans = -1;
  int times = 0;
  if (x >= -1) {
    times = x + 1;
  }
  else if (x <= -2) {
    times = -2 - x;
  }
  for (int i = 0; i < times; i++) {
    ans += 2 * (i + 1);
  }
  return ans;
}

int sumSeq2(int low, int high) {
  int ans = 0;
  if (low < high) {
    for (int i = low; i < high; i++) {
      ans += seq2(i);
    }
  }
  return ans;
}

int main() {
  for (int i = -5; i < 6; i++) {
    printf("seq2(%d) = %d\n", i, seq2(i));
  }

  printf("sumSeq2(%d, %d) = %d\n", 0, 2, sumSeq2(0, 2));
  printf("sumSeq2(%d, %d) = %d\n", 3, 6, sumSeq2(3, 6));
  printf("sumSeq2(%d, %d) = %d\n", 9, 7, sumSeq2(9, 7));
  printf("sumSeq2(%d, %d) = %d\n", 7, 7, sumSeq2(7, 7));
  printf("sumSeq2(%d, %d) = %d\n", -5, 5, sumSeq2(-5, 5));

  return EXIT_SUCCESS;
}
