// Problem:: https://leetcode.com/contest/weekly-contest-302/problems/maximum-number-of-pairs-in-array/

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int pair1 = 0, pair2 = 0;
        for(auto it: mp){
            pair1 += it.second/2;
            pair2 += it.second%2;
        }
        return {pair1, pair2};
    }
};
