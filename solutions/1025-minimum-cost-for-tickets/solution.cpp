class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<bool> ifTravelled(366,false);// boolean vector to keep track of days we travelled
        for(int i:days)ifTravelled[i]=true;
        vector<int> dp(366,INT_MAX);       //this vector keeps track of costs till the respective days
        dp[0]=0;                           //initialisation
        for(int i=1;i<366;i++){
            if(!ifTravelled[i])            //for the days we didn't travel update it with value of previous day
            {
                dp[i]=dp[i-1];
                continue;
             }
            int one=dp[i-1]+costs[0];               //one day pass cost 
            int seven=dp[max(i-7,0)]+costs[1];      //seven day pass cost,handled when i-7<0
            int thirty=dp[max(i-30,0)]+costs[2];    //thirty day pass cost,we have handled the condition when i-30<0
            
                 dp[i]=std::min({one,seven,thirty}); //update the value with the minimum of all three passes
      }   
         return dp[365] ;                            //finally return last day value
    }
};
