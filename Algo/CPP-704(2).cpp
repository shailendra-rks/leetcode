// 704. Binary Search
// Iterative Approach
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int high = nums.size() -1;
        int low = 0;
        int mid;
        while(high-low>1){
            mid = low + (high-low)/2;
            if(nums[mid]<target){
                low = mid +1;
            }
            else{
                high = mid;
            }
        }
        if(nums[low] == target){
            return low;
        }
        else if(nums[high] == target){
            return high;
        }
        else{
            return -1;
        }
    }
};