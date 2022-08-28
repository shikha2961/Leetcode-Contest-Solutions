class Solution {
public:
   
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
       
      sort(nums.begin(), nums.end());
      int n = nums.size();
      int m = queries.size();
        vector<int> prefix_sum(n);
        vector<int> ans(m);
        prefix_sum[0] = nums[0];
        for(int i=1; i<n; i++){
           prefix_sum[i] = prefix_sum[i-1]+nums[i];
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(prefix_sum[j]<=queries[i]) ans[i] = j+1;
                else break;
            }
        }
        return ans;
    }
};
