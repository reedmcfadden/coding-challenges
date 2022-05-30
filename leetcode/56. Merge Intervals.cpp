class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // handle empty case
        if (intervals.empty()) {
            return intervals;
        }
        
        int n = intervals.size();
        vector<vector<int>> ans;
        
        // sort the intervals by begin to simplify merging
        sort(intervals.begin(), intervals.end());
        
        // add the first interval to the answer by default
        ans.push_back({ intervals[0][0], intervals[0][1] });
        
        for (int i = 1; i < n; ++i) {
            int lastEnd = ans[ans.size() - 1][1];
            int currentBegin = intervals[i][0];
            int currentEnd = intervals[i][1];
            
            // merge
            if (currentBegin <= lastEnd) {
                ans[ans.size() - 1][1] = max(lastEnd, currentEnd);
            }
            // add new interval
            else {
                ans.push_back({ currentBegin, currentEnd });
            }
        }
        
        return ans;
    }
};
