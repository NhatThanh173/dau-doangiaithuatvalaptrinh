#include <sstream>

class Solution {
public:
    string toGoatLatin(string sentence) {
        stringstream ss(sentence);
        string word, result = "";
        int index = 1;

        while (ss >> word) {
            char first = word[0];

            // kiểm tra nguyên âm
            if(first=='a'||first=='e'||first=='i'||first=='o'||first=='u'||
               first=='A'||first=='E'||first=='I'||first=='O'||first=='U'){
                word = word + "ma";
            } 
            else {
                word = word.substr(1) + first + "ma";
            }

            // thêm a theo index
            word += string(index, 'a');

            if(result != "") result += " ";
            result += word;

            index++;
        }

        return result;
    }
};