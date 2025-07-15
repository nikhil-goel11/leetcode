class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        vector<int> groups;
        for(int i =0; i<n;){
            char c = word[i];
            int j = i;
            while(j< n && word[j] == c) ++j;
            groups.push_back(j - i);
            i = j;
        }
        int ans =1;
        for(int len: groups){
            if(len>1) ans += len -1;
        }
        return ans;
    }
};