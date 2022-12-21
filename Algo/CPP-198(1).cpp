// 198. House Robber
class Solution {
public:
    int rob(vector<int>& nums) {
        int a = 0;
        int b = 0;
        for(int i = 0; i<nums.size();i++){
            int temp = b;
            b = max(b,a+nums[i]);
            a = temp;
        }
        return b;
    }
};