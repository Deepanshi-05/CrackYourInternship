class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int st = 0;
      int e = 0;
      int maxlen = 0;
      unordered_map<char,int> map;

      for(e=0; e<s.length(); e++){
        char currchar = s[e];

        if(map.find(currchar) != map.end() && map[currchar] >= st){
            st = map[currchar] + 1;
        }

        map[currchar] = e;

        maxlen = max(maxlen, e - st + 1);
      }  
      return maxlen;
    
    }
};