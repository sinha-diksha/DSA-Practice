class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n= intervals.size();
        
        vector<vector<int>> ans;
        bool isNewUsed= false;
        if(n>0 && intervals[0][0]<=newInterval[0])            {
            ans.push_back(intervals[0]);
        }else{
            ans.push_back(newInterval);
            isNewUsed = true;
        }
        
        int start = isNewUsed ? 0 : 1;
        cout<<start<<endl;
        for(int i=start; i<n; ){
             if(isNewUsed || intervals[i][0]<newInterval[0]){
                if(ans.back()[1]>=intervals[i][0]){
                    ans.back()[1]=max(ans.back()[1], intervals[i][1]);
                }else{
                    ans.push_back(intervals[i]);
                }
                i++;
             }else{
                if(ans.back()[1]>=newInterval[0]){
                    ans.back()[1]=max(ans.back()[1], newInterval[1]);
                   
                }else{
                    ans.push_back(newInterval);
                }
                 isNewUsed=true;
             }
            
        }
        
        if(!isNewUsed){
            if(ans.back()[1]>=newInterval[0]){
                    ans.back()[1]= max(ans.back()[1], newInterval[1]);
                    isNewUsed= true;
                }

            else ans.push_back(newInterval);
        }
        
        return ans;
    }
}; 