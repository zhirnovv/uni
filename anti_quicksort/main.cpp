#include <iomanip>
#include <iostream>
#define SIZE 5

using namespace std;

/* swap a[i] and a[j] */
void swap(int arr[], int i, int j) {
  int temp;
  temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void print(const int arr[]) {
  for (int i = 0; i < SIZE; i++) {
    cout << setw(3) << arr[i];
  }
  cout << endl;
}

// Данная функция заполнит массив сначала четными элементами последовательности 1..n в порядке возрастания,
// а потом нечетными в порядке убывания.
// В результате при каждой итерации quicksort левый маркер будет останавливаться на центральном элементе (самом большом), 
// а правый маркер будет останавливаться на первом же элементе.
// Далее левый маркер будет свободно двигаться вперед, пока маркеры пересекутся или встанут на одном месте в (n-i) позиции, что является сигналом окончания сегментирования.
// В результате будет производиться n-i сравнений => аналогично худшему случаю => сложность O(n^2)
int * generateWorstCase(int arr[], int n) {
  int center;

  if (n % 2 == 0) {
    center = n / 2;    
  } else {
    center = (n + 1) / 2;
  }

  arr[center] = n;
  for (int i = 0; i < center; i++) {
    arr[i] = (i + 1) * 2;
    arr[n - 1 - i] = 2*i + 1;
  }

  return arr;
}

void quicksort(int* arr, int leftStart, int rightStart) {
  int left, right, pivot;
  if (leftStart >= rightStart)
    return;

  left = leftStart;
  right = rightStart;

  // pivot selection
  pivot = arr[(leftStart + rightStart) / 2];

  // partition
  while (left <= right) {
    while (arr[left] < pivot)
      left++;
    while (arr[right] > pivot)
      right--;
    if (left <= right) {
      swap(arr, left++, right--);
      print(arr);
    }
  }

  // recursion
  quicksort(arr, leftStart, right);
  quicksort(arr, left, rightStart);
}

int main() {
  int arr[SIZE];
  int * worstCase = generateWorstCase(&arr[SIZE], SIZE);
  quicksort(worstCase, 0, SIZE - 1);
  return 0;
}
