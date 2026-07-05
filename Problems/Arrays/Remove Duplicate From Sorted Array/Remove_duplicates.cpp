#include <iostream>
#include <vector>

using namespace std;

class RemoveDuplicatesFromSortedArray {
public:

    // Removes duplicates from a sorted array in-place
    // Returns the number of unique elements
    static int removeDuplicates(vector<int>& nums) {

        int n = nums.size();

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
};

int main() {

    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    int uniqueElements = RemoveDuplicatesFromSortedArray::removeDuplicates(nums);

    cout << "Number of Unique Elements: " << uniqueElements << endl;

    cout << "Array After Removing Duplicates: ";

    for (int i = 0; i < uniqueElements; i++) {
        cout << nums[i] << " ";
    }

    cout << endl;

    return 0;
}
