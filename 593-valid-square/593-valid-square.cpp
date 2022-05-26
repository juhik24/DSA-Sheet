class Solution {
public:
    unordered_set<int>s;
    
    bool dist(vector<int>&p1, vector<int>&p2) {
        if(p1[0] == p2[0] && p1[1] == p2[1]) return false;
        int dx = p2[0]-p1[0];
        int dy = p2[1]-p1[1];
        int d = (dx*dx)+(dy*dy);
        s.insert(d);
        return true;
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if(!dist(p1, p2) || !dist(p1, p3) || !dist(p1, p4) || !dist(p2, p3) || !dist(p2, p4) || !dist(p3, p4)) return false;
        else if(s.size() == 2) return true;
        else return false;
    }
};