import java.util.Scanner; // Importing Scanner class for input
class BubbleSort{ // Start of class
    public static void main(String args[]){ //Start of main function
        Scanner sc = new Scanner(System.in); // Scanner Object
        int n,i,j,temp; // Variable Declaration
        System.out.println("Enter the Size of the Array");
        n=sc.nextInt(); // Input n
        int arr[] = new int[n];
        System.out.println("Enter the integer values ");
        for(i=0; i<n; i++){ // For Inputting values into our Array
            arr[i]=sc.nextInt();
        }
        for(i=0; i<n-1; i++){ // Loop Running for Number of Passes
            for(j=0; j<n-1-i; j++){ // Loop Running for Number of Comparisions
                if(arr[j]>arr[j+1]){ // For Swapping Values
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }
        System.out.println("Array Sorted in Ascending order is ");
        for(i=0; i<n; i++){ // Loop for Displaying the Array
            System.out.print(arr[i]+" ");
        }
    }// End of main function
}// End of class