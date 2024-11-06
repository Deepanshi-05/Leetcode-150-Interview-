class Solution {
public:
    // Function to find the first occurrence of the target
    int findFirstPosition(const vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int first = -1; // Default to -1 if not found
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                first = mid;     // Update first position
                right = mid - 1; // Continue to search in the left half
            } else if (nums[mid] < target) {
                left = mid + 1; // Move to the right half
            } else {
                right = mid - 1; // Move to the left half
            }
        }
        return first;
    }

    // Function to find the last occurrence of the target
    int findLastPosition(const vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int last = -1; // Default to -1 if not found
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                last = mid;     // Update last position
                left = mid + 1; // Continue to search in the right half
            } else if (nums[mid] < target) {
                left = mid + 1; // Move to the right half
            } else {
                right = mid - 1; // Move to the left half
            }
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirstPosition(nums, target);
        int last = findLastPosition(nums, target);
        return {first, last};
    }
};