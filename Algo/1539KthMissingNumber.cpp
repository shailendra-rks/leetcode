class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int leftBound = 0;
        int rightBound = arr.size();

        if(arr[leftBound]-1 >= k){
            return k;
        }
        if(arr[rightBound-1]-rightBound < k){
            return k + rightBound;
        }
        
        while(leftBound < rightBound){
            int mid = leftBound + (rightBound - leftBound)/2;
            if(arr[mid] - mid - 1 < k){
                leftBound = mid+1;
            }
            else{
                rightBound = mid;
            }
        }
        return k + leftBound;
    }
};