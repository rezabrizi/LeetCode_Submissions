class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int last_zero_cnt = 0, curr_zero_cnt = 0, one_cnt = 0, convertedOne = 0; 
        for (int i = 0; i < s.size(); i++){
            if(s[i] == '0') curr_zero_cnt++; 
            else{
                if(curr_zero_cnt != 0){
                    last_zero_cnt = curr_zero_cnt;  
                }
                curr_zero_cnt = 0; 
                one_cnt++; 
            }
            convertedOne = max(convertedOne, curr_zero_cnt + last_zero_cnt);
        }
        if (convertedOne == curr_zero_cnt  || convertedOne == last_zero_cnt) return one_cnt; 
        return one_cnt + convertedOne;
    }
};

