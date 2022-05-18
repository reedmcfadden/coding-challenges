class Solution {
public:
    // space optimized solution. vector is unnecessary.
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
      
        int prev1 = 1;
        int prev2 = 2;
       
        for (int i = 2; i < n; ++i) {
            int temp = prev2;
            prev2 += prev1;
            prev1 = temp;
        }
        
        return prev2;
    }
  
       // dp solution using vector
//     int climbStairs(int n) {
//         vector<int> totals{ 1, 2 };
        
//         for (int i = 2; i < n; ++i) {
//             totals.push_back(totals[i - 1] + totals[i - 2]);
//         }
        
//         return totals[n - 1];
//     }
};
