class Solution {
public:
    int trap(vector<int>& height) {
      int n = height.size();
    if (n <= 2) return 0;  // No water can be trapped if there are less than 3 bars

    int left = 0;            // Pointer to traverse from the left
    int right = n - 1;       // Pointer to traverse from the right
    int left_max = 0;        // Maximum height on the left side
    int right_max = 0;       // Maximum height on the right side
    int water_trapped = 0;   // Total water trapped

    while (left <= right) {
        // Determine which side to process
        if (height[left] <= height[right]) {
            if (height[left] >= left_max) {
                left_max = height[left];  // Update left maximum
            } else {
                water_trapped += left_max - height[left];  // Calculate trapped water
            }
            ++left;  // Move left pointer to the right
        } else {
            if (height[right] >= right_max) {
                right_max = height[right];  // Update right maximum
            } else {
                water_trapped += right_max - height[right];  // Calculate trapped water
            }
            --right;  // Move right pointer to the left
        }
    }

    return water_trapped;  
    }
};