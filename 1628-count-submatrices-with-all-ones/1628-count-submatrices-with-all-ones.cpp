class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> h(n, 0);
        long long ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) h[j] = mat[i][j] ? h[j] + 1 : 0;
            stack<int> st;
            vector<long long> sum(n, 0);
            for (int j = 0; j < n; ++j) {
                while (!st.empty() && h[st.top()] >= h[j]) st.pop();
                if (st.empty()) {
                    sum[j] = 1LL * h[j] * (j + 1);
                } else {
                    int k = st.top();
                    sum[j] = sum[k] + 1LL * h[j] * (j - k);
                }
                st.push(j);
                ans += sum[j];
            }
        }
        return (int)ans;
    }
};