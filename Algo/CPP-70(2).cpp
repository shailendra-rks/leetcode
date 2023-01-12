// 70. Climbing Stairs
// dp concept bottom to up
class Solution {
public:
    int climbStairs(int n) {
        if(n < 3) return n;
        
        int a = 1; // for 1 step stairs
        int b = 2; // for 2 steps stairs

        for(int i = 0; i<n-2; i++){
            int curr = a +b;
            a = b;
            b =curr;
        }
        return b;
    }
};