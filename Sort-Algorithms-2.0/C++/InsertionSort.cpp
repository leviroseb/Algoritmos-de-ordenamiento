#include<iostream>
#include<iomanip>
using namespace std;


void insertion(int v[], int n) 
{
  
  for (int i=1; i < n; i++) 
  {
    int key = v[i];
    int j = i-1;
    while (j >= 0 && v[j] > key)
    {
      v[j + 1] = v[j];
      j--;
    }
    v[j+1] = key;
  }
}

void mostrar_arreglo(int v[], int n){
    for(int i = 0; i < n; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int v[] = { 12, 11, 13, 5, 6 }; 
    insertion(v,5);
    mostrar_arreglo(v,5);
    return 0;

}
