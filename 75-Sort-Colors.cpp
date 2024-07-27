class Solution {
public:
    void sortColors(vector<int>& nums) {
              int begin = 0, mid = 0, end = size(nums) - 1;
        while (mid <= end) {
            if (nums[mid] == 0) {
                swap(nums[begin], nums[mid]);
                begin++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[end]);
                end--;
            }
        }
    }
};