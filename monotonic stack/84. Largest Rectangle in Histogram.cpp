class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        int l[n], r[n]; //record most left and most right can be reached by ith height
        for(int i=0; i<n; i++)
        {
            l[i] = 0;
            r[i] = n-1;
        }

        stack<pair<int,int>> st;
        for(int i=0; i<n; i++)
        {
            while(!st.empty() && h[i] < st.top().first)
            {
                r[st.top().second] = i-1;
                st.pop();
            }
            st.push({h[i], i});
        }

        while(!st.empty()) st.pop();

        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && h[i] < st.top().first)
            {
                l[st.top().second] = i+1;
                st.pop();
            }
            st.push({h[i], i});
        }

        int ans = 0;
        for(int i=0; i<n; i++)
            ans = max(ans, (r[i]-l[i]+1)*h[i]);
        return ans;
    }
};
