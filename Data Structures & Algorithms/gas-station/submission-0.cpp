class Solution {

public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int tot_gas=0,tot_cost=0,point=0,curr_gas=0;

        for(int i=0;i<n;i++){
            tot_gas += gas[i];
            tot_cost += cost[i];

            curr_gas+= (gas[i]-cost[i]);
            if(curr_gas<0){
                curr_gas = 0;
                point = i+1;
            }
        }
        if(tot_gas < tot_cost) return -1;
        else return point;
    }
};