class Solution {
public:
    string thousandSeparator(int n) {
        string s = to_string(n);
        string res = "";
        int count = 0;

        for(int i = s.length() - 1; i >= 0; i--) {
            res = s[i] + res;
            count++;

            if(count == 3 && i != 0) {
                res = "." + res;
                count = 0;
            }
        }

        return res;
    }
};