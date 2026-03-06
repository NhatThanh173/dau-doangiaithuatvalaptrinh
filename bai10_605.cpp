class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int soHoaDaTrong = 0;

        for (int i = 0; i < flowerbed.size(); i++) {

            // kiểm tra ô hiện tại có trống không
            if (flowerbed[i] == 0) {

                int trai = (i == 0) ? 0 : flowerbed[i - 1];
                int phai = (i == flowerbed.size() - 1) ? 0 : flowerbed[i + 1];

                // nếu hai bên đều trống thì trồng được
                if (trai == 0 && phai == 0) {
                    flowerbed[i] = 1;
                    soHoaDaTrong++;

                    if (soHoaDaTrong >= n) {
                        return true;
                    }
                }
            }
        }

        return soHoaDaTrong >= n;
    }
};