class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<char, char> right;
        unordered_map<char, char> left;
        right['N']='E';
        right['S']='W';
        right['E']='S';
        right['W']='N';

        left['N']='W';
        left['S']='E';
        left['E']='N';
        left['W']='S';

        int n=commands.size();
        int oLength=obstacles.size();
        char direction = 'N';
        int x=0;
        int y=0;
        long ans=0;
        map<pair<int,int>, int> obMap;
        for(int i=0; i<oLength; i++){
            int x=obstacles[i][0];
            int y=obstacles[i][1];
            obMap[{x,y}]=1;
        }
        for(int i=0; i<n; i++){
            if(commands[i]==-1){
                direction=right[direction];
            }else if(commands[i]==-2){
                direction=left[direction];
            }else{
                if(direction =='N' || direction =='S'){
                    int value= direction=='N'?1:-1;
                    // y will change
                    for(int j=0; j<commands[i]; j++){
                        int newY=y+value;
                        if(obMap.count({x,newY})>0){
                            break;
                        }
                        y=newY;

                    }
                }else{
                    int value= direction=='E'?1:-1;
                    // x will change
                    for(int j=0; j<commands[i]; j++){
                        int newX=x+value;
                        if(obMap.count({newX,y})>0){
                            break;
                        }
                        x=newX;
                    }
                }
                long val=x*x + y*y;
                ans=max(ans,val);
            }
        }

        return ans;
    }
};