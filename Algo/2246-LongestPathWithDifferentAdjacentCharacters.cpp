class Solution {
public:
    int maxPathAtSelf(int node, int parent, vector<vector<int>>& adjlist, string& s, int& maxpath){
        int firstMaxChildPath = 0; 
        int scndMaxChildPath = 0;
        for(int child : adjlist[node]){
            int pathAtChild = maxPathAtSelf(child,node, adjlist, s, maxpath);
            
            if(s[node] == s[child]){
                continue;
            }

            if(pathAtChild > firstMaxChildPath){
                scndMaxChildPath = firstMaxChildPath;
                firstMaxChildPath = pathAtChild;
            }
            else if(pathAtChild > scndMaxChildPath){
                scndMaxChildPath = pathAtChild;
            }
        }
        maxpath = max(maxpath, firstMaxChildPath+scndMaxChildPath+1);
        return firstMaxChildPath+1;
    }

    int longestPath(vector<int>& parent, string s) {
        vector<vector<int>> adjlist(parent.size());
        int maxpath = 1;
        for(int i = 1; i<parent.size(); i++){
            adjlist[parent[i]].push_back(i);
        }
        maxPathAtSelf(0,-1, adjlist, s, maxpath);
        return maxpath;
    }
};