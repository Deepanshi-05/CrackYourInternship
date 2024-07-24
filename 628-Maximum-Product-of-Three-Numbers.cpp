class Solution {
public:
    int maximumProduct(vector<int>& nums) {
          sort(nums.begin(), nums.end());

    // Calculate the product of the three largest numbers
    int product1 = nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3];

    // Calculate the product of the two smallest numbers and the largest number
    int product2 = nums[0] * nums[1] * nums[nums.size() - 1];

    // Return the maximum of the two products
    return max(product1, product2);
    }
};