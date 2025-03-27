class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        pair<int, int> dom = {-1, -1}; 
        unordered_map<int, int> fq; 
        int f1 = 0; 
        
        for (int num: nums){
            fq[num] ++;
            if (dom.first < fq[num]){
                dom = {fq[num], num};
            }
        }

        int f2 = dom.first; 

        int n = nums.size(); 
        for (int i = 0; i < n-1; i++){
            if (nums[i] == dom.second){
                f1++; 
                f2--;
                if (f1*2 > i+1 && f2*2 > n-i-1 ) return i; 
            }
        }
        return -1;
        
    }
};
