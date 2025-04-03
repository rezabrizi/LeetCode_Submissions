class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> pf_max(n, 0), sf_min(n, INT_MAX); 
        pf_max[0] = nums[0]; 
        sf_min[n-1] = nums[n-1]; 

        for (int i = 1; i < n; i++){
            pf_max[i] = max(nums[i], pf_max[i-1]); 
            sf_min[n-1-i] = min(nums[n-i-1], sf_min[n-i]);
        }

        int booty = 0; 

        for (int i = 1; i < n-1; i++){
            if (nums[i-1] < nums[i] && nums[i] < nums[i+1])
                booty ++;
            if (pf_max[i-1] < nums[i] && nums[i] < sf_min[i+1]) 
                booty ++;
        }

        return booty;
    }
};