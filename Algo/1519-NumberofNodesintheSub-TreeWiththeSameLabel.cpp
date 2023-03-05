class Solution {
public:
    vector<int> cntNodswtSameLbl(int Node, int parent,vector<vector<int>>& adj,string& labels, vector<int>& res){
        vector<int> alphaCount(26);
        alphaCount[labels[Node] - 'a'] = 1;
        for(auto child : adj[Node]){
            if(child != parent){
                vector<int> childAlphaCount = cntNodswtSameLbl(child,Node,adj,labels,res);
                for(int i = 0; i<26; i++){
                    alphaCount[i] += childAlphaCount[i];
                }
            }            
        }

        int count = 0;
        
        res[Node] = alphaCount[labels[Node]-'a'];
        return alphaCount;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        vector<int> res(n,0);
        for(auto& edge : edges ){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        cntNodswtSameLbl(0,-1,adj,labels,res);
        // for(auto& str : belowMe){
        //     cout<<str<<endl;
        // }
        return res;
    }
};