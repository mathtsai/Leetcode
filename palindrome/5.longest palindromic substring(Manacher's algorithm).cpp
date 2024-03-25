class Solution {
public:
    int len = -1, u, v, n;
    void expand(int left, int right, string& s)
    {
        while(left >= 0 && right < n && s[left] == s[right])
        {
            if(len < right-left+1)
            {
                len = right-left+1;
                u = left, v = right;
            }
            left--, right++;
        }
    }
    string longestPalindrome(string s) {
        n = s.size();
        for(int i=0; i<n; i++)
        {
            expand(i,i,s);
            expand(i,i+1,s);
        }
        string ans;
        for(int i=u; i<=v; i++)
            ans += s[i];
        return ans;
    }
};
