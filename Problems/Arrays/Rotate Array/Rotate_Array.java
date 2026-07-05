import java.util.Arrays;

public class RotateArray {

    // Swaps two elements in the array
    private static void swap(int[] nums, int start, int end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
    }

    // Reverses the array from start to end
    private static void reverseArray(int[] nums, int start, int end) {
        while (start < end) {
            swap(nums, start, end);
            start++;
            end--;
        }
    }

    // Rotates the array to the right by k positions
    public static void rotate(int[] nums, int k) {
        int n = nums.length;

        // Handle cases where k > n
        k = k % n;

        /*
         * Step 1: Reverse the entire array
         * Step 2: Reverse the first k elements
         * Step 3: Reverse the remaining (n - k) elements
         */

        // Step 1
        reverseArray(nums, 0, n - 1);

        // Step 2
        reverseArray(nums, 0, k - 1);

        // Step 3
        reverseArray(nums, k, n - 1);
    }

    public static void main(String[] args) {

        int[] nums = {1, 2, 3, 4, 5, 6, 7};
        int k = 3;

        rotate(nums, k);

        System.out.println("Rotated Array: " + Arrays.toString(nums));
    }
}
