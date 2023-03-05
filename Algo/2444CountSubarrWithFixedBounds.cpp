class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minIdx = -1;
        int maxIdx = -1;
        int leftBound = -1;
        long count = 0;

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] < minK || nums[i] > maxK){
                leftBound = i;
                minIdx = -1;
                maxIdx = -1;
            }
            else{
                if(nums[i] == minK){
                    minIdx = i;
                }
                if(nums[i] == maxK){
                    maxIdx = i;
                }
                // int tempCount = min(minIdx,maxIdx)-leftBound;
                count += (min(minIdx,maxIdx)-leftBound)>0 ? min(minIdx,maxIdx)-leftBound : 0;
            }
        }
        return count;
    }
};