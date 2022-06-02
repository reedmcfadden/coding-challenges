class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int firstSize = firstList.size();
        int secondSize = secondList.size();
        int firstPtr = 0;
        int secondPtr = 0;
        
        while (firstPtr < firstSize && secondPtr < secondSize) {
            int firstStart = firstList[firstPtr][0];
            int firstEnd = firstList[firstPtr][1];
            int secondStart = secondList[secondPtr][0];
            int secondEnd = secondList[secondPtr][1];
            
            if (firstStart <= secondEnd) {
                int newStart = max(firstStart, secondStart);
                int newEnd = min(firstEnd, secondEnd);
                
                if (newStart <= newEnd) {
                    ans.push_back({ newStart, newEnd });
                }
            }
            
            if (firstEnd > secondEnd) {
                ++secondPtr;
            }
            else {
                ++firstPtr;
            }
        }
        
        return ans;
    }
};
