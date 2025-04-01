class Solution:
    def longestPalindrome(self, s: str, t: str) -> int:

        def is_pal(s_to_check):
            l, r = 0, len(s_to_check)-1
            while (l <= r):
                if (s_to_check[l] != s_to_check[r]):
                    return False
                l+=1
                r-=1
            return True

        ans = 1
        for s1 in range(len(s)):
            for s2 in range(s1, len(s)+1):
                for t1 in range(len(t)):
                    for t2 in range(t1, len(t)+1):
                        s_sub = s[s1:s2]
                        t_sub = t[t1:t2]
                        concat = s_sub + t_sub
                        if (is_pal(concat)):
                            ans = max(ans, len(concat))
        return ans
            

            
        