//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	      int n = nums.size();
    vector<int> temp(nums.begin(), nums.end());
    sort(temp.begin(), temp.end());
    
    unordered_map<int, int> indexMap;
    for (int i = 0; i < n; i++) {
        indexMap[nums[i]] = i;
    }
    
    int swaps = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] != temp[i]) {
            swaps++;
            int correctIndex = indexMap[temp[i]];

            // Update the map
            indexMap[nums[i]] = correctIndex;
            indexMap[temp[i]] = i;

            // Swap the elements
            swap(nums[i], nums[correctIndex]);
        }
    }
    
    return swaps;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends