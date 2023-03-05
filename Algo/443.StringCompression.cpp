class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0;
        for(int i = 0; i<chars.size();){
            char selectedChar = chars[i];
            int count = 0;
            while(i<chars.size() && chars[i] == selectedChar){
                count++;
                i++;
            }
            
            chars[index] = selectedChar;
            index++;

            if(count > 1){
                string str = to_string(count);
                for(char c: str){
                    chars[index] = c;
                    index++;
                }
            }
        }
        return index;
    }
};