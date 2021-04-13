public class MergeSort 
{ 
    void merge(int arr[], int l, int m, int r) 
    { 
	int i,j,k;
        int n1 = m - l + 1; 
        int n2 = r - m; 

        int L[] = new int[n1]; 
        int R[] = new int[n2]; 

        for (int u = 0; u < n1; ++u) 
            L[u] = arr[l + u]; 
        for (int v = 0; v < n2; ++v) 
            R[v] = arr[m + 1 + v]; 

        i = 0; 
	j = 0; 
        k = l; 


        while (i < n1 && j < n2) 
	{ 
            if (L[i] <= R[j]) 
	    { 
                arr[k] = L[i]; 
                i++; 
            } 
            else 
	    { 
                arr[k] = R[j]; 
                j++; 
            } 
            k++; 
        } 

        while (i < n1) 
	{ 
            arr[k] = L[i]; 
            i++; 
            k++; 
        } 

        while (j < n2) 
	{ 
            arr[k] = R[j]; 
            j++; 
            k++; 
        } 
    } 
 
    void mergeSort(int arr[], int l, int r) 
    { 
        if (l < r) { 
            int m = (l + r) / 2;
            mergeSort(arr, l, m); 
            mergeSort(arr, m + 1, r);
            merge(arr, l, m, r); 
        } 
    } 
  
    public void printArray(int arr[]) 
    { 
        int n = arr.length; 
        for (int i = 0; i < n; ++i) 
            System.out.print(arr[i] + " "); 
        System.out.println(); 
    } 

    public static void main(String args[]) 
    { 
        int arr[] = { 12, 11, 13, 5, 6, 7 }; 
        MergeSort ob = new MergeSort(); 
        ob.mergeSort(arr, 0, arr.length - 1); 
        ob.printArray(arr); 
    } 
}
