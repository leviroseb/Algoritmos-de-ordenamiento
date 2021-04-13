import os
import random
from time import time

def seleccion(A,n): 
    i = 0
    j = n - 1
    while(i < j): 
        min = A[i] 
        max = A[i] 
        min_i = i 
        max_i = i 
        for k in range(i, j + 1, 1): 
            if (A[k] > max): 
                max = A[k] 
                max_i = k 
            elif (A[k] < min): 
                min = A[k] 
                min_i = k 
        temp = A[i] 
        A[i] = A[min_i] 
        A[min_i] = temp 
        if (A[min_i] == max): 
            temp = A[j] 
            A[j] = A[min_i] 
            A[min_i] = temp 
        else: 
            temp = A[j] 
            A[j] = A[max_i] 
            A[max_i] = temp 
  
        i += 1
        j -= 1

        
def crear_arreglo(A,n):
    for i in range(n):
        A.append(random.randint(1,1000000))



if __name__=='__main__':
    A=[1000000]
    f=open("tiempos_selection_python.txt","w")
    for i in range(100000,1000001,100000):
        crear_arreglo(A,i)
        tiempo_inicial=time()
        seleccion(A,i)
        tiempo_final=time()
        tiempo_ejecucion=tiempo_final-tiempo_inicial
        f.write(str(tiempo_ejecucion))
        print("tiempo de ejecucion: ",tiempo_ejecucion)
    f.close()


