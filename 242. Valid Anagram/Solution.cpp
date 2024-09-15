class Solution {
public:
    bool isAnagram(string s, string t) {
          if (s.length() != t.length()) {
        return false;
    }
        unordered_map<char,int> freqmap;
        for(int i=0; i < s.length(); i++){
            freqmap[s[i]]++;
        }
        for(char c: t){
            if(freqmap[c] == 0){
                return false;
            }
            freqmap[c]--;
        }
        return true;
    }
};