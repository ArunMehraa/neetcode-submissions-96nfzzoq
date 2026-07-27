class Solution {
public:
    void solve(int ind,string digits,vector<string>&res,vector<vector<char>>&mp,string& temp){
        if(ind==digits.size()){
            res.push_back(temp);
            return;
        }
        int sizee = mp[digits[ind]-'0'].size();
        for(int i=0;i<sizee;i++){
            int index = digits[ind]-'0';
            temp+=mp[index][i];
            cout<<temp<<endl;
            solve(ind+1,digits,res,mp,temp);
            temp.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        if(digits.size()==0)return res;
        vector<vector<char>>mp(10);
        mp[2] = {'a','b','c'};
        mp[3] = {'d','e','f'};
        mp[4] = {'g','h','i'};
        mp[5] = {'j','k','l'};
        mp[6] = {'m','n','o'};
        mp[7] = {'p','q','r','s'};
        mp[8] = {'t','u','v'};
        mp[9] = {'w','x','y','z'};
        string temp = "";
        solve(0,digits,res,mp,temp);
        return res;
    }
};
