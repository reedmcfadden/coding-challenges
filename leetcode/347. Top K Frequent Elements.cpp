class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        // create a min heap of pairs of ints
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> counts;
        vector<int> ans;
        
        // count frequency of each number
        for (auto num : nums) {
            counts[num]++;
        }
        
        // add pairs of (frequency, number) to the min heap
        for (auto p : counts) {
            pq.push({ p.second, p.first });
        }
        
        // pop off the min frequency until the size is k
        while (pq.size() > k) {
            pq.pop();
        }
        
        // populate the vector with the remaining most frequent elements
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        } 
        
        return ans;
    }
};
