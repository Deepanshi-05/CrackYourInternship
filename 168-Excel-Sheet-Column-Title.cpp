class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result;

    while (columnNumber > 0) {
        columnNumber--; // Adjust for 1-based indexing
        char currentChar = 'A' + (columnNumber % 26); // Determine the current letter
        result += currentChar; // Append the current letter to the result
        columnNumber /= 26; // Update columnNumber for the next iteration
    }

    std::reverse(result.begin(), result.end()); // Reverse the result string to get the correct order

    return result;
    }
};