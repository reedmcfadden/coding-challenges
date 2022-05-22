class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        // todo. major improve can be made by removing this set for tracking visiting coordinates
        // and simply setting each visited '1' to a '0', so that they will no longer inrease the
        // island total
        set<pair<int, int>> visited;
        int n = grid.size();
        int m = grid[0].size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (visited.find({ i, j }) != visited.end()) {
                    continue;
                }
                
                visited.insert({ i, j });
                
                if (grid[i][j] == '0') {
                    continue;
                }
                
                ++ans;
                stack<pair<int, int>> toVisit;
                toVisit.push({ i, j });
                
                while (!toVisit.empty()) {
                    pair<int, int> current = toVisit.top();
                    toVisit.pop();
                    
                    int row = current.first;
                    int col = current.second;
                    
                    visited.insert({ row, col });
                    
                    if (grid[row][col] == '0') {
                        continue;
                    }
                    
                    if (row + 1 < n && visited.find({ row + 1, col }) == visited.end()) {
                        toVisit.push({ row + 1, col });
                    }
                    if (row - 1 >= 0 && visited.find({ row - 1, col }) == visited.end()) {
                        toVisit.push({ row - 1, col });
                    }
                    if (col + 1 < m && visited.find({ row, col + 1 }) == visited.end()) {
                        toVisit.push({ row, col + 1 });
                    }
                    if (col - 1 >= 0 && visited.find({ row, col - 1 }) == visited.end()) {
                        toVisit.push({ row, col - 1 });
                    }
                }
            }
        }
        
        return ans;
    }
};
