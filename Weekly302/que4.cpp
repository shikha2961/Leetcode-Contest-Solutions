// Problem:: https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int ans = 0;
        for(auto it: mp){
            bool flag = true;
            for(int j=0; j<numsDivide.size(); j++){
                if(numsDivide[j]%it.first!=0){
                    flag = false;
                    break;
                }
            }
            if(!flag) ans += it.second;
            else return ans;
        }
        return -1;
    }
};
