#include <stdlib.h>

#include <iostream>

#include "function.h"
#include "sort.h"

void (*my_sort)(double*, int);

int main(int argc, char** argv) {
  setlocale(LC_ALL, "Russian");
  int n_start, n_end, step;
  if (argc == 1) {
    printf("NO");
    return 0;
  }
  if (argc == 2) {
    const char* bubble_sort_name = "bubble_sort";
    const char* insertion_sort_name = "insertion_sort";
    const char* selection_sort_name = "selection_sort";
    const char* merge_sort_name = "merge_sort";

    if (checkString(argv[1], bubble_sort_name)) {
      my_sort = bubble_sort;
      n_start = 1000;
      n_end = 100000;
      step = 9900;
    } else if (checkString(argv[1], insertion_sort_name)) {
      my_sort = insertion_sort;
      n_start = 1000;
      n_end = 100000;
      step = 9900;
    } else if (checkString(argv[1], selection_sort_name)) {
      my_sort = selection_sort;
      n_start = 1000;
      n_end = 100000;
      step = 9900;
    } else if (checkString(argv[1], merge_sort_name)) {
      my_sort = merge_sort;
      n_start = 10000;
      n_end = 10000000;
      step = 999000;
    } else {
      printf("NO");
      return 0;
    }
  }
  double* ar = (double*)malloc(n_end * sizeof(double));
  for (int i = 0; i < n_end; i++) {
    ar[i] = (rand() % 2001) / 10.0 - 100;
  }
  for (int seed = n_start; seed <= n_end; seed += step) {
    double* cop_ar = copy_ar(ar, seed);
    unsigned int t1 = clock();
    my_sort(cop_ar, seed);
    unsigned int t2 = clock();
    if (check(cop_ar, seed))
      printf("%d ; %d ; 1\n", seed, t2 - t1);
    else
      printf("%d ; %d ; 0\n", seed, t2 - t1);
  }
  free(ar);
  return 0;
}