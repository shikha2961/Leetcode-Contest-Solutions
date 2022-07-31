// Problem:: https://leetcode.com/contest/weekly-contest-304/problems/make-array-zero-by-subtracting-equal-amounts/

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int ans = 0;
        if(mp.find(0) != mp.end()){
            ans = mp.size()-1;
        }else{
            ans = mp.size();
        }
        return ans;
    }
};
