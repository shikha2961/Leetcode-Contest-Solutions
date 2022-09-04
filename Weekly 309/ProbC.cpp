// Problem:: https://leetcode.com/contest/weekly-contest-309/problems/longest-nice-subarray/

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
       int i = 0, j=0, fl = 0, ans = 0;
        while(j<nums.size()){
            int an = fl & nums[j];
            if(an==0){
                ans = max(ans, (j-i+1));
                fl |= nums[j];
                j++;
            }else{
                fl ^= nums[i];
                i++;
            }
        }
        return ans;
    }
};
