class Solution {
public:
    bool isSubsequence(string s, string t) {
    //       // Step 1: Handle the edge case when `t` is empty
    // if (t.empty()) {
    //     return s.empty();  // Return true if `s` is also empty, otherwise false
    // }
    //     if(t.size() < s.size()){
    //         return -1;
    //     }
    //     string created;

    // // Step 2: Traverse through `t` to construct the `created` string
    // int index = 0;  // Pointer to track the position in `s`
    //        for (char c : t) {
    //     // If the character in `t` matches the current character in `s`, add it to `created`
    //     if (index < s.length() && c == s[index]) {
    //         created += c;
    //         index++;  // Move to the next character in `s`
    //     }
    // }

    // // Step 3: Check if the constructed string `created` matches `s`
    // return created == s;  ########Too much Error########

    // #####EFFICIENT APPROACH
       int i = 0, j = 0;

    // Traverse both strings
    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) {
            i++;  // Move pointer in `s` only if characters match
        }
        j++;  // Always move pointer in `t`
    }

    // Check if we traversed the entire `s`
    return i == s.size();

}
    
};