class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(string str:strs){
            res += to_string(str.size()) + "#" + str;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string>res;
        int n = s.size();
        int i=0;
        while(i<n){
            int j = i;
            while(s[j]!='#'){
                j++;
            }
            int length = stoi(s.substr(i,j-i));
            i=j+1;
            j=i+length;
            res.push_back(s.substr(i,length));
            i=j;
        }
        return res;
    }
};
