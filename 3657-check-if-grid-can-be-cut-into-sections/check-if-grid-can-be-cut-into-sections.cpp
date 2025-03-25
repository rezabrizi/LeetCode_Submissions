class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        if (rectangles.size() < 3) return false; 
        bool ans = _check(rectangles, true);
        ans |= _check(rectangles, false);
        return ans;

        
    }

    bool _check(vector<vector<int>>& recs, bool vertical){
        int idx = (vertical) ? 0 : 1;

        sort(recs.begin(), recs.end(), [idx](const auto& r1, const auto& r2){
            return r1[idx] < r2[idx];
        }); 
        
        int splits = 1;
        int last_split = -1; 
        int last_end = recs[0][idx+2];
        for (int i = 1; i < recs.size(); i++){
            if (recs[i][idx] >= last_end){
                splits++;
                
            }
            last_end = max(last_end, recs[i][idx+2]);
            
            if (splits >= 3) return true;
            
        }
        return false; 
    }
};