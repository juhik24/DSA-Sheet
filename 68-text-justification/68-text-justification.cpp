class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string>ans;
        int i = 0;
        while(i < n) {
            int chCount = words[i].length();
            int j = i+1;
            int wordCnt = 0;
            while(j < n && chCount+wordCnt+words[j].length()+1 <= maxWidth) {
                chCount+= words[j].length();
                wordCnt++;
                j++;
            }
            int vacant = maxWidth-chCount;
            int spaces = wordCnt == 0? 0:vacant/wordCnt;
            int extra = wordCnt == 0? 0 : vacant%wordCnt;
            if(j == n){
                spaces = 1;
                extra = 0;
            }
            string temp = "";
            for(int k = i; k < j; k++) {
                temp += words[k];
                if(k == j-1) break;
                for(int a = 0; a < spaces; a++) {
                    temp += " ";
                }
                if(extra > 0) {
                    temp += " ";
                    extra--;
                }
            }
            while(temp.length() < maxWidth) temp += " ";
            ans.push_back(temp);
            i = j;
        }
        return ans;
    }
};