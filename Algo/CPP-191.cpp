// 191. Number of 1 Bits
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            if(n&1)
                count ++;
            n = n>>1;
        }
        return count;
    }
};

// class Solution {
// public:
//     int hammingWeight(uint32_t n) {
//         int count = 0;
//         for(int i= 0; i<32; i++){
//             count += n%2;
//             n = n>>1;
//         }
//         return count;
//     }
// };