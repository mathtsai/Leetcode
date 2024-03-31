class Solution {
public:
    long long countSubarrays(vector<int>& nums, int Min, int Max) {
        int n = nums.size(), i=0,j=0, min_id = -1, max_id=-1;
        long long ans = 0;
        while(j<n)
        {
            if(nums[j]>=Min && nums[j]<=Max)
            {
                if(nums[j] == Min) min_id = j;
                if(nums[j] == Max) max_id = j;

                if(min_id != -1 && max_id != -1)
                    ans += min(min_id, max_id)-i+1;
            }
            else
            {
                i = j+1;
                min_id = -1;
                max_id = -1;
            }

            j++;
        }
        return ans;
    }
};
