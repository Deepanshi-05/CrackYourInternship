class Solution {
public:void findSum(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, int i) {
    // Base case: if index reaches the end, add the current subset to ans
    if (i == nums.size()) {
        ans.push_back(temp);
        return;
    }

    // Include the current element
    temp.push_back(nums[i]);
    findSum(nums, ans, temp, i + 1);
    temp.pop_back();  // Backtrack

    // Exclude the current element and skip duplicates
    while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
        i++;
    }
    findSum(nums, ans, temp, i + 1);
}

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> temp;
    findSum(nums, ans, temp, 0);
    return ans;

    }
};