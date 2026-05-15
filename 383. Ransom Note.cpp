class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        int demChuCai[26] = {0};

        // Đếm số chữ trong magazine
        for (int i = 0; i < magazine.length(); i++) {
            demChuCai[magazine[i] - 'a']++;
        }

        // Kiểm tra ransomNote
        for (int i = 0; i < ransomNote.length(); i++) {

            demChuCai[ransomNote[i] - 'a']--;

            if (demChuCai[ransomNote[i] - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};