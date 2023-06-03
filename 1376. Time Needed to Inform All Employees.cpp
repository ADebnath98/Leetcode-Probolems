class Solution {
public:
    int res = 0;
    void dfs(vector<vector<int>>& adj, int currnode, vector<int>& informTime, int currtime) {
        if(!adj[currnode].size()) {
            res = max(res, currtime); return;
        }
        for(int& child : adj[currnode]) {
            dfs(adj, child, informTime, currtime + informTime[currnode]);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++) {
            if(i == headID) continue;
            adj[manager[i]].push_back(i);
        }
        dfs(adj, headID, informTime, 0);
        return res;
    }
};