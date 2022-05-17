class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = -1;
        int n = nums.size();
        int lo = 0;
        int hi = n - 1;
        
        // old linear search to find lowest val
        // for (int i = 1; i < n; ++i) {
        //     if (nums[i] < nums[i - 1]) {
        //         offset = i;
        //         break;
        //     }
        // }
        
        // search for lowest element. lo will be the offset for the rotated array.
        while (lo < hi) {
            int mid = (hi - lo) / 2 + lo;
            if (nums[mid] > nums[hi]) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }
        
        int offset = lo;
        lo = 0;
        hi = n - 1;
        // use binary search to search the rotated array using the offset
        while (lo <= hi) {
            int mid = (hi - lo) / 2 + lo;
            int offsetMid = (mid + offset) % nums.size();
            
            if (nums[offsetMid] < target) {
                lo = mid + 1;
            }
            else if (nums[offsetMid] > target) {
                hi = mid - 1;
            }
            else {
                ans = offsetMid;
                break;
            }
        }
        
        return ans;
    }
};
