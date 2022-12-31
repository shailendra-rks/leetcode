// 4. Median of Two Sorted Arrays
// O(m+n) 
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int S1 = nums1.size();
        int S2 = nums2.size();

        // keeping control array smaller
        if(S1>S2) return findMedianSortedArrays(nums2,nums1);

        // fir size N array we may say there are 2xN+1 positions for cut indeced(0,2*N)
        int left = 0, right = S1*2;

        while(left<=right) {

            // cut array nums1
            int mid1 = left + (right-left)/2;

            // cut array nums2 accordingly to have equal number of elements on both side
            // S1 + S2 + 1 - (mid1 +1) since mid is an index not position
            int mid2 = S1 + S2 - mid1; 

            //compute left and right values w.r.t. cuts in both array
            double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1-1)/2];
            double R1 = (mid1 == S1*2) ? INT_MAX : nums1[mid1/2];
            double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2-1)/2];
            double R2 = (mid2 == S2*2) ? INT_MAX : nums2[mid2/2];

            // shift nums1 cut to left if L1 > R2 or to right if L2>R1
            if(L1 > R2) right = mid1-1;
            else if(L2 > R1)  left = mid1+1;
            else return (max(L1,L2) + min(R1,R2))/2;
        }
        return -1;
    }
};