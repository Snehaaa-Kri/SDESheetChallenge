class Solution {
public:
    // using minheap of size = k
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        int i = 0; 
        while(i<nums.size()){
            if(i < k) pq.push(nums[i]); //O(logN)
            else{
                if(pq.top() < nums[i]){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
            i++;
        }
        return pq.top();
    }
};