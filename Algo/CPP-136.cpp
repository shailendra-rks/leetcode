//  136. Single Number
// bitwise logic ^ xor
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int n : nums){
            res = res^n;
        }
        return res;
    }
};