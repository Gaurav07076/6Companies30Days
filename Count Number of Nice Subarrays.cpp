class Solution {
public:
    int subArray(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;

        int l = 0, r = 0, count = 0;
        while(r < n){
            if(nums[r] % 2 == 1)count++;

            while(count > k){
                if(nums[l] % 2 == 1)count--;
                l++;
            }

            res += r - l+1;
            r++;

        }
        return res;

 
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        // find number of subarrys having at most k - number having at most k - 1
      return subArray(nums, k) - subArray(nums, k - 1);
    }
};