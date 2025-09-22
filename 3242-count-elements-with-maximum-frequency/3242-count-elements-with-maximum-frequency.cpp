class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
    int maxFreq = 0, total = 0;
    for (int n : nums) maxFreq = max(maxFreq, ++freq[n]);
    for (auto& [_, f] : freq) if (f == maxFreq) total += f;
    return total;
    }
};