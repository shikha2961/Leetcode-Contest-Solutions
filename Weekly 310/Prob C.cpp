// Problem:: https://leetcode.com/contest/weekly-contest-310/problems/divide-intervals-into-minimum-number-of-groups/

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<intervals.size(); i++){
            // priority_queue<int, vector<int>, greater<int> > g = pq;
            // while(!g.empty()){
            //     cout<<g.top()<<" ";
            //     g.pop();
            // }
            // cout<<"\n";
            if(!pq.empty() && pq.top()<intervals[i][0]){
                pq.pop();
            }
            pq.push(intervals[i][1]);
        }
        return pq.size();
    }
};
