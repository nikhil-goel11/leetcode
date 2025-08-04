class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorSum = 0;
                for (int num : nums)
                            xorSum ^= num;

                                    unsigned int diffBit = (unsigned int)xorSum & (-(unsigned int)xorSum);

                                            int a = 0, b = 0;
                                                    for (int num : nums) {
                                                                if ((num & diffBit) == 0)
                                                                                a ^= num;
                                                                                            else
                                                                                                            b ^= num;
                                                                                                                    }

                                                                                                                            return {a, b};
    }
};