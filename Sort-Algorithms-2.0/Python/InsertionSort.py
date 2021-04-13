def InsertionSort(lista,n):
    
    for i in range(1, n):
        key = lista[i]
        j = i-1

        while j >= 0 and lista[j] > key:
            lista[j+1] = lista[j]
            j -= 1

        lista[j+1] = key

lista = [36, 71, 16, 21, 73, 9, 0, 40, 66, 5]
n = len(lista)
InsertionSort(lista,n)
print lista, "\n"
