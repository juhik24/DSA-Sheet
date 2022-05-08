class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        map<int, int>mp;
        map<int, int>::iterator it;
        for(int i = 0; i < n; i++) {
            it = mp.find(candyType[i]);
            if(it == mp.end()) {
                mp.insert(make_pair(candyType[i], 1));
            }
            else {
                it->second++;
            }
        }
        int m = mp.size();
        int cnt = n/2;
        if(m > cnt) return cnt;
        else return m;
    }
};