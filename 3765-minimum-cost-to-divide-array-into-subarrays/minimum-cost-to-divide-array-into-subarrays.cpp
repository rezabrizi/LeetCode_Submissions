
#define ll long long 
#define pb push_back

class Solution {
public:
    long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
        int n = nums.size(); 
        vector<ll> pf_costs(n);
        vector<ll> pf_nums(n);

        pf_nums[0] = nums[0];
        for (int i = 1; i < n; i++){
            pf_nums[i] = pf_nums[i-1] + nums[i]; 
        }

        pf_costs[0] = cost[0];
        for (int i = 1; i < n; i++){
            pf_costs[i] = pf_costs[i-1] + cost[i]; 
        }

        vector<vector<ll>> dp(n, vector<ll>(n, -1));
        ll ans = solve(0, 0, k, pf_nums, pf_costs, dp); 
        return ans; 
    }

    ll solve (int l, int r, int k, vector<ll>& pf_nums, vector<ll>& pf_costs, vector<vector<ll>>& dp){
        int n = pf_nums.size(); 
        if (r == n){
            if (l == n) return 0;
            return LLONG_MAX;
        }

        if (dp[l][r] != -1) return dp[l][r];

        ll current_nums_sum = pf_nums[r]; 
        ll current_cost_sum = pf_costs[n-1];

        if (l != 0){
            current_nums_sum = pf_nums[r]-pf_nums[l-1];
            current_cost_sum = pf_costs[n-1] - pf_costs[l-1]; 
        }

        ll curr_cost = (current_nums_sum + k) * current_cost_sum; 

        ll cost_cutted = curr_cost + solve(r+1, r+1, k, pf_nums, pf_costs, dp);
        ll cost_extend = solve(l, r+1, k, pf_nums, pf_costs, dp); 

        return dp[l][r] = min(cost_cutted, cost_extend); 
    }
};