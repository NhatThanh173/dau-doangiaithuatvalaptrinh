class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int tre = 0;
        int banh = 0;
        int soTreHaiLong = 0;

        while(tre < g.size() && banh < s.size()){

            if(s[banh] >= g[tre]){
                soTreHaiLong++;
                tre++;
                banh++;
            }
            else{
                banh++;
            }

        }

        return soTreHaiLong;
    }
};