class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        bool inserted = false;
        vector<vector<int>> ans;
        
        for (int i = 0; i < n; ++i) {
            int currentStart = intervals[i][0];
            int currentEnd = intervals[i][1];
            
            if (currentEnd < newInterval[0]) {
                ans.push_back({ currentStart, currentEnd });
            }
            else if (currentStart > newInterval[1]) {
                if (!inserted) {
                    ans.push_back(newInterval);
                    inserted = true;
                }
                ans.push_back({ currentStart, currentEnd });
            }
            else {
                newInterval[0] = min(newInterval[0], currentStart);
                newInterval[1] = max(newInterval[1], currentEnd);
            }
        }
        
        // if the new interval has not been added yet, add it
        if (!inserted) {
            ans.push_back(newInterval);
        }
        
        return ans;
    }
};
