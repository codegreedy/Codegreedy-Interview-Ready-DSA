#include <iostream>
#include <vector>

using namespace std;

class RotateArray {
public:

    // Swaps two elements in the array
    static void swapElements(vector<int>& nums, int start, int end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
    }

    // Reverses the array from start to end
    static void reverseArray(vector<int>& nums, int start, int end) {
        while (start < end) {
            swapElements(nums, start, end);
            start++;
            end--;
        }
    }

    // Rotates the array to the right by k positions
    static void rotate(vector<int>& nums, int k) {
        int n = nums.size();

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
};

int main() {

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    RotateArray::rotate(nums, k);

    cout << "Rotated Array: ";

    for (int num : nums) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}
