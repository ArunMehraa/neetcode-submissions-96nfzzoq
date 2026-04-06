class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==1)return 0;
        vector<int>maxi(n,0);
        maxi[n-1]=prices[n-1];
        for(int j=n-2;j>=0;j--){
            maxi[j] = max(maxi[j+1],prices[j]);
        }
        int ans = 0;
        for(int i=0;i<n-1;i++){
            ans = max(ans,maxi[i+1] - prices[i]);
        }
        return ans;
    }
};
