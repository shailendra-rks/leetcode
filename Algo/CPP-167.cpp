// 167. Two Sum II - Input Array Is Sorted
class Solution {
public:
    int binarySearch(vector<int>& numbers, int target, int left, int right) {
        if(left<=right){
            int mid = left + (right - left)/2;
            if(numbers[mid] == target){
                return mid;
            }
            else if(numbers[mid] < target){
                return binarySearch(numbers, target, mid+1, right);
            }
            else{
                return binarySearch(numbers, target, left, mid-1);
            }
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        int pos;
        vector<int> rslt(2,-1);
        for(int i = 0; i<numbers.size();i++){
            pos = binarySearch(numbers, target-numbers[i], i+1, numbers.size()-1);
            if(pos != -1){
                rslt[0] = i+1;
                rslt[1] = pos+1;
                break;
            }
        }
        return rslt;
    }
};