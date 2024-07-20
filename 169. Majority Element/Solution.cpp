class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele;
        int count = 0;
        for(int i = 0; i< nums.size(); i++){
            if(count == 0){
                ele = nums[i];
                count++;
            }
            else if(ele == nums[i]){
                count++;
            }
            else{
                count--;
            }
        }
        count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == ele){
                count++;
            }
        }
        if(count > (nums.size())/2){
            return ele;
        }
        return -1;
    }
};