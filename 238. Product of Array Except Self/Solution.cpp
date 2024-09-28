class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int n = nums.size();
    vector<int> result(n, 1);  // Initialize the result array with 1
    
    // First pass: Calculate the left products
    int left_product = 1;
    for (int i = 0; i < n; ++i) {
        result[i] = left_product;  // Store the product of elements to the left of i
        left_product *= nums[i];   // Update left_product for the next element
    }
    
    // Second pass: Calculate the right products and update the result array
    int right_product = 1;
    for (int i = n - 1; i >= 0; --i) {
        result[i] *= right_product;  // Multiply by the product of elements to the right of i
        right_product *= nums[i];    // Update right_product for the next element
    }
    
    return result;
    }
};