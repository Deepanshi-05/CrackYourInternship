class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int count = 1;
        for(int j = 1; j < nums.size(); j++){
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
                count = 1;
            }
            else if(nums[i] == nums[j]){
                count++;
                if(count <= 2){
                    i++;
                    nums[i] = nums[j] ;
                }
            }
        }
        return i+1;
    }
};