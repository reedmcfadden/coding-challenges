class Solution {
public:
    // space optimized solution. vector is unnecessary.
    int climbStairs(int n) {
        // handle 1 case
        if (n == 1) {
            return 1;
        }
      
        int prev = 1;
        int curr = 2;
       
        for (int i = 2; i < n; ++i) {
            int temp = curr;
            curr += prev;
            prev = temp;
        }
        
        return curr;
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
