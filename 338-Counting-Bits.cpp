class Solution {
public:
    vector<int> countBits(int n) {
        int count = 0;
        vector<int> ans;
        for(int i = 0; i <= n; i++){
            int x = i;
            count = 0;
            while(x!=0){
                x = x&(x-1);
                count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};