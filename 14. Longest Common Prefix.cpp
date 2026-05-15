class Solution {
public:
    string longestCommonPrefix(vector<string>& danhSachChuoi) {
        if (danhSachChuoi.size() == 0) {
            return "";
        }
        string tienToChung = danhSachChuoi[0];
        for (int viTri = 0; viTri < tienToChung.length(); viTri++) {

            char kyTuHienTai = tienToChung[viTri];
            for (int i = 1; i < danhSachChuoi.size(); i++) {
                if (viTri >= danhSachChuoi[i].length() ||
                    danhSachChuoi[i][viTri] != kyTuHienTai) {
                    return tienToChung.substr(0, viTri);
                }
            }
        }
        return tienToChung;
    }
};
