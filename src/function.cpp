#include "function.h"

double* copy_ar(double* ar, int new_n) {
  double* new_ar = (double*)malloc(new_n * sizeof(double));
  for (int i = 0; i < new_n; i++) {
    new_ar[i] = ar[i];
  }
  return new_ar;
}

char* createMyString(char s[]) {
  int ind = 0;
  while (s[ind] != '\0') {
    ind++;
  }
  char* a = (char*)malloc(ind);
  for (int i = 0; i < ind; i++) {
    a[i] = s[i];
  }
  return a;
}

bool checkString(char* s1, const char* s2) {
  int i = 0;
  bool f = 1;
  while (65 <= (int)s1[i] && (int)s1[i] <= 122 && 65 <= (int)s2[i] && (int)s2[i] <= 122) {
    if (s1[i] != s2[i]) {
      f = 0;
      break;
    }
    i++;
  }
  if (f) return true;
  return false;
}

bool check(double* ar, int n) {
  for (int i = 0; i < n - 1; i++)
    if (ar[i + 1] < ar[i]) return false;
  return true;
}