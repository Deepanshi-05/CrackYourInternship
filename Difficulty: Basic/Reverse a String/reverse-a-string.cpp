//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string reverseString(string& s) {
        // Your code goes here
       string result = "";
       for(int i = s.length()-1 ; i >= 0; i--){
           result.push_back(s[i]);
       }
       return result;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.reverseString(s) << endl;
    }
    return 0;
}

// } Driver Code Ends