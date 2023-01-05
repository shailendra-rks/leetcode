// 567. Permutation in String
class Solution {
public:
    bool matchMaps(int m1[], int m2[]) {
        for(int i =0; i<26; i++){
            if(m1[i] != m2[i]){
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {

        if(s1.size()>s2.size()) return false;

        int window_size = s1.size();
        int s1_map[26] = {0};
        int s2_map[26] = {0};

        for(int i = 0; i<window_size; i++) {
            s1_map[s1[i]-'a']++;
            s2_map[s2[i]-'a']++;
        }

        bool flag = matchMaps(s1_map, s2_map);
        int i = 1; 

        while(i+window_size-1<s2.size() && flag == false){
            s2_map[s2[i-1]-'a']--;
            s2_map[s2[i+window_size-1]-'a']++;
            flag = matchMaps(s1_map, s2_map);
            i++;
        }

        return flag;
    }
};