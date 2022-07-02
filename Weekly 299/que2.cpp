Problem:: https://leetcode.com/contest/weekly-contest-299/problems/count-number-of-ways-to-place-houses/

class Solution {
public:
    long long N = 1000000000+7;
    long long fib(long long n){
        long long a = 0, b = 1, c, i;
        if( n == 0)
            return a;
        for(i = 2; i <= n; i++)
        {
           c = ((a%N) + (b%N));
           a = b;
           b = c;
        }
        return b%N;
    }
    int countHousePlacements(int n) {
        if(n==1) return 4;
        int result = fib(n+2);
        return ((result%N)*(result%N))%N;
    }
};

