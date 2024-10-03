class Solution {
public:
    string reverseWords(string s) {
            // Split the string into words
    vector<string> words;
    string word;
    istringstream stream(s);
    while (stream >> word) {
        words.push_back(word);
    }
        

         
    // Reverse the order of words
    reverse(words.begin(), words.end());
    
    // Join the words with a single space between them
    string result;
    for (int i = 0; i < words.size(); ++i) {
        result += words[i];
        if (i != words.size() - 1) result += " ";
    }
    
    return result;
    }
};