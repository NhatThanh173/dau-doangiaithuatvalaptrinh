class Solution {
public:
    int lengthOfLastWord(string s) {

        int doDai = 0;
        int viTri = s.length() - 1;

        while (viTri >= 0 && s[viTri] == ' ') {
            viTri--;
        }

        while (viTri >= 0 && s[viTri] != ' ') {
            doDai++;
            viTri--;
        }

        return doDai;
    }
};