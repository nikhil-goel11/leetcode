class Solution {
    public:

            vector<int> maxSubsequence(vector<int>& nums, int k) {
                    vector<int> res;
                            int drop = nums.size() - k;
                                    for (int num : nums) {
                                                while (!res.empty() && drop && res.back() < num) {
                                                                res.pop_back();
                                                                                drop--;
                                                                                            }
                                                                                                        res.push_back(num);
                                                                                                                }
                                                                                                                        res.resize(k);
                                                                                                                                return res;
                                                                                                                                    }


                                                                                                                                            vector<int> merge(vector<int>& a, vector<int>& b) {
                                                                                                                                                    vector<int> res;
                                                                                                                                                            auto i = a.begin(), j = b.begin();
                                                                                                                                                                    while (i != a.end() || j != b.end()) {
                                                                                                                                                                                if (lexicographical_compare(i, a.end(), j, b.end()))
                                                                                                                                                                                                res.push_back(*j++);
                                                                                                                                                                                                            else
                                                                                                                                                                                                                            res.push_back(*i++);
                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                            return res;
                                                                                                                                                                                                                                                }

                                                                                                                                                                                                                                                    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
                                                                                                                                                                                                                                                            vector<int> ans;
                                                                                                                                                                                                                                                                    int n = nums1.size(), m = nums2.size();
                                                                                                                                                                                                                                                                            for (int i = max(0, k - m); i <= min(k, n); ++i) {
                                                                                                                                                                                                                                                                                        auto part1 = maxSubsequence(nums1, i);
                                                                                                                                                                                                                                                                                                    auto part2 = maxSubsequence(nums2, k - i);
                                                                                                                                                                                                                                                                                                                auto candidate = merge(part1, part2);
                                                                                                                                                                                                                                                                                                                            if (candidate > ans) ans = candidate;
                                                                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                                                                            return ans;
                                                                                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                                                                                };

