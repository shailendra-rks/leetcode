// 198. House Robber with house position
class Solution {
public:
    int rob(vector<int>& nums) {
        int a = 0;
        int b = 0;

        string path_a = "";
        string path_b = "";
        string path_temp;

        for(int i = 0; i<nums.size();i++){
             if(b < (a + nums[i])){
                path_temp = path_b;
                path_b = path_a  + to_string(i+1) + ",";
                path_a = path_temp;
            }
            else{
                path_a = path_b;
            }

            int temp = b;
            b = max(b,a+nums[i]);
            a = temp;      
        }

        cout<<path_b;
        return b;
    }
};