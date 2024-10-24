class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // If there are no intervals, return an empty vector
    if(intervals.empty()) return {};

    // Sort the intervals by their start time
    sort(intervals.begin(), intervals.end());

    // Create a result vector to store merged intervals
    vector<vector<int>> merged;

    // Start with the first interval
    merged.push_back(intervals[0]);

    // Iterate through the intervals starting from the second one
    for(int i = 1; i < intervals.size(); ++i) {
        // Get the last interval in the merged vector
        vector<int>& last = merged.back();

        // If the current interval overlaps with the last merged interval
        if(intervals[i][0] <= last[1]) {
            // Merge them by updating the end of the last interval
            last[1] = max(last[1], intervals[i][1]);
        } else {
            // Otherwise, there is no overlap, so add the current interval to merged
            merged.push_back(intervals[i]);
        }
    }

    return merged;
    }
};