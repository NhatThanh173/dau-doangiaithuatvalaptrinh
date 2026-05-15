class Solution {
public:
    bool wordPattern(string pattern, string s) {

        vector<string> danhSachTu;
        string tu = "";

        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                danhSachTu.push_back(tu);
                tu = "";
            }
            else{
                tu += s[i];
            }
        }

        danhSachTu.push_back(tu);

        if(danhSachTu.size() != pattern.size()){
            return false;
        }

        unordered_map<char, string> mapChuSangTu;
        unordered_map<string, char> mapTuSangChu;

        for(int i = 0; i < pattern.size(); i++){

            char chu = pattern[i];
            string tuHienTai = danhSachTu[i];

            if(mapChuSangTu.count(chu) && mapChuSangTu[chu] != tuHienTai){
                return false;
            }

            if(mapTuSangChu.count(tuHienTai) && mapTuSangChu[tuHienTai] != chu){
                return false;
            }

            mapChuSangTu[chu] = tuHienTai;
            mapTuSangChu[tuHienTai] = chu;
        }

        return true;
    }
};