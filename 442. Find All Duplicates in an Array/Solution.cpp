class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
    unordered_map<int, int> element_count;
    vector<int> duplicates;

    // Count the occurrences of each element
    for (int element : nums) {
        element_count[element]++;
    }

    // Identify elements that have a count greater than 1
    for (const auto& pair : element_count) {
        if (pair.second > 1) {
            duplicates.push_back(pair.first);
        }
    }

    return duplicates;
    }
};