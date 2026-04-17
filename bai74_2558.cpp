#include <queue>
#include <cmath>
using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {

        priority_queue<int> pq;

        // đưa vào heap
        for(int x : gifts)
            pq.push(x);

        // lặp k lần
        while(k--)
        {
            int top = pq.top();
            pq.pop();

            int newVal = sqrt(top); // floor tự động
            pq.push(newVal);
        }

        long long sum = 0;

        while(!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};