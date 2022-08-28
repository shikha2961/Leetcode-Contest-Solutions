class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        string ans = "";
        int cnt = 0;
       for(int i=n-1; i>=0; i--){
           if(s[i]=='*') cnt++;
           else if(cnt>0 && s[i]!='*') cnt--;
           else ans += s[i];
       }
        reverse(ans.begin(), ans.end());
           return ans;
    }
};
