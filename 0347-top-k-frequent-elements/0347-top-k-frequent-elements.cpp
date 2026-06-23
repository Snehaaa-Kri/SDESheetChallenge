class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp; //num -> cnt

        for(int &num: nums){
            mp[num]++;
        }

        //top k freq el - max heap of size k   -- {freq, num}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //min heap
        for(auto &el: mp){
            if(pq.size()<k){
                pq.push({el.second, el.first});
            }
            else{
                if(pq.top().first < el.second){
                    pq.pop();
                    pq.push({el.second, el.first});
                }
            }
        }

        vector<int> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};