// 704. Binary Search
// Recursive approach
class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int low, int high){
        if(high>=low){
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]<target){
                return binarySearch(nums, target, mid+1, high);
            }
            else{
                return binarySearch(nums, target, low, mid-1);
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int high = nums.size();
        return binarySearch(nums, target, 0, high-1);
    }
};