// 46. Permutations
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int itrate = nums.size();
        vector<vector<int>> ans;
        vector<int> copy = nums;

        if(itrate == 1){
            ans.push_back(nums);
        }

        if(itrate < 4){
            while(itrate){
                for(int i = nums.size()-1; i>0; i--){
                    int temp = nums[i-1];
                    nums[i-1] = nums[i];
                    nums[i] = temp;
                    ans.push_back(nums);
                }
                itrate--;
            }
            return ans;  
        }

        int pos = 0;
        while(pos<itrate){
            vector<vector<int>> mid_man;
            int temp = nums[itrate-1];
            nums.pop_back();
            mid_man = permute(nums);
            for(int j = 0; j<mid_man.size();j++){
                mid_man[j].push_back(temp);
                ans.push_back(mid_man[j]);
            }
            nums = copy;
            temp = nums[itrate-1];
            nums[itrate-1] = nums[pos];
            nums[pos] = temp;
            pos++;
        }
        return ans;
    }
};