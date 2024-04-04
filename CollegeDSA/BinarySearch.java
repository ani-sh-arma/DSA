// Name : Anish Sharma
// Enrollment No. : 202203103510042

import java.util.Scanner;

public class BinarySearch {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] arr = {1,2,3,4,5,6,7,8,9,10};
        
        System.out.println("\n----- Binary Search -----\n");

        System.out.print("Enter the value to search : ");
        int target = scanner.nextInt();
        int result = binarySearch(arr, target);

        if (result == -1) {
            System.out.println("Value not found.\n");
        }
        else{
            System.out.println("Value found at index : " + result + "\n");
        }

        scanner.close();
    }

    private static int binarySearch(int[] arr, int target) {
        int left = 0;
        int right = arr.length - 1;

        while (left <= right) {
            int mid = left + (right - left)/2;

            if (arr[mid] == target) {
                return mid;
            }
            else if (arr[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return -1;
    }
}
