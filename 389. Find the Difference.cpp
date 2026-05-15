class Solution {
public:
    char findTheDifference(string s, string t) {
        
        char ketQua = 0;

        for(char kyTu : s){
            ketQua ^= kyTu;
        }

        for(char kyTu : t){
            ketQua ^= kyTu;
        }

        return ketQua;
    }
};