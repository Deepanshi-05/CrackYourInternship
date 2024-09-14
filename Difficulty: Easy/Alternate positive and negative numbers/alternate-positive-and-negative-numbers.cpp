//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
         vector<int> pos, neg;

    // Separate positive and negative numbers
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < 0)
            neg.push_back(arr[i]);
        else
            pos.push_back(arr[i]);
    }

    int i = 0, p = 0, n = 0;
    bool usePos = true; // Toggle between positive and negative

    while (i < arr.size()) {
        if (usePos && p < pos.size()) {
            arr[i++] = pos[p++];
        } else if (!usePos && n < neg.size()) {
            arr[i++] = neg[n++];
        }
        usePos = !usePos; // Alternate between positive and negative
    }

    // If there are remaining positive numbers
    while (p < pos.size()) {
        arr[i++] = pos[p++];
    }

    // If there are remaining negative numbers
    while (n < neg.size()) {
        arr[i++] = neg[n++];
    }
      
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends