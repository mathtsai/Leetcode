class Solution {
public:
    #define ll long long
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        ll p = 1;
        int n = nums.size(), cnt = 0, i = 0, j = 0;
        while(j<n)
        {
            p *= nums[j];
            while(i<=j && p >= k) p /= nums[i++];
            cnt += j-i+1;
            j++;
        }
        return cnt;
    }
};
