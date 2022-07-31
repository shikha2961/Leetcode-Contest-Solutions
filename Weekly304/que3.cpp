Problem:: https://leetcode.com/contest/weekly-contest-304/problems/find-closest-node-to-given-two-nodes/

class Solution {
public:
    void calculate_distances(vector<int> & dist, vector<int> & edges, int node, int distance){
        if(node != -1 && dist[node] == -1 ){
            dist[node] = distance;
            calculate_distances(dist, edges, edges[node], distance+1);
        }
    }
    
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        
        vector<int> dist_from_node1 (n , -1), dist_from_node2 (n , -1);
        
        // Calculate the distance from node1 to the node, where it can go & same for node2
        calculate_distances(dist_from_node1, edges, node1, 0);
        calculate_distances(dist_from_node2, edges, node2, 0);
        
        int ans = -1, min_dist = INT_MAX;
        for(int i=0; i<n; i++){
            // will check for minimum of dist_from_node1[i] and dist_from_node2[i] should >=0 because both nodes should be able to reach the particular node
            // and max of both the distances should be minimized 
            if(min(dist_from_node1[i], dist_from_node2[i])>=0 && max(dist_from_node1[i], dist_from_node2[i]) < min_dist){
                min_dist = max(dist_from_node1[i], dist_from_node2[i]);
                ans = i;
            }
        }
        
        return ans;
    }
};
