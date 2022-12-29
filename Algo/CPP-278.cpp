// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
// 278. First Bad Version

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n;
        int mid;
        while(high>low){
            mid = low + (high-low)/2;
            if(isBadVersion(mid)){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};