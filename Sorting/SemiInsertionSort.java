package Sorting;

public class SemiInsertionSort {
    static int[] insertionSort(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j <= i; j++) {
                if (arr[i] < arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        return arr;
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
