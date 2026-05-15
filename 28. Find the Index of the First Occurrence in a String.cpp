class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int doDaiHaystack = haystack.size();
        int doDaiNeedle = needle.size();

        for(int i = 0; i <= doDaiHaystack - doDaiNeedle; i++){

            int j = 0;

            while(j < doDaiNeedle && haystack[i + j] == needle[j]){
                j++;
            }

            if(j == doDaiNeedle){
                return i;
            }
        }

        return -1;
    }
};