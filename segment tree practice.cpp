class Solution {
public:
    int t[80005];

    //point modify
    void update(int id, int s, int e, int val) //range modify : update(id,s,e,qs,qe)
    {
        if(s == e)//if(qs<=s && e<=qe)
        {
            t[id] += 1;
            return;
        }
        int m = (s+e) >> 1;

        if(val <= m) //if(qs <= m)
            update(id<<1, s, m, val);
        if(val > m) //if(qe > m)
            update(id<<1 | 1, m+1, e, val);

        t[id] = t[id<<1] + t[id<<1 | 1];
    }

    int query(int id, int s, int e, int qs, int qe)
    {
        if(qs>e || qe<s) return 0;
        if(qs<=s && e<=qe) return t[id];
        int m = (s+e) >> 1;
        return query(id<<1, s, m, qs, qe) + query(id<<1 | 1, m+1, e, qs, qe);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size(), N = 20000;
        for(int i=0; i<n; i++)
            nums[i] += 10000;

        vector<int> ans(n);
        for(int i=n-1; i>=0; i--)
        {
            ans[i] = query(1,0,N,0,nums[i]-1);
            update(1,0,N,nums[i]);
        }
        return ans;
    }
};

