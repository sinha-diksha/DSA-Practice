class Solution {
public:
    pair<int,int> function(string arrive, string leave){
        vector<int> month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int personArriveMonth = stoi(arrive.substr(0,2));
        int personArriveDate = stoi(arrive.substr(3,2));
        int personDepartDate = stoi(leave.substr(3,2));
        int personDepartMonth = stoi(leave.substr(0,2));
        int personStartDay=0;

        for(int i=0; i<personArriveMonth-1; i++){
            personStartDay+=month[i];
        }
        personStartDay+=personArriveDate;
        int personLeaveDay=0;
        for(int i=0; i<personDepartMonth-1; i++){
            personLeaveDay+=month[i];
        }
        personLeaveDay+=personDepartDate;

        return {personStartDay, personLeaveDay};
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        auto alice = function(arriveAlice, leaveAlice);
        auto bob = function(arriveBob, leaveBob);
        int aliceStartDay = alice.first;
        int aliceLeaveDay = alice.second;
        int bobStartDay = bob.first;
        int bobLeaveDay = bob.second;
        int ans=0;
        for(int i=aliceStartDay; i<=aliceLeaveDay; i++){
            if(i>=bobStartDay && i<=bobLeaveDay){
                ans++;
            }
        }

        return ans;
    }
};