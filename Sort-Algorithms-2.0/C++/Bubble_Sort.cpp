#include<iostream>
#include<time.h>
#include<fstream>
#include<stdlib.h>
using namespace std;

void BubbleSort(int *v, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(v[j]>v[j+1]){
                int aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            }
        }
    }
}

void crear_arreglo(int *v, int n){
    int c;
    srand(time(NULL));

    for(c=0;c<=n;c++){
        v[c]=rand()%100000;

    }
}

int main()
{
    unsigned t0,t1;
    double time;
    int *v=new int[100000];
    ofstream archivo;
    archivo.open("tiempos_bubble_c.txt",ios::out);
    for(int i=10000;i<=100000;i+=10000){
        crear_arreglo(v,i);
        t0=clock();
        BubbleSort(v,i-1);
        t1=clock();
        time=(double(t1-t0)/CLOCKS_PER_SEC);
        cout<<"Tiempo de ejecucion: "<<time<<endl;
        archivo<<time<<endl;
    }

    archivo.close();
    delete[] v;
    return 0;
}
