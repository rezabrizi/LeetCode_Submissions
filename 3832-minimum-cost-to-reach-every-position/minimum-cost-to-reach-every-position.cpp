class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        vector<int> ans(cost.size());
        int min_so_far = INT_MAX;
        for (int i = 0; i < cost.size(); i++){
            min_so_far = min(min_so_far, cost[i]);
            ans[i] = min_so_far; 
        }
        return ans;
    }
};