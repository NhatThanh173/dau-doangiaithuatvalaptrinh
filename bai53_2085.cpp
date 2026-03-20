class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> freq1;
        unordered_map<string,int> freq2;

        for(string w : words1)
            freq1[w]++;

        for(string w : words2)
            freq2[w]++;

        int count = 0;

        for(auto &p : freq1){
            if(p.second == 1 && freq2[p.first] == 1)
                count++;
        }

        return count;
    }
};