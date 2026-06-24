class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<pair<int, int>> st;
        vector<int> res(n, 0);
        int i = n - 1;
        while (i >= 0) {
            int count = 0;
            while (st.size() > 0) {
                int top = st.top().first;
                int val = st.top().second;
                if (temp[top] > temp[i]) {
                    st.push({i, temp[top]});
                    res[i] = count + 1;
                    break;
                } else {
                    count += res[top];
                    st.pop();
                }
            }
            if (st.size() == 0) {
                st.push({i, 0});
            }

            i--;
        }
        return res;
    }
};
