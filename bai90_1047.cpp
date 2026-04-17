#include <stack>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {

        stack<char> st;

        for(char c : s)
        {
            if(!st.empty() && st.top() == c)
            {
                st.pop(); // xóa cặp
            }
            else
            {
                st.push(c);
            }
        }

        string res = "";

        while(!st.empty())
        {
            res = st.top() + res;
            st.pop();
        }

        return res;
    }
};