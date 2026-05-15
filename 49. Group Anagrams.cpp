class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& danhSachChuoi) {
        unordered_map<string, vector<string>> bangNhom;

        for (int i = 0; i < danhSachChuoi.size(); i++) {

            string chuoiGoc = danhSachChuoi[i];

            string chuoiSapXep = chuoiGoc;
            sort(chuoiSapXep.begin(), chuoiSapXep.end());

            bangNhom[chuoiSapXep].push_back(chuoiGoc);
        }

        vector<vector<string>> ketQua;
        for (auto cap : bangNhom) {
            ketQua.push_back(cap.second);
        }

        return ketQua;
    }
};
