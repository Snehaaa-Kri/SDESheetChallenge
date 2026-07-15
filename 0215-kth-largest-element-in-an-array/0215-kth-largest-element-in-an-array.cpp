class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // kth largest = min heap of size k
        priority_queue<int, vector<int>, greater<int>> minheap;

        int n = nums.size();
        for(int i=0; i<n; i++){
            if(minheap.size() < k){
                minheap.push(nums[i]);
            }
            else if(minheap.top() < nums[i]){
                minheap.pop();
                minheap.push(nums[i]);
            }
        }
        return minheap.top();

    }
};