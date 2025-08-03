class Solution {
    public:
        vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
                vector<pair<int, int>> events;
                        for (auto& b : buildings) {
                                    events.emplace_back(b[0], -b[2]); // start, use negative for max-heap
                                                events.emplace_back(b[1], b[2]);  // end
                                                        }
                                                                sort(events.begin(), events.end());
                                                                        multiset<int> heights = {0};
                                                                                int prev = 0;
                                                                                        vector<vector<int>> res;
                                                                                                for (auto& [x, h] : events) {
                                                                                                            if (h < 0) heights.insert(-h);      // entering building
                                                                                                                        else heights.erase(heights.find(h)); // leaving building
                                                                                                                                    int curr = *heights.rbegin();
                                                                                                                                                if (curr != prev) {
                                                                                                                                                                res.push_back({x, curr});
                                                                                                                                                                                prev = curr;
                                                                                                                                                                                            }
                                                                                                                                                                                                    }
                                                                                                                                                                                                            return res;
                                                                                                                                                                                                                }
                                                                                                                                                                                                                };

