def BubbleSort(V):
    for i in range(0,len(V),1):
        for j in range(0,len(V)-1,1):
            if V[j]>V[j+1]:
                temp = V[j]
                V[j] = V[j+1]
                V[j+1] = temp

V = [54,26,93,17,77,31,44,55,20]
BubbleSort(V)
print(V)

