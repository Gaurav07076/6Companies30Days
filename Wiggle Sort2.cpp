class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> temp;
        temp = nums;
        int n = nums.size();
        sort(temp.begin(),temp.end());

        int i = 1;
        int j = n-1;

        while(i < n){
            nums[i] = temp[j];
            j--;
            i+=2;
        }

        i = 0;
        while( i < n){
            nums[i] = temp[j];
            j--;
            i+=2;
        }
        
    }
};