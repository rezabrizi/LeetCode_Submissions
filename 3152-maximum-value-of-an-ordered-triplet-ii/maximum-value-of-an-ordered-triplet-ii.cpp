class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> pf_max(n, 0), sf_max(n); 
        pf_max[0] = nums[0];
        sf_max[n-1] = nums[n-1];
        for (int i = 1; i < n; i++){
            pf_max[i] = max(pf_max[i-1], nums[i]);
            sf_max[n-1-i] = max(sf_max[n-i], nums[n-1-i]);
        }
        
        long long ans = 0; 
        for (int i = 1; i < n-1; i++){
            ans = max(ans, (long long)(pf_max[i-1]-nums[i])*sf_max[i+1]);
        }
        return ans;
    }
};
