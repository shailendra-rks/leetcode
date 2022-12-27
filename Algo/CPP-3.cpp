// 3. Longest Substring Without Repeating Characters
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int lensubstr = 0;
        int max = 0;

        for(int i = 0; i<s.size(); i++){
            char curr = s[i];
            int ctr = 1;
            for(int j = start; j < i; j++){
                if(curr == s[j]){
                    lensubstr = i-j-1;
                    start = j+1;
                    j = i;
                }
            }
            lensubstr = lensubstr + 1;
            if(max < lensubstr){
                max = lensubstr;
            }
        }
        return max;
    }
};