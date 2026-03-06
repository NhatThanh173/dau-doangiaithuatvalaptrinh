class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int freq[26] = {0};

        for(char c : s) {
            freq[c - 'a']++;
        }

        int count = 0;

        for(int i = 0; i < 26; i++) {
            if(freq[i] != 0) {
                if(count == 0) count = freq[i];
                else if(freq[i] != count) return false;
            }
        }

        return true;
    }
};