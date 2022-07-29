class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s;
        int n = wordList.size();
        bool f = false;
        for(int i = 0; i < n; i++) {
            if(wordList[i] == endWord) f = true;
            s.insert(wordList[i]);
        }
        if(f == false) return 0;
        queue<string>q;
        q.push(beginWord);
        int cnt = 0;
        while(!q.empty()) {
            cnt++;
            int size = q.size();
            while(size--) {
                string cur = q.front();
                q.pop();
                for(int i = 0; i < cur.length(); i++) {
                    string temp = cur;
                    for(char c = 'a'; c <= 'z'; c++) {
                        temp[i] = c;
                        if(cur == temp) continue;
                        if(temp == endWord) return cnt+1;
                        if(s.find(temp) != s.end()) {
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};