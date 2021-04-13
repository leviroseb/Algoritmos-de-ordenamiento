def InsertionSort(lista):
    n = len(lista)

    for i in range(1, n):
        index = lista[i]
        j = i-1

        while j >= 0 and lista[j] > index:
            lista[j+1] = lista[j]
            j -= 1

        lista[j+1] = index

lista = [36, 71, 16, 21, 73, 9, 0, 40, 66, 5]
InsertionSort(lista)
print lista, "\n"
