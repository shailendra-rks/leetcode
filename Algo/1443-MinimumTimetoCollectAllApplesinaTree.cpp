class Solution {
public:
    int calMinTime(int node, int parent, vector<vector<int>>& adjlist, vector<bool>& hasApple){
        int time=0;
        int childTime=0;   

        for(auto& child : adjlist[node]){
            if(child != parent){
                childTime = calMinTime(child,node,adjlist,hasApple);
                if(childTime || hasApple[child]){
                    time += childTime + 2;
                }
            }
        }
        return time;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adjlist(n);
        for(auto& edge: edges){
            adjlist[edge[0]].push_back(edge[1]);
            adjlist[edge[1]].push_back(edge[0]);
        }
        return calMinTime(0,-1,adjlist,hasApple);
    }
};