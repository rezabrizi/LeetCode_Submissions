class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        vector<int> b2d(bulbs.size()); 

        for (int d = 0; d < bulbs.size(); d++){
            b2d[bulbs[d]-1]= d + 1; 
        }
        int l = 0, r = k + 1, res = INT_MAX;
        for (int b = 0; r < b2d.size(); b++){
            if (b2d[b] < b2d[l] || b2d[b] <= b2d[r]){
                if (r == b){
                    res = min (res, max(b2d[l], b2d[r])); 
                }
                l = b;
                r = k + b + 1;
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
