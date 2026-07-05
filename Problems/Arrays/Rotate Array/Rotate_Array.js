// Swaps two elements in the array
function swap(nums, start, end) {
    const temp = nums[start];
    nums[start] = nums[end];
    nums[end] = temp;
}

// Reverses the array from start to end
function reverseArray(nums, start, end) {
    while (start < end) {
        swap(nums, start, end);
        start++;
        end--;
    }
}

// Rotates the array to the right by k positions
function rotate(nums, k) {
    const n = nums.length;

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

// Driver Code
const nums = [1, 2, 3, 4, 5, 6, 7];
const k = 3;

rotate(nums, k);

console.log("Rotated Array:", nums);
