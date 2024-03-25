class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int prefix[n+1], cnt = 0;
        unordered_map<int,int> mp;
        prefix[0] = 0;
        mp[0]++;

        for(int i=1; i<=n; i++)
        {
            prefix[i] = prefix[i-1] + nums[i-1];
            int t = prefix[i]-k;
            if(mp.find(t) != mp.end())
                cnt += mp[t];
            mp[prefix[i]]++;
        }
        return cnt;
    }
};
