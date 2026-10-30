class Solution {
public:
    int height(int a, int b){
        int h=0;
        int ab=true;
        while(a>0 || b>0){
            if(ab){
                if(a>=h+1) {
                    a-=(h+1);
                    h++;
                }else{
                    return h;
                }
                ab=!ab;
            }else{
                if(b>=h+1) {
                    b-=(h+1);
                    h++;
                }else{
                    return h;
                }
                ab=!ab;
            }
        }

        return h;
    }
    int maxHeightOfTriangle(int red, int blue) {
        return max(height(red, blue), height(blue, red));
    }
};