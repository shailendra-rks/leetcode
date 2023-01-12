// 784. Letter Case Permutation
class Solution {
private:
    vector<string> ans;
public:
    void recursivePerm(int i, string s){
        bool flag = true;
        while(i < s.size()){
            if(tolower(s[i]) != toupper(s[i])){
                s[i] = tolower(s[i]);
                recursivePerm(i+1,s);
                s[i] = toupper(s[i]);
                recursivePerm(i+1,s);
                flag = false;
                break;
            }
            else{
                i++;
            }
        }
        if(flag){
            ans.push_back(s);
        }
    }

    vector<string> letterCasePermutation(string s) {
        recursivePerm(0,s);
        return ans;
    }
};