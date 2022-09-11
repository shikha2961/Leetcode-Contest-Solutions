// Problem:: https://leetcode.com/contest/weekly-contest-310/problems/optimal-partition-of-string/

class Solution {
public:
    int partitionString(string s) {
      unordered_map<char, int> mp;
        int cnt = 1;
        int n = s.size();
        for(int i=0; i<n; i++){
            auto it = mp.find(s[i]);
            if(it!=mp.end() && it->second>=1){
                cnt++;
                mp.clear();
            }
            mp[s[i]]++;
        }
        return cnt;
    }
};
