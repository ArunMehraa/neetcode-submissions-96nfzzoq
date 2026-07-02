class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        if(n==1)return 1;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[position[i]] = i;
        }
        sort(position.begin(),position.end(),greater<int>());
        int count=n;
        int i=0;
        while(i<n){
            int speedi = speed[mp[position[i]]];
            int distance = target - position[i];
            double time = (distance)/(double)speedi;
            int j = i+1;
            while(j<n){
                int speedj = speed[mp[position[j]]];
                int distance = target-position[j];
                double covered_distance = (speedj) * time;
                if(covered_distance>=distance){
                    count--;
                    j++;
                }
                else{
                    break;
                }
            }
            i=j;
        }
        if(count==0)return 1;
        return count;
    }
};