class Solution {
public:
    int maxArea(vector<int>& height) {
        int left  = 0;
        int right = height.size() - 1;
        int maxArea = 0;
        while(left<right){
            int mini = min(height[left], height[right]);
            int width = right - left;
            maxArea = max(maxArea, mini*width);

            if(height[left]<height[right]){
                ++left;
            }
            else{
                --right;
            }
        }
        return maxArea;
    }
};