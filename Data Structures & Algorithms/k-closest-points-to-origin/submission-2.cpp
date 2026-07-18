class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>>q;
        vector<vector<int>>res;
        int n = points.size();
        for(int i=0;i<n;i++){
            int x = points[i][0]*points[i][0]+points[i][1]*points[i][1];
            q.push({x,i});
            if(q.size()>k)q.pop();
        }
        while(!q.empty()){
            res.push_back(points[q.top().second]);
            q.pop();
        }
        return res;
    }
};
