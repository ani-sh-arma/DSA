import java.util.Scanner;

public class SequentialSearch {

    static int sequentialSearch(int[] arr, int target) {
        for (int i = 0; i < arr.length; i++) {
            if (target == arr[i]) {
                return i;
            }
        }
        return -1;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] arr = {1,52,5,86,63,5,9,2,56,8,63,58,96,85,96,8,5,5,8,55,88,5};
        
        System.out.println("\n----- Sequential Search -----\n");
        System.out.print("Enter the value to search : ");
        int target = scanner.nextInt();
        int result = sequentialSearch(arr, target);

        if (result == -1) {
            System.out.println("Value not found.\n");
        }
        else{
            System.out.println("Value found at index : " + result + "\n");
        }

        scanner.close();
    }
}