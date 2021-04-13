#include<iostream>
#include<iomanip>
#include<time.h>
#include<stdlib.h>
#include<fstream>

using namespace std;


void crear_arreglo(int *A, int n){
    int c;
    srand(time(NULL));

    for(c=0;c<=n;c++){
        A[c]=rand()%1000000;

    }
}


void mostrar_arreglo(int v[], int n){
    for(int i=0;i<n;i++){
        cout<<v[i]<<setw(3);
    }
}

void selection(int* A, int n)
{
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        int min = A[i], max = A[i];
        int min_i = i, max_i = i;
        for (int k = i; k <= j; k++)  {
            if (A[k] > max) {
                max = A[k];
                max_i = k;
            } else if (A[k] < min) {
                min = A[k];
                min_i = k;
            }
        }

        swap(A[i], A[min_i]);
        if (A[min_i] == max)
            swap(A[j], A[min_i]);
        else
            swap(A[j], A[max_i]);
    }
}

int main()
{
    unsigned t0,t1;
    double time;
    int *v=new int[1000000];
    ofstream archivo;
    archivo.open("tiempos_selection_c2.txt",ios::out);
    for(int i=100000;i<=1000000;i+=100000){
        crear_arreglo(v,i);
        t0=clock();
        selection(v,i);
        t1=clock();
        time=(double(t1-t0)/CLOCKS_PER_SEC);
        cout<<"Tiempo de ejecucion: "<<time<<endl;
        archivo<<time<<endl;
    }

    archivo.close();
    delete[] v;
    return 0;

}
