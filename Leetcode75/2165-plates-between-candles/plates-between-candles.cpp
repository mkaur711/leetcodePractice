class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> v; // Store candle positions

        // Find candle positions
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '|') {
                v.push_back(i);
            }
        }

        vector<int> ans(queries.size(), 0);

        for (int i = 0; i < queries.size(); i++) {
            auto x = lower_bound(v.begin(), v.end(), queries[i][0]);
            auto y = lower_bound(v.begin(), v.end(), queries[i][1]);

            if (v.size() == 0) break;
            
            if (y == v.end()) y--;
            else if (*y != queries[i][1]) y--;

            if (x == v.end() || x >= y) continue;

            ans[i] = (*y - *x - 1 - (y - x - 1));
        }

        return ans;
    }
};