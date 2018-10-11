#include <stdio.h>
#include <stdlib.h>

int seq3(int x, int y) {
  return 6 + (-2 - x) * (3 - y);
}

int countEvenInSeq3Range(int xLow, int xHi, int yLow, int yHi) {
  int EvenCounter = 0;
  if (xLow < xHi && yLow < yHi) {
    for (int i = xLow; i < xHi; i++) {
      for (int j = yLow; j < yHi; j++) {
        if (seq3(i, j) % 2 == 0) {
          EvenCounter++;
        }
      }
    }
  }
  return EvenCounter;
}

int main() {
  for (int i = -7; i < 8; i++) {
    for (int j = -7; j < 8; j++) {
      printf("seq3(%d, %d) = %d\n", i, j, seq3(i, j));
    }
  }

  printf(
      "countEvenInSeq3Range(%d, %d, %d, %d) = %d\n", 0, 2, 0, 3, countEvenInSeq3Range(0, 2, 0, 3));
  printf("countEvenInSeq3Range(%d, %d, %d, %d) = %d\n",
         -1,
         1,
         3,
         2,
         countEvenInSeq3Range(-1, 1, 3, 2));
  printf("countEvenInSeq3Range(%d, %d, %d, %d) = %d\n",
         -5,
         6,
         -5,
         6,
         countEvenInSeq3Range(-5, 6, -5, 6));
  printf(
      "countEvenInSeq3Range(%d, %d, %d, %d) = %d\n", 0, 0, 2, 3, countEvenInSeq3Range(0, 0, 2, 3));
  printf(
      "countEvenInSeq3Range(%d, %d, %d, %d) = %d\n", 0, 2, 3, 1, countEvenInSeq3Range(0, 2, 3, 1));

  return EXIT_SUCCESS;
}
