class Solution {
public:
    // Time = O(log n), Space = O(1) 
    
    bool isPalindrome(int x) {
        //when x < 0, x is not a palindrome.
        // Also if the last digit of the number is 0, in order to be a palindrome,
        // the first digit of the number also needs to be 0.
        if(x < 0 || (x%10 == 0 && x != 0)) return false;
        
        int reverse = 0;
        while(reverse < x) {
            reverse = (reverse*10) + x%10;
            x = x/10;
        }
         // When the length is an odd number, we can get rid of the middle digit by revertedNumber/10
        // For example when the input is 12321, at the end of the while loop we get x = 12, revertedNumber = 123,
        // since the middle digit doesn't matter in palidrome(it will always equal to itself), we can simply get rid of it.
        if(x == reverse || reverse/10 == x) return true;
        return false;
    }
};