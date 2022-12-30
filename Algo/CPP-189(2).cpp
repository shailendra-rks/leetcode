// 189. Rotate Array
// O(N), O(n)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int ctr = 0;
        vector<int> temp(nums.size());
        int r = nums.size();
        
        k = k%(r);
        for(int i = 0; i<r;i++,ctr++){
            if(ctr < k){
                temp[i] = nums[r-k+ctr];
            }
            else{
                temp[i] = nums[i-k];
            }
        }
        nums = temp;
    }
};