class Solution {
public:
    int countOdds(int low, int high) {
        int ans = 0;
        
        // since we know that odds occur every other number, subtract high 
        // and low and divide by two.
        ans += (high - low) / 2;
        
        // if either low or high is odd, increment ans. 
        // this accounts for the leading or trailing odd that was not calculated above.
        if (low % 2 == 1 || high % 2 == 1) {
            ++ans;
        }
        
        return ans;
    }
};
