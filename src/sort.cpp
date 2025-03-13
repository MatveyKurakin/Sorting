#include "sort.h"

#include <iostream>
void bubble_sort(double* ar, int n) {
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < n - i - 1; j++) {
      if (ar[j] > ar[j + 1]) {
        const double tmp = ar[j + 1];
        ar[j + 1] = ar[j];
        ar[j] = tmp;
      }
    }
}

void insertion_sort(double* ar, int n) {
  double a;
  int pos_a;
  for (int i = 1; i < n; i++) {
    a = ar[i];
    pos_a = i - 1;
    while (pos_a >= 0 && ar[pos_a] > a) {
      ar[pos_a + 1] = ar[pos_a];
      pos_a--;
    }
    ar[pos_a + 1] = a;
  }
}

void selection_sort(double* ar, int n) {
  double min_ar;
  int pos_min_ar;
  for (int i = 0; i < n; i++) {
    min_ar = ar[i];
    pos_min_ar = i;
    for (int j = i; j < n; j++) {
      if (min_ar > ar[j]) {
        min_ar = ar[j];
        pos_min_ar = j;
      }
    }
    const double tmp = ar[i];
    ar[i] = ar[pos_min_ar];
    ar[pos_min_ar] = tmp;
  }
}

void linMerge(double* ar, int start, int mid, int end) {
  int i = start;
  int j = mid;
  double* new_ar = (double*)malloc((end - start) * sizeof(double));
  for (int l = 0; l < end - start; l++) {
    if ((i < mid) && (j < end)) {
      if (ar[i] <= ar[j]) {
        new_ar[l] = ar[i++];
      } else {
        new_ar[l] = ar[j++];
      }
    } else {
      if (i == mid) {
        new_ar[l] = ar[j++];
      } else {
        new_ar[l] = ar[i++];
      }
    }
  }
  for (int i = start; i < end; i++) {
    ar[i] = new_ar[i - start];
  }
  free(new_ar);
}

void merge_sort(double* ar, int n) {
  // merge(ar, 0, n);
  int start = 0, end = 2;
  int delta = 2;
  while (delta <= n + n) {
    int mid = (start + end) / 2;
    if (end > n)
      linMerge(ar, start, mid, n);
    else
      linMerge(ar, start, mid, end);
    if (end >= n) {
      delta *= 2;
      start = 0;
      end = delta;
    } else {
      start += delta;
      end += delta;
    }
  }
}
