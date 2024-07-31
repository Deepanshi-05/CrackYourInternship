class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> stack;
    
    for (char digit : num) {
        while (k > 0 && !stack.empty() && stack.back() > digit) {
            stack.pop_back();
            k--;
        }
        stack.push_back(digit);
    }
    
    // If we still have k digits to remove
    while (k > 0) {
        stack.pop_back();
        k--;
    }
    
    // Build the result from the stack
    string result = \\;
    for (char digit : stack) {
        if (!(result.empty() && digit == '0')) { // Avoid leading zeros
            result.push_back(digit);
        }
    }
    
    // Return '0' if the result is an empty string
    return result.empty() ? \0\ : result;
    }
};