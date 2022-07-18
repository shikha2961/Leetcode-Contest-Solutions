// Problem :: https://leetcode.com/contest/weekly-contest-302/problems/max-sum-of-a-pair-with-equal-sum-of-digits/

class Solution {
public:
    int getSum (int num){
        int sum = 0;
        while(num!=0){
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
    
    vector<int> find_two_max(vector<int>& v){
        int f = INT_MIN;
        int s = INT_MIN;
        for(int i=0; i<v.size(); i++){
            int curr = v[i];
            if(f<curr){
                s = f;
                f = curr;
            }else if(s<curr){
                s = curr;
            }
        }
        return {f,s};
    }
    int maximumSum(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<n; i++){
            int s = getSum(nums[i]);
            mp[s].push_back(nums[i]);
        }
        for(auto it: mp){
            vector<int> v = it.second;
            if(v.size()>2){
                v = find_two_max(v);
            }
            if(v.size()==2){
                ans = max(ans, (v[0]+v[1]));
            }
        }
        return ans;
    }
};
