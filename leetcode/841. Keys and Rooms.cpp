class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int numVisited = 0;
        vector<bool> visited(rooms.size(), false);  // keep track of visited room
        stack<int> next;                            // visit room in depth first order
        next.push(0);                               // start with room 0, because unlocked
        
        // go until all possible rooms visited
        while (!next.empty()) {
            int current = next.top();
            next.pop();
            
            if (visited[current]) {
                continue;
            }
            
            visited[current] = true;    // mark room as visited
            ++numVisited;
            
            for (int key : rooms[current]) {
                next.push(key);
            }
        }
        
        return numVisited == rooms.size();
    }
};
