// 35. Search-Insert Position
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        int mid;
        while(left<right){
            mid = left + (right-left)/2;
            if(nums[mid] < target){
                left = mid+1;
            }
            else{
                right = mid;
            }
        }
        if(nums[right] < target){
            return right+1;
        }
        else{
            return right;
        }
    }
};