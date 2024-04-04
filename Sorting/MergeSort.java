
package Sorting;

public class MergeSort {
    static void merge(int[] arr, int low, int mid, int high) {
        int temp[] = new int[arr.length];
        int index = 0;
        int left = low;
        int right = mid+1;

        while (left <= mid && right <= high) {
            if (arr[left] < arr[right]) {
                temp[index] = arr[left];
                left++;
            }
            else{
                temp[index] = arr[right];
                right++;
            }
            index++;
        }

        while (left <= mid) {
            temp[index++] = arr[left++];
        }
        while (right <= high) {
            temp[index++] = arr[right++];
        }
        
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    static void mergeSort(int[] arr, int low, int high) {
        if (low >= high) return;
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid +1 , high);
        merge(arr, low, mid, high);
    }

    public static void main(String[] args) {
        int[] arr = {1,5,8,6,8,62,2,59,52,5,98,95,6,49,0,-65,-1};
        
        System.out.println("\n---Merge Sort---\n");
        System.out.print("Array  : ");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
        mergeSort(arr, 0, arr.length-1);
        System.out.print("Sorted : ");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}