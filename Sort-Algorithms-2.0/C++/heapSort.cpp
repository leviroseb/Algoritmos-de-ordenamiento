#include <iostream>
  using namespace std;
  
  void heapify(int arr[], int n, int i) {
    
    int max = i;
    int izq = 2 * i + 1;
    int der = 2 * i + 2;
  
    if (izq < n && arr[izq] > arr[max])
      max = izq;
  
    if (der < n && arr[der] > arr[max])
      max = der;
  
    
    if (max != i) {
      swap(arr[i], arr[max]);
      heapify(arr, n, max);
    }
  }
  
  
  void heapSort(int arr[], int n) {
    
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
    
    for (int i = n - 1; i >= 0; i--) {
      swap(arr[0], arr[i]);
      heapify(arr, i, 0);
    }
  }
  
  void imprimir(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      cout << arr[i] << " ";
    cout << "\n";
  }
  

  int main() {
    int arr[] = {1, 12, 9, 5, 6, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, n);
  
    cout << "Arreglo ordenado \n";
    imprimir(arr, n);
  }
