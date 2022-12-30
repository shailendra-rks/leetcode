// 977. Squares of a Sorted Array
// "Kyonki Ak'Shit'o ko INT_MAX nahi chahiye"
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        // searching for the sign flip

        int left = 0 , right = nums.size()-1;
        int mid;
        while(right-left>1){
            mid = left + (right-left)/2;
            if(nums[mid]<0){
                left = mid;
            }
            else{
                right = mid;
            }
        }
        
        // boundry condition when only 1 element is present
        if(right==left){
            right = right+1;
        }

        // swaping around left and right index of the flip of sign(including flip)

        vector<int> new_nums;
        int left_val;
        int right_val;
        while(left>=0 && right<nums.size()){
            left_val = nums[left]*nums[left];
            right_val = nums[right]*nums[right];

            if(left_val < right_val){
                new_nums.push_back(left_val);
                left = left-1;
            }
            else{
                new_nums.push_back(right_val);
                right = right+1;
            }
        }
        while(left>=0){
            left_val = nums[left]*nums[left];
            new_nums.push_back(left_val);
            left = left-1;
        }
        while(right<nums.size()){
            right_val = nums[right]*nums[right];
            new_nums.push_back(right_val);
            right = right+1;
        }
        return new_nums;
    }
};