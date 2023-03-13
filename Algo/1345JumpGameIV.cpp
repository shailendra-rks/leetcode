class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> mp;
        vector<bool> seen(arr.size(),false);
        queue<int> nodeQueue;
        int step = 0;
        int n = arr.size();

        for(int i = 0; i< arr.size(); i++){
            mp[arr[i]].push_back(i);
        }

        nodeQueue.push(0);
        seen[0] = true;

        while(!nodeQueue.empty()){
            int size = nodeQueue.size();
            for(int i =0; i < size; i++){
                int curr = nodeQueue.front();
                if(curr == n-1){
                    return step;
                }
                nodeQueue.pop();
                if(curr-1 > -1 && !seen[curr-1]){
                    nodeQueue.push(curr-1);
                    seen[curr-1] = true;
                }
                if(curr+1 < n && !seen[curr+1]){
                    nodeQueue.push(curr+1);
                    seen[curr+1] = true;
                }
                for(int idx : mp[arr[curr]] ){
                    if(idx != curr && !seen[idx]){
                        nodeQueue.push(idx);
                        seen[idx] = true;
                    }
                }
                mp.erase(arr[curr]);
            }
            step++;
        }
        return step;
    }
};