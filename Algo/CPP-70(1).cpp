// 70. Climbing Stairs
// Time Limit Exceeded(top to bottom)
class Solution {
public:
    int climbStairs(int n) {
        if(n < 4) return n;
        return climbStairs(n-1) + climbStairs(n-2);
    }
};