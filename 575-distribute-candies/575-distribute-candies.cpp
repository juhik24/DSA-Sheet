class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        map<int, int>mp;
        for(int i = 0; i < n; i++) {
            mp[candyType[i]]++;
        }
        int m = mp.size();
        int cnt = n/2;
        if(m > cnt) return cnt;
        else return m;
    }
};