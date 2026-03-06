class Solution {
public:
    vector<string> fizzBuzz(int n) {
        
        vector<string> ketQua;

        for(int i = 1; i <= n; i++){

            if(i % 3 == 0 && i % 5 == 0){
                ketQua.push_back("FizzBuzz");
            }
            else if(i % 3 == 0){
                ketQua.push_back("Fizz");
            }
            else if(i % 5 == 0){
                ketQua.push_back("Buzz");
            }
            else{
                ketQua.push_back(to_string(i));
            }

        }

        return ketQua;
    }
};