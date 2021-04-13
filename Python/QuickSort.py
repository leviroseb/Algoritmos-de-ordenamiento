#QuickSort

def particion(lista, izq, der):
	pivote = lista[der]
	indice = izq-1

	for i in range(izq, der,1):		
		if lista[i] < pivote:
			indice += 1
			temp = lista[indice]
                	lista[indice] = lista[i]
                	lista[i] = temp

	temp = lista[indice+1]
 	lista[indice+1] = lista[der]
	lista[der]=temp
	return indice+1

def quicksort(lista, izq, der):
    if izq < der:
    	pi= particion(lista, izq, der)
    	quicksort(lista, izq, pi-1)
    	quicksort(lista, pi+1, der)


lista = [36, 71, 16, 21, 73, 9, 0, 40, 66, 5]

quicksort(lista, 0, len(lista)-1)

print "Lista ordenada:"
print lista, "\n"
