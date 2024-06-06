class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize != 0){
            return false;
        }
        if(n==1 && groupSize==1){
            return true;
        }
        sort(hand.begin(),hand.end());
        
        for(int i=0;i<n;i++){
            if(hand[i]!=-1){
                // int k=i;
                int a=1;
                int num=hand[i];
                hand[i]=-1;
                int j=i+1;
                while(j<n){   //1 2 2 3 3 4 6 7 8
                    if(hand[j]==num+1){
                        num=hand[j];
                        hand[j]=-1;
                        j++;
                        a++;
                    }
                    else{
                        j++;
                    } 
                    if(a==groupSize){
                        j=n;
                    }
                }
                if(a<groupSize){
                    return false;
                }
            }
        }
        return true;
    }
    
};
