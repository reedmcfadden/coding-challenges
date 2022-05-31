class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int ans = 0;
        
        sort(intervals.begin(), intervals.end());
        
        int prevEnd = intervals[0][1];
        for (int i = 1; i < n; ++i) {
            int currentStart = intervals[i][0];
            int currentEnd = intervals[i][1];
            
            // if there is overlap, increment ans and set prevEnd to the smaller of the two ends
            // else, there is no overlap. set prevEnd to the currentEnd
            if (currentStart < prevEnd) {
                ++ans;
                prevEnd = min(currentEnd, prevEnd);
            }
            else {
                prevEnd = currentEnd;
            }
        }
        
        return ans;
    }
};
