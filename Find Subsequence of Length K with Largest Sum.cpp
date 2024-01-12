class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        int n = nums.size();
        for(int i = 0; i < n; i++){
            minHeap.push({nums[i],i});
            if(minHeap.size() > k)minHeap.pop();
            
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;
        while(!minHeap.empty()){
            heap.push({minHeap.top().second,minHeap.top().first});
            minHeap.pop();
        }

        vector<int> ans;
        while(!heap.empty()){
            ans.push_back(heap.top().second);
            heap.pop();
        }

        return ans;


        
    }
};