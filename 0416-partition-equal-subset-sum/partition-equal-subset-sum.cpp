class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0); 
        if (total_sum % 2) return false;
        int target = total_sum / 2;
        vector <bool> dp(target+1); 
        dp[0] = true; 

        for (const auto& num: nums){
            for (int i = target; i >= num; i--){
                dp[i] = (dp[i] || dp[i-num]);
            }
        }

        return dp[target];
    }
};