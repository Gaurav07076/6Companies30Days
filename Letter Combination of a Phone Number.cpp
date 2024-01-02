class Solution {
public:
    void solve(int i, string &digits,string &ds, vector<string> &ans, vector<string> &mapping){
        if(i == digits.size()){
            ans.push_back(ds);
            return;
        }

        int value = digits[i] - '0';

        string curr = mapping[value];
        for(int j = 0;j < curr.size(); j++){
            ds.push_back(curr[j]);
            solve(i+1,digits,ds,ans,mapping);
            ds.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0)return ans;

        string ds="";
        vector<string> mapping{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(0,digits,ds,ans,mapping);

        return ans;
        
    }
};