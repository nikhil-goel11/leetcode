// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        while (true) {
        int a = rand7();
        int b = rand7();
        int idx = (a - 1) * 7 + b;
        if (idx <= 40) return 1 + (idx - 1) % 10;
        a = idx - 40;
        b = rand7();
        idx = (a - 1) * 7 + b;
        if (idx <= 60) return 1 + (idx - 1) % 10;
        a = idx - 60;
        b = rand7();
        idx = (a - 1) * 7 + b;
        if (idx <= 20) return 1 + (idx - 1) % 10;
        }
    }
};