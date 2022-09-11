// Problem:: https://leetcode.com/contest/weekly-contest-310/problems/most-frequent-even-element/

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2==0)
            mp[nums[i]]++;
        }
        if(mp.size()==0) return -1;
        int maxi = INT_MIN;
        int ans = -1;
        for(auto it: mp){
            if(maxi<it.second){
                maxi = it.second;
                ans = it.first;
            }
        }
        return  ans;
    }
};
