class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for(auto it: s){
            freq[it]++;
        }

        priority_queue<pair<int,char>> pq;
        for(auto it: freq){
            pq.push({it.second,it.first});
        }

        string res = "";
        while(!pq.empty()){
            int x = pq.top().first;
            for(int i = 0; i < x; i++){
                res+= pq.top().second;
            }
            pq.pop();
        }
        return res;
        
    }
};