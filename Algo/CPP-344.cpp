// 344. Reverse String
class Solution {
public:
    void rotateSpecific(vector<char>& s, int l, int r) {
            char temp;
            while(l<=r){
                temp = s[l];
                s[l] = s[r];
                s[r] = temp;
                l += 1;
                r -= 1;
            }
    }

    void reverseString(vector<char>& s) {
        rotateSpecific(s,0,s.size()-1);
    }
};