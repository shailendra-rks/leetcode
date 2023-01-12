// 77. Combinations
class Solution {
public:
    vector<vector<int>> combineNext(int start, int n , int k){
        vector<vector<int>> result;
        vector<int> all;

        if(n == k){
            for(int i = start; i <= n; i++){
                all.push_back(i);
            }
            result.push_back(all);
            return result;
        }
        else if(k == 1){
            for(int i = start; i <= n; i++){
                result.push_back({i});
            }            
            return result;
        }
        for(int i = start; i<=n+1-k;i++){
            vector<vector<int>> temp = combineNext(i+1,n,k-1);
            for(int j = 0; j<temp.size();j++){
                temp[j].push_back(i);
                result.push_back(temp[j]);
            }
        }
        return result;
    }

    vector<vector<int>> combine(int n, int k) {
        return combineNext(1,n,k);
    }
};