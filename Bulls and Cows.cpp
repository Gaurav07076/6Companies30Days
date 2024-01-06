class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int n = secret.size();
        unordered_map<char,int> s;
        unordered_map<char,int> g;

        for(int i = 0; i < n; i++){
            if(secret[i] == guess[i])bulls++;
            else{
                s[secret[i]]++;
                g[guess[i]]++;
            }
        }

        string x = to_string(bulls);

        int cows = 0;
        
        for(auto it: s){
            if(g.find(it.first) != g.end()){
                cows += min(g[it.first], s[it.first]);
            }
        }

        string y = to_string(cows);

        string ans = x + 'A' + y + 'B';
        return ans;

    }
};