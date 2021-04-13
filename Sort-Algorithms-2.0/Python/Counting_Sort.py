import os
from time import time
import random

def CountingSort(arr): 
    max_element = int(max(arr)) 
    min_element = int(min(arr)) 
    range_of_elements = max_element - min_element + 1

    count_arr = [0 for _ in range(range_of_elements)] 
    output_arr = [0 for _ in range(len(arr))] 
  
    for i in range(0, len(arr)): 
        count_arr[arr[i]-min_element] += 1
  
    for i in range(1, len(count_arr)): 
        count_arr[i] += count_arr[i-1] 
  
    for i in range(len(arr)-1, -1, -1): 
        output_arr[count_arr[arr[i] - min_element] - 1] = arr[i] 
        count_arr[arr[i] - min_element] -= 1
  
    for i in range(0, len(arr)): 
        arr[i] = output_arr[i] 
  
    return arr 


def crear_arreglo(A,n):
    for i in range(n):
        A.append(random.randint(1,1000000))


if __name__=='__main__':
    A=[1000000]
    f=open("tiempos_counting_p.txt","w")
    for i in range(100000,1000001,100000):
        crear_arreglo(A,i)
        tiempo_inicial=time()
        CountingSort(A)
        tiempo_final=time()
        tiempo_ejecucion=tiempo_final-tiempo_inicial
        f.write(str(tiempo_ejecucion))
        print("tiempo de ejecucion: ",tiempo_ejecucion)
    f.close()
