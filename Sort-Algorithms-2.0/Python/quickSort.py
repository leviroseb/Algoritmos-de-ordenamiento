#quickSort
import os
from time import time

import random

def particion(A,p,r):
    x=A[r]
    i=p-1
    for j in range(p,r):
        if A[j]<=x:
            i=i+1
            aux=A[i]
            A[i]=A[j]
            A[j]=aux
    aux=A[i+1]
    A[i+1]=A[r]
    A[r]=aux
    return i+1

def quicksort(A,p,r):
    if p<r:
        q=particion(A,p,r)
        quicksort(A,p,q-1)
        quicksort(A,q+1,r)


def imprimir(lista):
    for i in range(len(lista)):
        print(lista[i],end=" ")
    print()

def crear_arreglo(A,n):
    for i in range(n):
        A.append(random.randint(1,1000000))
        

if __name__=='__main__':
    A=[1000000]
    f=open("tiempos_quick_python.txt","w")
    for i in range(100000,1000001,100000):
        crear_arreglo(A,i)
        tiempo_inicial=time()
        quicksort(A,0,len(A)-1)
        tiempo_final=time()
        tiempo_ejecucion=tiempo_final-tiempo_inicial
        f.write(str(tiempo_ejecucion))
        print("tiempo de ejecucion: ",tiempo_ejecucion)
    f.close()
        
