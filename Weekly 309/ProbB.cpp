// https://leetcode.com/contest/weekly-contest-309/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/


## Recursive Way (Time Limit Exceeded)
class Solution {
public:
    int func(int i, int endPos, int k){
        if(k==0 && i==endPos) return 1;
        if(k<=0) return 0;
        int l = func(i-1, endPos, k-1);
        int r = func(i+1, endPos, k-1);
        
        return l+r;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        return func(startPos, endPos, k,dp);
    }
};

## Memoization
int N = 1e9+7;
long long dp[3001][1001];
class Solution {
public:
    int func(int i, int endPos, int k){
        if(k==0 && i==endPos) return 1;
        if(k<=0) return 0;
        if(dp[i+1000][k]!=-1) return dp[i+1000][k];
        int l = func(i+1, endPos, k-1);
        if((k-1)>=(endPos-i+1))
        l += func(i-1, endPos, k-1);
        
        return dp[i+1000][k] = l%N;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp, -1, sizeof(dp));
        if(abs(startPos-endPos)>k) return 0;
        return func(startPos, endPos, k)%N;
    }
};
