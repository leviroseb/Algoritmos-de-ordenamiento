#include<iostream>
#include<algorithm>
#include<time.h>
using namespace std;

//intercalacion
void intercala(int* A, int p, int q, int r){
    int i,j;
    int *B=new int[r-p+1];
    for(i=p;i<=q;i++){
        B[i]=A[i];
    }

    for(j=q+1;j<=r;j++){
        B[r+q+1-j]=A[j];
    }
    i=p;
    j=r;
    for(int k=p;k<=r;k++){
        if(B[i]<=B[j]){
            A[k]=B[i];
            i=i+1;
        }
        else{
            A[k]=B[j];
            j=j-1;
        }
    }

}

void mergesort(int *A,int p, int r){
    if(p<r){
        int q=(p+r)/2;
        mergesort(A,p,q);
        mergesort(A,q+1,r);
        intercala(A,p,q,r);
    }
}


void crear_arreglo(int *A, int n){
    int num,c;
    srand(time(NULL));

    for(c=1;c<=n;c++){
        num=1+rand()%(10000-1);
        A[c]=num;

    }
}


int main()
{
    
    unsigned t0,t1;
    double time;
    for(int i=1000;i<=100000;i=i+1000){
        int *A=new int[i];
        crear_arreglo(A,i);
        t0=clock();
        mergesort(A, 0,i-1);
        t1=clock();
        time = (double(t1-t0)/CLOCKS_PER_SEC*1000000);
        std::cout << "Tiempo: " << time << std::endl;
        delete[] A;
    }
    system("pause");
    return 0;
}
