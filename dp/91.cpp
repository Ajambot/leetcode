class Solution {
public:
    // idea: curways is the # of ways to decode substring finishing at index i (curways[i]).
    // if you can make a 1 digit number > 0 ending at s[i], then add curways[i-1] to curways[i]
    // if you can make a 2 digit number <= 26 ending at s[i], add curways[i-2] to curways[i]
    // For space optimization, p = curways[i-1] and pp = curways[i-2].
    int numDecodings(string s) {
        if (s[0] == '0') return 0;

        int p = 1, pp = 1;
        for (int i=0; i<s.length(); i++) {
            int curways = 0;
            if (s[i] != '0') {
                curways += p;
            } 
            
            if (i > 0 && stoi(s.substr(i-1, 2)) >= 10 && stoi(s.substr(i-1, 2)) <= 26) {
                curways += pp;
            }

            pp = p;
            p = curways;
        }
        return p;
    }
};
