#include <gtest.h>

#include <algorithm>
#include <cstdlib>

#include "function.h"
#include "sort.h"

double *generateRandomArray(int size)
{
  if (size <= 0)
    return nullptr;

  double *arr = new double[size];
  for (int i = 0; i < size; ++i)
  {
    arr[i] = static_cast<double>(std::rand()) / RAND_MAX * 1000.0 - 500.0;
  }
  return arr;
}

template <typename SortFunction>
void testSortFunction(SortFunction sortFunc, int size)
{
  double *source = generateRandomArray(size);
  double *expected = new double[size];
  double *actual = new double[size];

  // Подготовка данных
  std::copy(source, source + size, expected);
  std::sort(expected, expected + size);

  std::copy(source, source + size, actual);
  sortFunc(actual, size);

  for (int i = 0; i < size; ++i)
  {
    ASSERT_NEAR(actual[i], expected[i], 1e-9) << "Mismatch at position " << i;
  }

  // Очистка памяти
  delete[] source;
  delete[] expected;
  delete[] actual;
}

TEST(SortTest, BubbleSort) { testSortFunction(bubble_sort, 100000); }

TEST(SortTest, InsertionSort) { testSortFunction(insertion_sort, 100000); }

TEST(SortTest, SelectionSort) { testSortFunction(selection_sort, 100000); }

TEST(SortTest, MergeSort) { testSortFunction(merge_sort, 100000); }

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
