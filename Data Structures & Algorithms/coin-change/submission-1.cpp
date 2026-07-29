class Solution {
public:
    int solve(int ind,vector<int>&coins,int amount){
        if(amount==0)return 0;
        if(ind>=coins.size())return 1e9;
        int a = 1e9;
        if(amount>=coins[ind]){
            a = 1 + solve(ind,coins,amount-coins[ind]);
        }
        int b = solve(ind+1,coins,amount);
        return min(a,b);
    }
    int coinChange(vector<int>& coins, int amount) {
        int a = solve(0,coins,amount);
        if(a==1e9){
            return -1;
        } 
        return a;
    }
};
