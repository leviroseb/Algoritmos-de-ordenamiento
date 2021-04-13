#include <iostream>
using namespace std;

void countSort(int array[], int size) {
  
  int *output=new int[size];
  int *count=new int[size+1];
  int max = array[0];

  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }

  // Inicializa un arreglo con todos los elementos en 0
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  //almacena la cuenta de cada elemento
  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }

  
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  for (int i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  
  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}


void imprimir(int array[], int size) {
  for (int i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}


int main() {
  int array[] = {4, 2, 2, 8, 3, 3, 1,34,1,67,345,1,345,2,4,20,34,99};
  int n = sizeof(array) / sizeof(array[0]);
  countSort(array, n);
  imprimir(array, n);
}
