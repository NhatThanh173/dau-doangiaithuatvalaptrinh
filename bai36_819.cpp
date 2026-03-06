class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> freq;

        // chuẩn hóa chuỗi
        for(char &c : paragraph){
            if(isalpha(c)) c = tolower(c);
            else c = ' ';
        }

        stringstream ss(paragraph);
        string word;
        string ans = "";
        int maxCount = 0;

        while(ss >> word){
            if(ban.count(word)) continue;

            freq[word]++;
            if(freq[word] > maxCount){
                maxCount = freq[word];
                ans = word;
            }
        }

        return ans;
    }
};