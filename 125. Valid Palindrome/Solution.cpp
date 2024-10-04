class Solution {
public:
    bool isPalindrome(string s) {
         string result;
    
    // Iterate through each character in the input string
    for (char c : s) {
        // Convert to lowercase
        char lowerChar = tolower(c);
        
        // Keep only alphanumeric characters
        if (isalnum(lowerChar)) {
            result += lowerChar;
        }
    }
     // Step 2: Use two pointers to check if the cleaned string is a palindrome
        int left = 0, right = result.length() - 1;

        while (left < right) {
            if (result[left] != result[right]) {
                return false; // If mismatch, it's not a palindrome
            }
            left++;
            right--;
        }

        return true; // All characters matched, it's a palindrome
    }
};