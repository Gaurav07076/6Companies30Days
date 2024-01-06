class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        
        vector<vector<int>> ans(n, vector<int> (m,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int curr = 0;
                int x = 0;
                for(int delrow = -1; delrow <= 1; delrow++){
                    for(int delcol = -1; delcol <=1 ; delcol++){
                        int nrow = i + delrow;
                        int ncol = j + delcol;
                        if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m){
                            x++;
                            curr+= img[nrow][ncol];
                        }
                    }
                }

                ans[i][j] = curr / x;
            }
        }
        return ans;
    }
};