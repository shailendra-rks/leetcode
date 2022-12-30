// 283. Move Zeroes
// Optimal space, sub-optimal operation
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ctr_zr = 0;
        int left = 0;

        for (int i = 0; i<nums.size(); i++){
            if(nums[i] == 0){
                ctr_zr++;
            }
            else{
                nums[left++] = nums[i];
            }
        }
        while(left<nums.size()){
            nums[left++] = 0;
        }
    }
};