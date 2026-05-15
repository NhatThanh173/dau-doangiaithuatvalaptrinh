class Solution {
public:
    string reformatNumber(string number) {
        string digits = "";

        // Bước 1: lấy chỉ các chữ số
        for(char c : number){
            if(isdigit(c))
                digits += c;
        }

        string res = "";
        int i = 0;
        int n = digits.size();

        while(n - i > 4){
            res += digits.substr(i,3) + "-";
            i += 3;
        }

        if(n - i == 4){
            res += digits.substr(i,2) + "-";
            res += digits.substr(i+2,2);
        }
        else{
            res += digits.substr(i);
        }

        return res;
    }
};