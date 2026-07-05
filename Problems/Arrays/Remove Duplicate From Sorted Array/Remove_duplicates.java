import java.util.Arrays;

public class RemoveDuplicatesFromSortedArray {

    // Removes duplicates from a sorted array in-place
    // Returns the number of unique elements
    public static int removeDuplicates(int[] nums) {

        int n = nums.length;

        // Index of the last unique element
        int indexOfPrevElement = 0;

        // Traverse the array
        for (int j = 1; j < n; j++) {

            // If a new unique element is found
            if (nums[j] != nums[indexOfPrevElement]) {
                indexOfPrevElement++;
                nums[indexOfPrevElement] = nums[j];
            }
        }

        return indexOfPrevElement + 1;
    }

    public static void main(String[] args) {

        int[] nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

        int uniqueElements = removeDuplicates(nums);

        System.out.println("Number of Unique Elements: " + uniqueElements);

        System.out.print("Array After Removing Duplicates: ");

        for (int i = 0; i < uniqueElements; i++) {
            System.out.print(nums[i] + " ");
        }

        System.out.println();
    }
}
