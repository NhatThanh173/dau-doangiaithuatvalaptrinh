class Solution {
public:
    bool isSubsequence(string s, string t) {

        int chiSoS = 0; 
        int chiSoT = 0; 

        
        while (chiSoS < s.length() && chiSoT < t.length()) {

            
            if (s[chiSoS] == t[chiSoT]) {
                chiSoS++;
            }

            
            chiSoT++;
        }

        
        return chiSoS == s.length();
    }
};
