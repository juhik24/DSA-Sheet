class Solution {
public:
    bool canChange(string start, string target) {
        string temp1 = "";
        string temp2 = "";
        unordered_map<int, vector<int>>mp1, mp2;
        for(int i = 0; i < start.length(); i++) {
            if(start[i] == 'L' || start[i] == 'R') {
                temp1 += start[i];
                mp1[start[i]].push_back(i);
            }
            if(target[i] == 'L' || target[i] == 'R') {
                temp2 += target[i];
                mp2[target[i]].push_back(i);
            }
            
        }
        if(temp1 == temp2) {
            if(mp1.find('L') != mp1.end()) {
                vector<int>v1 = mp1.at('L');
                vector<int>v2 = mp2.at('L');
                for(int i = 0; i < v1.size(); i++) {
                    if(v1[i] < v2[i]) {
                        return false;
                    }
                }
            }
            if(mp2.find('R') != mp2.end()) {
                vector<int>v3 = mp1.at('R');
                vector<int>v4 = mp2.at('R');
                for(int i = 0; i < v3.size(); i++) {
                    if(v3[i] > v4[i]) {
                        return false;
                    }
                }
            }
            return true;
        }
        return false;
    }
};