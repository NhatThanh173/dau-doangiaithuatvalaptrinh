class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        int demKyTu[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            demKyTu[s[i] - 'a']++;
        }
        for (int i = 0; i < t.length(); i++) {
            demKyTu[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (demKyTu[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
