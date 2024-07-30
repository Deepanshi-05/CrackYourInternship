class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int totaltank = 0;
        int start = 0;
        int currtank = 0;
        for(int i = 0; i < gas.size(); i++){
            totaltank = totaltank + gas[i] - cost[i];
            currtank += gas[i] - cost[i];
            if(currtank < 0){
                start = i + 1;
                currtank = 0;
            }
        }
        if(totaltank >= 0){
            return start;
        }
        return -1;
    }
};