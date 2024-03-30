class Solution {
public:
    int less_or_equal(vector<int>& nums, int k)
    {
        int n = nums.size(), i=0, j=0, ans=0;
        int cnt[n+1], total=0;
        for(int i=0; i<=n; i++) cnt[i] = 0;

        while(j<n)
        {
            if(cnt[nums[j]]++ == 0) total++;
            while(total > k)
            {
                if(--cnt[nums[i]] == 0) total--;
                i++;
            }
            ans += j-i+1;
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        //subarray with at most k different numbers - subarray with at most k-1 different numbers
        return less_or_equal(nums,k) - less_or_equal(nums,k-1);
    }
};
