// 189. Rotate Array
// O(N)-time, O(1)-auxillary space

class Solution {
public:
    void rotateSpec(vector<int>& nums, int l, int r) {
        int temp;
        while(l<=r){
            temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            l += 1;
            r -= 1;
        }
    }

    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        rotateSpec(nums,0,nums.size()-1);
        rotateSpec(nums,0,k-1);
        rotateSpec(nums,k,nums.size()-1);
    }
};