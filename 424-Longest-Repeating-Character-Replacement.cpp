class Solution {
public:
    int characterReplacement(string s, int k) {
         unordered_map<char, int> freq_map; // Map to store frequency of characters in the current window
    int start = 0;                     // Start pointer of the window
    int max_count = 0;                 // Max frequency of any character in the current window
    int max_len = 0;                   // The longest valid window length

    // Loop through the string with the end pointer
    for (int end = 0; end < s.length(); ++end) {
        char current_char = s[end];

        // Increment the frequency of the current character in the window
        freq_map[current_char]++;
        
        // Update max_count to hold the highest frequency of any character in the current window
        max_count = max(max_count, freq_map[current_char]);

        // Check if the current window is invalid (i.e., needs more than 'k' replacements)
        // If invalid, shrink the window by moving the start pointer
        while ((end - start + 1) - max_count > k) {
            // Decrease the frequency of the character that is at the 'start' position
            freq_map[s[start]]--;
            start++; // Shrink the window from the left
        }

        // Update max_len to the maximum valid window size found
        max_len = max(max_len, end - start + 1);
    }

    return max_len;
    }
};