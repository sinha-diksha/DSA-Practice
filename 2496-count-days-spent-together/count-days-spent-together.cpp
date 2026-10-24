class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int aliceArriveMonth = stoi(arriveAlice.substr(0,2));
        int aliceArriveDate = stoi(arriveAlice.substr(3,2));
        int aliceDepartDate = stoi(leaveAlice.substr(3,2));
        int aliceDepartMonth = stoi(leaveAlice.substr(0,2));
        cout<<aliceArriveMonth<<" "<<aliceArriveDate<<endl;
        int aliceStartDay=0;

        for(int i=0; i<aliceArriveMonth-1; i++){
            aliceStartDay+=month[i];
        }
        aliceStartDay+=aliceArriveDate;
        int aliceLeaveDay=0;
        for(int i=0; i<aliceDepartMonth-1; i++){
            aliceLeaveDay+=month[i];
        }
        aliceLeaveDay+=aliceDepartDate;
        


        int bobArriveMonth = stoi(arriveBob.substr(0,2));
        int bobArriveDate = stoi(arriveBob.substr(3,2));
        int bobDepartDate = stoi(leaveBob.substr(3,2));
        int bobDepartMonth = stoi(leaveBob.substr(0,2));
        // cout<<aliceArriveMonth<<" "<<aliceArriveDate<<endl;
        int bobStartDay=0;
        for(int i=0; i<bobArriveMonth-1; i++){
            bobStartDay+=month[i];
        }
        bobStartDay+=bobArriveDate;
        int bobLeaveDay=0;
        for(int i=0; i<bobDepartMonth-1; i++){
            bobLeaveDay+=month[i];
        }
        bobLeaveDay+=bobDepartDate;
        int ans=0;
        cout<<aliceStartDay<<" "<<aliceLeaveDay<<" "<<bobLeaveDay<<" "<<bobStartDay<<endl;
        for(int i=aliceStartDay; i<=aliceLeaveDay; i++){
            if(i>=bobStartDay && i<=bobLeaveDay){
                ans++;
            }
        }

        return ans;
    }
};