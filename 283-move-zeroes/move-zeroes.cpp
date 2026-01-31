class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n=arr.size();
        int i=0;
        for(int j=1; j<n; j++){
            if(arr[i]==0 && arr[j]!=0){
                swap(arr[i], arr[j]);
                i++;
            }else if(arr[i]!=0){
                i++;
            }
        }
    }
};