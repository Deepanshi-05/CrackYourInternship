class Solution {
public:
    int candy(vector<int>& ratings) {
          int n = ratings.size();
    if (n == 1) return 1;  
        vector<int> count(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                count[i] = count[i - 1] + 1;
            }
        }

        for (int j = ratings.size() - 2; j >= 0; j--) {
            if (ratings[j] >
                ratings[j + 1]) { // Compare with the right neighbor
                count[j] = max(
                    count[j], count[j + 1] +
                                  1); // Ensure the count is greater if required
            }
        }

        int sum = 0;
        for (int k = 0; k < count.size(); k++) {
            sum = sum + count[k];
        }
        return sum;
    }
};