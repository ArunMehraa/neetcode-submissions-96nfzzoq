class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>>q;
        vector<vector<int>>res;
        int n = points.size();
        for(int i=0;i<n;i++){
            double x = sqrt((points[i][0]*points[i][0])+(points[i][1]*points[i][1]));
            cout<<x<<endl;
            q.push({x,points[i]});
            if(q.size()>k)q.pop();
        }
        while(!q.empty()){
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};
