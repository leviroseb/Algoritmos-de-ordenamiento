import os
from time import time

import random

def BubbleSort(V):
    for i in range(0,len(V),1):
        for j in range(0,len(V)-1,1):
            if V[j]>V[j+1]:
                temp = V[j]
                V[j] = V[j+1]
                V[j+1] = temp

def crear_arreglo(A,n):
    for i in range(n):
        A.append(random.randint(1,100000))
        

if __name__=='__main__':
    A=[100000]
    f=open("tiempos_bubble_p.txt","w")
    for i in range(10000,100001,10000):
        crear_arreglo(A,i)
        tiempo_inicial=time()
        BubbleSort(A)
        tiempo_final=time()
        tiempo_ejecucion=tiempo_final-tiempo_inicial
        f.write(str(tiempo_ejecucion))
        print("tiempo de ejecucion: ",tiempo_ejecucion)
    f.close()
        
