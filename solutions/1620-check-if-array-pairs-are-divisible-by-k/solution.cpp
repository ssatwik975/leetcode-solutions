class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        if(arr.size()&1) return false;
        unordered_map<int,int>m;
        for(auto x:arr) m[(x%k + k)%k]++;          //store the count of remainders in a map.
        for(auto x:arr)
        {
            int rem=(x%k + k)%k;
            if(rem==0)                         //if the remainder for an element is 0 then the count of numbers that give this remainder must be even.
            { 
                if(m[rem] & 1) return false;            //if count of numbers that give this remainder is odd all pairs can't be made hence return false.
            }         
            else if(m[rem] != m[k - rem]) return false;    //if the remainder rem and k-rem do not have the same count then pairs can not be made 
        }
        return true;
    }
};
