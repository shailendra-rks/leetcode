// 189. Rotate Array
// O(N), O(1)

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