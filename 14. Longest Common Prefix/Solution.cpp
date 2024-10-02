class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
            if (strs.empty()) return "";

    string prefix = strs[0];  // Assume the first string as the initial prefix
    for (int i = 1; i < strs.size(); i++) {
        // Reduce prefix length until it matches the start of the current string
        while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.length() - 1);
            if (prefix.empty()) return "";  // No common prefix
        }
    }
    return prefix;
        
    }
};