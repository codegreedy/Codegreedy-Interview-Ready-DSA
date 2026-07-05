// Removes duplicates from a sorted array in-place
// Returns the number of unique elements
function removeDuplicates(nums) {

    const n = nums.length;

    // Index of the last unique element
    let indexOfPrevElement = 0;

    // Traverse the array
    for (let j = 1; j < n; j++) {

        // If a new unique element is found
        if (nums[j] !== nums[indexOfPrevElement]) {
            indexOfPrevElement++;
            nums[indexOfPrevElement] = nums[j];
        }
    }

    return indexOfPrevElement + 1;
}

// Driver Code
const nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4];

const uniqueElements = removeDuplicates(nums);

console.log("Number of Unique Elements:", uniqueElements);

process.stdout.write("Array After Removing Duplicates: ");

for (let i = 0; i < uniqueElements; i++) {
    process.stdout.write(nums[i] + " ");
}

console.log();
