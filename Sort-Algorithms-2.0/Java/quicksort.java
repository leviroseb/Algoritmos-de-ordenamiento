class QuickSort{

    int particion(int A[], int p, int r){
        int x=A[r];
        int i=p-1;
        for(int j=p; j<r; j++){
            if(A[j]<=x){
                i=i+1;
                int aux=A[i];
                A[i]=A[j];
                A[j]=aux;
            }
        }

        int aux=A[i+1];
        A[i+1]=A[r];
        A[r]=aux;
        return i+1;

    }

    public void sort(int A[], int p, int r){
        if(p<r){
            int q=particion(A,p,r);
            sort(A,p,q-1);
            sort(A,q+1,r);

        }
    }

    static void printArray(int arr[]) 
    { 
        int n = arr.length; 
        for (int i=0; i<n; ++i) 
            System.out.print(arr[i]+" "); 
        System.out.println(); 
    }

    public static void main(String args[]) 
    { 
        int arr[] = {10, 7, 8, 9, 1, 5}; 
        int n = arr.length; 
  
        QuickSort ob = new QuickSort(); 
        ob.sort(arr, 0, n-1); 
  
        System.out.println("sorted array"); 
        printArray(arr); 
    } 


}

