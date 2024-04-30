class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans = 0;
        int n = word.size(), cur = 0;
        int cnt[1024] = {0};
        cnt[0] = 1;
        for(int i=0; i<n; i++)
        {
            int k = word[i]-'a';
            cur = cur^(1<<k);
            ans += cnt[cur];

            int last = 1;
            for(int j=0; j<10; j++)
            {
                ans += cnt[cur^last];
                last <<= 1;
            }
            cnt[cur]++;
        }
        return ans;
    }
};
