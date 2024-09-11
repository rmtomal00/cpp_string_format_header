#ifndef FORMATSTRING
#define FORMATSTRING

#include <iostream>
#include <vector>
#include <string>
#include <cstdarg>

class StringFormat {

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

    public:
        std::string string_format(const std::string& formatString, int argsNumber, ...) {
            size_t formatLength = formatString.length();
            int startIndex = 0;
            std::vector<std::string> parts;

            // Split the string by '{' and '}'
            for (size_t i = 0; i < formatLength; ++i) {
                if (formatString[i] == '{') {
                    parts.push_back(formatString.substr(startIndex, i - startIndex));
                    startIndex = i; // Mark the position for the next substring
                } else if (formatString[i] == '}') {
                    startIndex = i + 1; // Move past the '}'
                }
                if (i == formatLength - 1) {
                    parts.push_back(formatString.substr(startIndex));
                }
            }

            // Initialize variadic argument list
            va_list args;
            va_start(args, argsNumber);

            std::string result = "";
            size_t partIndex = 0;

            // Concatenate parts and variadic arguments
            for (const auto& part : parts) {
                result += part;
                if (partIndex < argsNumber) {
                    result += std::to_string(va_arg(args, int)); // Assuming all arguments are integers
                }
                ++partIndex;
            }

            va_end(args);
            return result;
        }
};

#endif
