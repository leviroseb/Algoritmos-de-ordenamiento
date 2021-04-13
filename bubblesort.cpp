#include<iostream>
#include<iomanip>
using namespace std;

void crear_arreglo(int v[], int n){
    for(int i=0;i<n;i++){
        cout<<"ingrese un numero: ";
        cin>>v[i];
    }
}

void mostrar_arreglo(int v[], int n){
    for(int i=0;i<n;i++){
        cout<<v[i]<<setw(3);
    }
    cout<<endl;
}

void burbuja(int v[], int n){
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

int main()
{
    int v[30],n;
    cout<<"Numero de elementos del vector: "<<endl;
    cin>>n;
    crear_arreglo(v,n);
    mostrar_arreglo(v,n);
    burbuja(v,n);
    cout<<"El arreglo ordenado es: "<<endl;
    mostrar_arreglo(v,n);
    return 0;
}