class Solution {
public:
    // Time = O(n), Space = O(1) 
    
    string reverseWords(string s) {
        int n = s.length();
        reverse(s.begin(), s.end());
        int i = 0, j = 0, k = 0;
        while(i < n) {
            while(i < n && s[i] != ' ') {
                s[j] = s[i];
                j++; i++;
            }
            if(k < j) {
                reverse(s.begin()+k, s.begin()+j);
                if(j == n) break;
                s[j] = ' ';
                j++;
                k = j;
            }
            i++;
        }
        if(j > 0 && s[j-1] == ' ') j--;
        s.resize(j);
        return s;
    }
};

// Brute force = Time = O(n) , Space = O(n) 

// string reverseWords(string s) {
//         int n = s.length();
//         string ans = "";
//         stack<string>st;
//         for(int i = 0; i < n; i++) {
//             if(s[i] == ' ') continue;
//             string temp = "";
//             while(i < n && s[i] != ' ') {
//                 temp += s[i];
//                 i++;
//             }
//             st.push(temp);
//         }
//         while(st.size() > 0) {
//             if(ans == "") {
//                 ans += st.top();
//             }
//             else {
//                 ans += " " + st.top();
//             }
//             st.pop();
//         }
//         return ans;
//     }