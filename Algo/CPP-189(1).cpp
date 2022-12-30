// 189. Rotate Array
// O(N), O(k)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums);
        int r = nums.size();        
        k = k%(r);
        for(int i = 0; i<r;i++){
            temp[(i+k)%r] = nums[i];
        }
        nums = temp;
    }
};