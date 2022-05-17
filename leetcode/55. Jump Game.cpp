class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = 0;
        int n = nums.size();
        
        for (int i = 0; i < n && i <= maxJump; ++i) {
            maxJump = max(maxJump, i + nums[i]);
            
            if (maxJump >= n - 1) {
                return true;
            }
        }
        return false;
    }
};
