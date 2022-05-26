class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // must have at least n - 1 connections to be able to connect all nodes
        // if there are less connections than that, return -1
        if (connections.size() < n - 1) {
            return - 1;
        }
        
        vector<vector<int>> adjList(n);
        
        // populate adjacency list
        for (auto v : connections) {
            int c1 = v[0];
            int c2 = v[1];
            
            adjList[c1].push_back(c2);
            adjList[c2].push_back(c1);
        }
        
        vector<bool> visited(n, false);
        int networks = -1;   // start at -1. (1 network will need 0 moved connections)
        
        // iterate and dfs to discover the number of networks
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(adjList, visited, i);
                ++networks;
            }
        }
        
        return networks;
    }
    
    void dfs(vector<vector<int>>& adjList, vector<bool>& visited, int current) {
        if (visited[current]) {
            return;
        }
        
        visited[current] = true;
        for (auto n : adjList[current]) {
            dfs(adjList, visited, n);
        }
    }
};
