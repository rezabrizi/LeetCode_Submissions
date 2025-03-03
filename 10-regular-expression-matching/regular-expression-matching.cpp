class Solution {
public:
    bool isMatch(string s, string p) {
        unordered_map<int, unordered_map<int, bool>> memo; 
        return dfs(0, 0, s, p, memo);
    }
    
    bool dfs(int i, int j, const string& s, const string& p, unordered_map<int, unordered_map<int, bool>> &memo){
        
        if(memo.find(i) != memo.end() && memo[i].find(j) != memo[i].end())
            return memo[i][j];
        
        if (i >= s.length() && j >= p.length()){
            return true; 
        }
        
        if (j >= p.length()){
            return false; 
        }
        
        bool match = (i < s.length() && (s[i] == p[j] || p[j] == '.'));
        
        if (j < p.length()-1 && p[j+1] == '*'){
            memo[i][j] = (match && dfs(i+1, j, s, p, memo)) || dfs(i, j+2, s, p, memo);  
            return memo[i][j]; 
        }
        
        if(match)
        {
            memo[i][j] = (dfs(i+1, j+1, s, p, memo));
            return memo[i][j];
        }
        
        memo[i][j] = false;
        return false;
        
    }
};