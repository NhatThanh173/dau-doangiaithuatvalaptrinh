class Solution {
public:
    string capitalizeTitle(string title) {
        for(char &c : title){
            c = tolower(c);
        }

        int n = title.size();
        int start = 0;

        for(int i = 0; i <= n; i++){
            if(i == n || title[i] == ' '){
                int len = i - start;

                if(len > 2){
                    title[start] = toupper(title[start]);
                }

                start = i + 1;
            }
        }

        return title;
    }
};