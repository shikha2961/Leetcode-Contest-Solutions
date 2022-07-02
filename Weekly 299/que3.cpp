Problem:: https://leetcode.com/contest/weekly-contest-299/problems/maximum-score-of-spliced-array/

class Solution {
public:
    int func(vector<int>& arr1, vector<int>& arr2){
        int varSum = 0, maxi = 0;
        int sum = accumulate(arr1.begin(), arr1.end(), 0);
        for(int i=0; i<arr1.size(); i++){
            varSum += (arr2[i]-arr1[i]);
            if(varSum<0){
                varSum = 0;
            }
            maxi = max(varSum, maxi);
        }
        return sum+maxi;
        
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        return max(func(nums1, nums2), func(nums2, nums1));
    }
};
