class Solution {
public:
    int findNthDigit(int n) {
        //if n is less than 10 then return n
        if(n<10)
            return n;
        //initializing the variables
        long long digitsinnumber=1;
        long long numberslikeit=9;
        long long basenumber=1;
        //finding the length of the number
        while(n > ( digitsinnumber * numberslikeit )){

            //reducing the number of digits which we dont need from the bottom
            n = n - digitsinnumber * numberslikeit;

            //number of digits in each number increases
            digitsinnumber++;
            //numbers like that become tenfold - 9 1 digit, 90 2 digit from 10 to 99
            numberslikeit = numberslikeit * 10;
            //base number becomes tenfold - 1 for 1 digit, 10 for 2 digit
            basenumber = basenumber * 10;

        }

        //finding the number
        int actualnumber = basenumber + (n-1)/digitsinnumber;

        //finding the digit in that number
        string s = to_string(actualnumber);
        return s[(n-1)%digitsinnumber]-'0';
        
    }
};
