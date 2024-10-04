class Solution {
public:
    int strStr(string haystack, string needle) {
      if (needle.empty()) {
        return 0;
    }

    // Get the lengths of both strings
    int haystackLen = haystack.length();
    int needleLen = needle.length();

    // Iterate through the haystack until there's enough length left for needle
    for (int i = 0; i <= haystackLen - needleLen; i++) {
        // Check if the substring of haystack starting at i matches needle
        if (haystack.substr(i, needleLen) == needle) {
            return i; // Return the index if a match is found
        }
    }
     return -1;
    }
};