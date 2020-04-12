#include <fstream>
#include <iostream>
#define SIZE 5

using namespace std;

void swap(int* arr, int i, int j) {
  int temp;
  temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

// Данная функция будет заполнять массив в порядке возрастания и менять последний элемент i с центром вырезки массива i/2.
// В результате получится, что в центре будет самый большой элемент.
// При каждом сегментировании левый маркер дойдет до опорного элемента, а правый остановится на последнем элементы.
// После замены левый маркер продолжит движение до конца (тк опорный элемент в конце), в результате чего он окажется дальше правого маркера,
// что укажет на окончание сегментирования.
// Оставшаяся левее опорного элемента часть массива будет также иметь наибольший элемент в центре.
// Таким образом, алгоритм проведет (n-i-1) вложенных операций, что сходится к O(n^2)
void generateWorstCase(int* arr, int n) {
  for (int i = 0; i < n; i++) {
    arr[i] = i + 1;
    swap(arr, i/2, i);
  }
}

/* void quicksort(int* arr, int leftStart, int rightStart) { */
/*   int left, right, pivot; */
/*   if (leftStart >= rightStart) */
/*     return; */

/*   left = leftStart; */
/*   right = rightStart; */

/*   pivot = arr[(leftStart + rightStart) / 2]; */

/*   while (left <= right) { */
/*     while (arr[left] < pivot) */
/*       left++; */
/*     while (arr[right] > pivot) */
/*       right--; */
/*     if (left <= right) { */
/*       swap(arr, left++, right--); */
/*       print(arr); */
/*     } */
/*   } */

/*   // recursion */
/*   quicksort(arr, leftStart, right); */
/*   quicksort(arr, left, rightStart); */
/* } */

int main() {
  ifstream infile("in.txt");
  ofstream outfile("out.txt");

  if (!infile.good()) {
    cout << "Error: failed to read in.txt" << endl;
    return 0;
  }

  int size;
  infile >> size; 

  int arr[size];
  generateWorstCase(arr, size);

  for (int i = 0; i < size; i++) {
    outfile << arr[i] << ' ';
  }

  return 0;
}
