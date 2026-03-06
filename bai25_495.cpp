class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        
        int tongThoiGianDoc = 0;

        for(int i = 0; i < timeSeries.size() - 1; i++){

            int khoangCach = timeSeries[i+1] - timeSeries[i];

            if(khoangCach >= duration){
                tongThoiGianDoc += duration;
            }
            else{
                tongThoiGianDoc += khoangCach;
            }
        }

        tongThoiGianDoc += duration;

        return tongThoiGianDoc;
    }
};