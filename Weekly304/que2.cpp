// Problem:: https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition/

class Solution {
public:
    // If we are able to create the grouping like this: group of 1 , group of 2, group of 3 & so on. count those groups and return the ans
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int cnt = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            cnt++;
            int chk = cnt;
            bool flag = true;
            while(i<n && chk>0){
                i++;
                chk--;
                flag = false;
            }
            if(flag == false) i--;
            if(chk==0) ans++;
        }
        return ans;
    }
};
