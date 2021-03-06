// @Title: Minimum ASCII Delete Sum for Two Strings
// @Author: colinjxc
// @Date: 2022-01-24T02:58:30+08:00
// @URL: https://leetcode-cn.com/problems/minimum-ascii-delete-sum-for-two-strings


class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1));
        
        for (int i = 1; i <= s1.size(); i++) 
            dp[i][0] = s1[i-1] + dp[i-1][0];

        for (int i = 1; i <= s2.size(); i++) 
            dp[0][i] = s2[i-1] + dp[0][i-1];

        for (int i = 1; i <= s1.size(); i++) {
            for (int j = 1; j <= s2.size(); j++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = std::min(s1[i-1] + dp[i-1][j], s2[j-1] + dp[i][j-1]);
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
};
