/*
You are playing the Bulls and Cows game with your friend.
You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:
The number of "bulls", which are digits in the guess that are in the correct position.
The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.
Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.
The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.
 
Example 1:
Input: secret = "1807", guess = "7810"
Output: "1A3B"
Explanation: Bulls are connected with a '|' and cows are underlined:
"1807"
  |
"7810"
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();
        string ans = "";
        int b = 0;
        int c =0;
        int sc[10]={0};
        int gs[10]={0};
        for(int i=0;i<n;i++){
            if(secret[i] == guess[i]){
                b++;
            }
            else{

               
                sc[secret[i] - '0' ]++;
                gs[guess[i] - '0' ]++;


            }
        }
        for(int j=0;j<10;j++){
            c += min(sc[j],gs[j]);
           
        }
      ans += to_string(b);
      ans +='A';
      ans += to_string(c);
      ans +='B';
 
           return ans;
        
    }
    
};