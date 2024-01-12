class Solution {
    int m,n;
    set<pair<int,int>>s;
public:
    Solution(int m, int n) {
        this -> m = m;
        this -> n = n;
        s.clear();
    }
    
    vector<int> flip() {
        int r = rand()%m;
        int c = rand()%n;

        while(s.count({r,c}) > 0){
            r = rand()%m;
            c = rand()%n;
        }

        s.insert({r,c});
        return {r,c};
    }
    
    void reset() {
        s.clear();
    }
};


