// Name : Anish Sharma
// Enrollment No. : 202203103510042

package Sorting;

public class InsertionSort {
    static void insertionSort(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            int j = i;
            while (j > 0 && arr[j-1] > arr[j]) {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                j--;
            }
        }
    }
    public static void main(String[] args) {
        int[] arr = {1,5,8,6,8,62,2,59,52,5,98,95,6,49,0,-65,-1};
        
        System.out.println("\n---Insertion Sort---\n");
        System.out.print("Array  : ");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
        insertionSort(arr);

        System.out.print("Sorted : ");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}