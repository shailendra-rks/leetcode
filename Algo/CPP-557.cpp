// 557. Reverse Words in a String III
class Solution {
public:
    void rotateSpecific(string& s, int l, int r) {
            char temp;
            while(l<=r){
                temp = s[l];
                s[l] = s[r];
                s[r] = temp;
                l += 1;
                r -= 1;
            }
    }
    string reverseWords(string s) {
        int l =0;
        for(int i = 0; i<s.size(); i++) {
            if(s[i] == ' '){
                rotateSpecific(s, l, i-1);
                l = i+1;
            }
        }
        if(l < s.size()){
            rotateSpecific(s, l, s.size()-1);
        }
        return s;
    }
};