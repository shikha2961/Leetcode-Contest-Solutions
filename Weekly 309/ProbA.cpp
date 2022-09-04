// Problem:: https://leetcode.com/contest/weekly-contest-309/problems/check-distances-between-same-letters/

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
       
        int n = s.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(s[i]==s[j]){
                    long long chk = (j-i-1);
                    if(distance[s[i]-'a']==chk){
                        break;
                    }else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
