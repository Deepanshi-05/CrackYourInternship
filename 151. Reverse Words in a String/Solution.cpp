class Solution {
public:
    string reverseWords(string s) {
       istringstream iss(s);
       vector<string> words;
       string word;
    
    // Split the string into words
    while (iss >> word) {
        words.push_back(word);
    }
    
    // Reverse the vector of words
    std::reverse(words.begin(), words.end());
    
    // Join the reversed words back into a string
    ostringstream oss;
    for (size_t i = 0; i < words.size(); ++i) {
        if (i != 0) {
            oss << " ";
        }
        oss << words[i];
    }
    
    return oss.str(); 
    }
};