class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int n: nums) freq[n]++;
        vector<vector<int>> buckets(nums.size() +1);
        for(auto& p: freq) buckets[p.second].push_back(p.first);
        vector<int> res;
        for(int i = nums.size(); i>= 0 && res.size()<k; --i){
            for(int n: buckets[i]){
                res.push_back(n);
                if(res.size() == k)break;
            }
        }
        return res;
    }
};