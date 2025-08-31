class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long len = 1;
        vector<long long> pref;
        for (int t : operations) {
            if (t == 0) len *= 2;
            else len *= 2;
            pref.push_back(len);
            if (len >= k) break;
        }
        long long inc = 0;
        for (int i = (int)pref.size() - 1; i >= 0; --i) {
            long long half = pref[i] / 2;
            if (k > half) {
                k -= half;
                if (operations[i] == 1) inc++;
            }
        }
        char base = 'a';
        int shift = inc % 26;
        return char((base - 'a' + shift) % 26 + 'a');
    }
};