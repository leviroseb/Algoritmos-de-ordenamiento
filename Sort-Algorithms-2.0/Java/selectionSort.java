class SelectionSort {

    public void selection(int A[], int n){
        
        int i=0;
        int j=n-1;
        while(i<j){
            int min=A[i];
            int max=A[i];
            int min_i=i;
            int max_i=i;
            for(int k=i;k<=j;k++){
                if(A[k]>max){
                    max=A[k];
                    max_i=k;
                }
                else if (A[k]<min){
                    min=A[k];
                    min_i=k;
                }
            }
        
        

            int aux=A[i];
            A[i]=A[min_i];
            A[min_i]=aux;
            if(A[min_i]==max){
                int aux2 = A[j];
                A[j]=A[min_i];
                A[min_i]=aux2;
            }
            else{
                int aux3=A[j];
                A[j]=A[max_i];
                A[max_i]=aux3;
            }
            i=i+1;
            j=j-1;
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
  
        SelectionSort ob = new SelectionSort(); 
        ob.selection(arr,n); 
  
        System.out.println("sorted array"); 
        printArray(arr); 
    } 
    
}
