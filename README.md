/*1st parameter is need to a sting which contain with {} simbol. second pamaneter how many args you want to add 
    in the string. 3rd add the value which you want.
    Exp: I that this string like "Hello, I am 18 years old. I have 1 dog". there the string will be "Hello, I am { } years old. I have { } dog"
    the argsNumber will be 2, and (...) 18, 1
    */

   /*Code Exp:
        #include <format.h>
        #include <iostream>

        using namespace std;

        int main(){
            StringFormat sf;
            sf.string_format("Hello, I am { } years old. I have { } dog", 2, 18,1)
        }

   */
