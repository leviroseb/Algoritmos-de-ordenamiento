#include<iostream>
#include<time.h>
#include<fstream>
#include<stdlib.h>
using namespace std;

int particion(int *A, int p, int r)
{
    int x=A[r];
    int i=p-1;
    for(int j=p;j<r;j++){
        if(A[j]<=x){
            i=i+1;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}

void quicksort(int *A, int p, int r)
{
    if(p<r){
        int q=particion(A,p,r);
        quicksort(A,p,q-1);
        quicksort(A,q+1,r);
    }
}


void crear_arreglo(int *A, int n){
    int c;
    srand(time(NULL));

    for(c=0;c<=n;c++){
        A[c]=rand()%1000000;

    }
}


void mostrar_arreglo(int *A, int n){
    for(int i=0;i<n;i++){
        cout<<A[i]<<"-";
    }
}


int main()
{
    unsigned t0,t1;
    double time;
    int *v=new int[1000000];
    ofstream archivo;
    archivo.open("tiempos_quick_c.txt",ios::out);
    for(int i=100000;i<=1000000;i+=100000){
        crear_arreglo(v,i);
        t0=clock();
        quicksort(v,0,i-1);
        t1=clock();
        time=(double(t1-t0)/CLOCKS_PER_SEC);
        cout<<"Tiempo de ejecucion: "<<time<<endl;
        archivo<<time<<endl;
    }

    archivo.close();
    delete[] v;
    return 0;

}
