class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        vector<int> stringAvailable;
        for(int i=0; i<n; i++){
            if(words[i]==target){
                stringAvailable.push_back(i);
            }
        }
        int m=stringAvailable.size();
        if(m==0){
            return -1;
        }
        int minDistance=INT_MAX;
        for(int i=0; i<m; i++){
            int absVal=abs(startIndex-stringAvailable[i]);
            int val2=n-absVal;
            minDistance=min(minDistance, min(absVal, val2));
        }

        return minDistance;
    }
};