class Solution {
public:
    int secondHighest(string s) {
        int max1 = -1;
        int max2 = -1;

        for(char c : s){
            if(isdigit(c)){
                int num = c - '0';

                if(num > max1){
                    max2 = max1;
                    max1 = num;
                }
                else if(num > max2 && num != max1){
                    max2 = num;
                }
            }
        }

        return max2;
    }
};