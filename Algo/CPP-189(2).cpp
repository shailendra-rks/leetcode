// 189. Rotate Array
// O(N)-time, O(n)-auxillary space

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int count = 0;
        vector<int> temp(nums.size());
        int size = nums.size();
        
        k = k%size;
        for(int i = 0; i<size;i++){
            if(ctr < k){
                temp[i] = nums[size-k+count];
            }
            else{
                temp[i] = nums[i-k];
            }
            count++;
        }
        nums = temp;
    }
};