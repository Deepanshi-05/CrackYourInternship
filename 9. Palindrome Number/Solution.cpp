class Solution {
public:
    bool isPalindrome(int x) {
       if (x < 0) return false;

    // Convert integer to string
    string s = to_string(x);
    
    // Create a reversed copy of the string
    string reversed_s = s;
    reverse(reversed_s.begin(), reversed_s.end());

    // Check if the original string is equal to the reversed string
    return s == reversed_s;
    }
};