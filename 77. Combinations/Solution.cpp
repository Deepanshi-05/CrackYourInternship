class Solution {
public:
void findCombine(vector<int>& arr, vector<vector<int>>& ans, int n, int k, 
                 vector<int>& temp, int i) {

  if (temp.size() == k) {
        ans.push_back(temp);
        return;
    }
    if (i == n) {
        return;
    }

    // Include the current element
    temp.push_back(arr[i]);
    findCombine(arr, ans, n, k, temp, i + 1);
    temp.pop_back();  // Backtrack

    // Exclude the current element and skip duplicates
    while (i + 1 < n && arr[i] == arr[i + 1]) {
        i++;
    }
    findCombine(arr, ans, n, k, temp, i + 1);
}
    vector<vector<int>> combine(int n, int k) {
          vector<int> arr;
         for (int i = 1; i <= n; i++) {
        arr.push_back(i);
    }
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> temp;
    findCombine(arr, ans, n, k, temp, 0);
    return ans;
    }
};