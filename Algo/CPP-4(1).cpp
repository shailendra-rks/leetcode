// 4. Median of Two Sorted Arrays
// O(m+n) 
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int a = 0, b = 0;
        int curr = 0,last;
        int cut_right = (nums1.size()+nums2.size()+1)/2;
        for (int i = 0; i<=cut_right; i++){
            if(a<nums1.size() && b<nums2.size()){
                if(nums1[a]<nums2[b]){
                    last = curr;
                    curr = nums1[a++];
                }
                else{
                    last = curr;
                    curr = nums2[b++];
                }
            }
            else{
                if(a<nums1.size()){
                    last = curr;
                    curr = nums1[a++];
                }
                else if(b<nums2.size()){
                    last = curr;
                    curr = nums2[b++];
                }
            }
        }
        if(nums1.size()+nums2.size() == 1){
            last = curr;
        }
        if((nums1.size()+nums2.size())%2 == 0){
            return double(curr+last)/2;
        }
        else{
            return double(last);
        }
    }
};