class Solution {
public:
    static bool compare(vector<int>&a, vector<int>&b) {
        return a[1] < b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare);
        int maxUnits = 0;
        int cnt = 0;
        int n = boxTypes.size();
        for(int i = n-1; i >= 0; i--) {
            if(cnt+boxTypes[i][0] <= truckSize) {
                cnt += boxTypes[i][0];
                maxUnits = maxUnits + (boxTypes[i][0]*boxTypes[i][1]);
            }
            else {
                int a = cnt+boxTypes[i][0];
                int b = a - truckSize;
                int c = boxTypes[i][0]-b;
                cnt += c;
                maxUnits = maxUnits + (c*boxTypes[i][1]);
                break;
            }
        }
        return maxUnits;
    }
};