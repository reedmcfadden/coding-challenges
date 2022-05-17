class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = (right - left) / 2 + left;
            // if nums[mid] > nums[right], the lowest value is somewhere to the right
            // else, the lowest value is to the left
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        
        // At this point, both left and right are pointing to the index of the smallest element.
        // Use either to return the minimum element.
        return nums[left];
    }
};
