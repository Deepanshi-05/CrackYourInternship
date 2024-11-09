class Solution {
public:
    int rob(vector<int>& nums) {
         int n = nums.size();
    if (n == 0) return 0;          // No houses to rob
    if (n == 1) return nums[0];    // Only one house to rob

    vector<int> dp(n, 0);
    dp[0] = nums[0];               // Robbing the first house
    dp[1] = max(nums[0], nums[1]); // Max of robbing the first or second house

    for (int i = 2; i < n; i++) {
        dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
    }

    return dp[n - 1];
    }
};