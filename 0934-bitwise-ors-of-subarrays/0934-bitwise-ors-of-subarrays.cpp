class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res,prev,cur;
        for(int n: arr){
            cur ={n};
            for(int x: prev) cur.insert(x | n);
            prev = cur;
            res.insert(cur.begin(), cur.end());
        }
        return res.size();
    }
};