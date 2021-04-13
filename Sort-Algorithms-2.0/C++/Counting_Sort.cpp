#include <algorithm>
#include<iostream>
#include<time.h>
#include<fstream>
#include<stdlib.h>
#include <vector>
using namespace std;

void countSort(vector<int>& arr,int i)
{
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;

    vector<int> count(range), output(arr.size());
    for (int i = 0; i < arr.size(); i++)
        count[arr[i] - min]++;

    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    for (int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}

void printArray(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << "\n";
}


void crear_arreglo(vector<int>& v,int n){
    int c;
    srand(time(NULL));

    for(c=0;c<=n;c++){
        v[c]=rand()%1000000;

    }
}


int main()
{
    unsigned t0,t1;
    double time;
    vector<int> v(1000000);
    ofstream archivo;
    archivo.open("tiempos_counting_c.txt",ios::out);
    for(int i=100000;i<=1000000;i+=100000){
        crear_arreglo(v,i);
        t0=clock();
        countSort(v,i-1);
        t1=clock();
        time=(double(t1-t0)/CLOCKS_PER_SEC);
        cout<<"Tiempo de ejecucion: "<<time<<endl;
        archivo<<time<<endl;
    }
    archivo.close();
    return 0;
}
