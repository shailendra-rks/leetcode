//leetcode Q. 967. Numbers With Same Consecutive Differences
#include <iostream>
#include <vector>

class Solution {
public:
    vector<int> vec;
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i = 1; i<=9; i++){
            int cntr = 1;
            reoccur(i, k, n, cntr);
        }
        return vec;
    }

    void reoccur(int num, int k, int n, int cntr){
        if(cntr != n){
            int unit = num%10;
            if(k==0){
                int num1 = num*10 + unit;
                reoccur(num1, k, n, cntr+1);
            }
            else{
                if( unit-k >= 0){
                    int num1 = num*10 + unit - k;
                    reoccur(num1, k, n, cntr+1);
                }

                if( unit+k < 10){
                    int num2 = num*10 + unit + k;
                    reoccur(num2, k, n, cntr+1);
                }
            }
        }
        else{
            vec.push_back(num);
        }
    }
};
