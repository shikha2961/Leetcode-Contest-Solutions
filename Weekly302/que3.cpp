// Problem:: https://leetcode.com/contest/weekly-contest-302/problems/query-kth-smallest-trimmed-number/

// E.g. nums = ["24","37","96","04"], queries = [[2,1],[2,2]]
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int q = queries.size();
        vector<int> ans;
        for(int i=0; i<q; i++){
            
            vector<pair<string,int>> trimString;
             // This trimString vector will store all the trim strings and their indexes according to query, then sort the array
            // 4->0 4->3 6->2 7->1 
            // 04->3 24->0 37->1 96->2 

            for(int j=0; j<nums.size(); j++){
                string trimNum = nums[j].substr(nums[0].size()-queries[i][1],queries[i][1]);
                trimString.push_back({trimNum, j});
            }
            sort(trimString.begin(), trimString.end());
            
            // Access whichever smallest element is needed
            ans.push_back(trimString[queries[i][0]-1].second);
        }
        return ans;
    }
};
