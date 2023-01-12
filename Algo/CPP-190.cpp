// 190. Reverse Bits
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t a = 0;
        int count = 0;
        while(n>0){
            a |= (n&1)<<(31-count);
            n = n>>1;
            count++;
        }
        return a;
    }
};

// class Solution {
// public:
//     uint32_t reverseBits(uint32_t n) {
//         uint32_t a = 0;
//         int count = 0;
//         while(n>0){
//             a += (n&1)<<(31-count);
//             n = n>>1;
//             count++;
//         }
//         return a;
//     }
// };

// class Solution {
// public:
//     uint32_t reverseBits(uint32_t n) {
//         if(n == 0) return n;
//         uint32_t a = 0;
//         int count = 0;
//         while(n>0){
//             a = (a*2) + (n&1);
//             n = n>>1;
//             count++;
//         }
//         a = a<<(32-count);
//         return a;
//     }
// };