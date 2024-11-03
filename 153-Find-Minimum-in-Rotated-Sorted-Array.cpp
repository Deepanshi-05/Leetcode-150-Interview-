class Solution {
public:
    int findMin(vector<int>& nums) {
         int s = 0;
    int e = nums.size() - 1;
    
    // If the array is not rotated at all
    if (nums[s] <= nums[e]) {
        return nums[s];
    }

    while (s < e) {
        int mid = s + (e - s) / 2;
        
        // Check if mid element is the minimum
        if (nums[mid] > nums[mid + 1]) {
            return nums[mid + 1];
        }
        if (nums[mid] < nums[mid - 1]) {
            return nums[mid];
        }
        
        // Decide which side to continue searching
        if (nums[mid] > nums[s]) {
            s = mid + 1; // Minimum is in the right half
        } else {
            e = mid - 1; // Minimum is in the left half
        }
    }
    
    return nums[s];
    }
};