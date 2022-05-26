class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        set<pair<int, int>> atlantic;
        set<pair<int, int>> pacific;
        int m = heights.size();
        int n = heights[0].size();
        
        // dfs rows that border an ocean
        for (int i = 0; i < n; ++i) {
            dfs(pacific, heights, 0, i, m, n);
            dfs(atlantic, heights, m - 1, i, m, n);
        }
        // dfs cols that border an ocean
        for (int i = 0; i < m; ++i) {
            dfs(pacific, heights, i, 0, m, n);
            dfs(atlantic, heights, i, n - 1, m, n);
        }
        
        // gather the intersection of atlantic and pacific reachable coordinates
        for (auto p : pacific) {
            if (atlantic.find(p) != atlantic.end()) {
                ans.push_back({ p.first, p.second });
            }
        }
        
//        for (auto p : atlantic) {
//            cout << p.first << ", " << p.second << " | ";
//        }
//        cout << endl;
//        for (auto p : pacific) {
//            cout << p.first << ", " << p.second << " | ";
//        }
//        cout << endl;
        
        
        return ans;
    }
    
    void dfs(set<pair<int, int>>& coords, vector<vector<int>>& heights, int row, int col, int& m, int& n) {
        if (coords.find({row, col}) != coords.end()) {
            return;
        }
        
        coords.insert({ row, col });
        
        if (row + 1 < m && heights[row + 1][col] >= heights[row][col]) {
            dfs(coords, heights, row + 1, col, m, n);
        }
        if (row - 1 >= 0 && heights[row - 1][col] >= heights[row][col]) {
            dfs(coords, heights, row - 1, col, m, n);
        }
        if (col + 1 < n && heights[row][col + 1] >= heights[row][col]) {
            dfs(coords, heights, row, col + 1, m, n);
        }
        if (col - 1 >= 0 && heights[row][col - 1] >= heights[row][col]) {
            dfs(coords, heights, row, col - 1, m, n);
        }
    }
};
