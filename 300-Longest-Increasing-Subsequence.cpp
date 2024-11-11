class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
     int ans = 1, n = size(nums);
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < i; j++) 
                if(nums[i] > nums[j]) 
\t\t\t\t    dp[i] = max(dp[i], dp[j] + 1), ans = max(ans, dp[i]);
        return ans;
      
    }
};