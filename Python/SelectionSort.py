#Selection Sort

def selectionSort(lista):
    n = len(lista)

    for i in range(0,n-1,1):
        menor = i
        for j in range(i+1,n,1):
            if lista[j] < lista[menor]:
                menor = j

        temp = lista[menor]
 	lista[menor] = lista[i]
	lista[i]=temp


lista = [36, 71, 16, 21, 73, 9, 0, 40, 66, 5]
selectionSort(lista)
print "Lista ordenada:"
print lista, "\n"
