#include<iostream>
using namespace std;

bool isPalindrome(int num){

    //Negative numbers and the numbers that end with 0 except 0,are not palindrome
    if( num<0 || (num%10 == 0 && num!=0) ){
        return false;
    }

    int reversetHalf = 0;
    while(num > reversetHalf){

        reversetHalf = (reversetHalf*10)+num%10;
        num/=10;

        //for even digits : num = reverseHalf
        // fro odd digits : num = reverseHalf/10 (chop offs the middle digit)
    }
    return num == reversetHalf ||  num == reversetHalf/10;

}


int main(){

    cout<<isPalindrome(541)<<endl;

    return 0;
}