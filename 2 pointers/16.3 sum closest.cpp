class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int diff = INT_MAX, ans;
        for(int i=0; i<n; i++)
        {
            int j = i+1, k = n-1;
            while(j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(sum-target) < diff)
                {
                    diff = abs(sum-target);
                    ans = sum;
                }
                if(sum == target) return sum;
                if(sum > target) k--;
                else j++;
            }
        }
        return ans;
    }
};
