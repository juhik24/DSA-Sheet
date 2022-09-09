class Solution {
public:
    // Time = O(1), Space = O(1) 
    
    bool dist(vector<int>&p1, vector<int>&p2, unordered_set<int>&s) {
        if(p1[0] == p2[0] && p1[1] == p2[1]) return false; // if two coordinates are equal then it cannot be a square.
        // Then we'll find the difference b/w x and y coordinates
        int dx = p2[0]-p1[0];
        int dy = p2[1]-p1[1];
        // Then we find the distance
        int d = (dx*dx)+(dy*dy);
        s.insert(d);
        return true;
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int>s;
        if(!dist(p1, p2, s) || !dist(p1, p3, s) || !dist(p1, p4, s) || !dist(p2, p3, s) || !dist(p2, p4, s) || !dist(p3, p4, s)) return false;
        // In a square there can be two distances, one of side and other of diagonal
        // If there are more than 2 distances then it is not square
        else if(s.size() == 2) return true;
        else return false;
    }
};