#include <ctype.h>
#include <fun.h>
#include <math.h>

unsigned int faStr1(const char* str)
{
    int i = 0;
    int count = 0;
    bool inWord = false;
    bool isNumber = false;

    while (str[i] != '\0'){
        if (str[i] != ' ' && !inWord){
            inWord = true;

            if (isdigit(str[i])){
                isNumber = true;
            }
        }
        else if ((str[i] != ' ') && inWord && isdigit(str[i])){
            isNumber = true;
        }
        else if (str[i] == ' '){
            if (!isNumber && inWord){
                count++;
            }
            inWord = false;
            isNumber = false;
        }
        i++;
    }
    return count;
}
unsigned int faStr2(const char *str)
{
    int i = 0;
    int count = 0;
    int inWord = 0;
    while(str[i] != '\0') {
        if(str[i] != ' ' && inWord == 0 && ('A' <=  str[i] && str[i] <= 'Z')) {
           inWord = 1;
           count++;
        }
        else if(str[i] != ' ' && inWord == 1 && !('a' <=  str[i] && str[i] <= 'z')) {
            inWord = 3;
            count--;
        }
        else if(str[i] == ' ' && (inWord == 1 || inWord == 3)) {
            inWord = 0;
        }
        i++;
    }
    return count;
}
unsigned int faStr3(const char *str)
{
    int i = 0;
    float count = 0;
    float word_sumbols = 0;
    int inWord = 0;
    while(str[i] != '\0') {
        if(str[i] != ' ' && inWord == 0) {
            count++;
            inWord = 1;
            word_sumbols++;
        }
        else if(str[i] != ' ' && inWord == 1) {
            word_sumbols++;
        }
        else if(str[i] == ' ' && inWord == 1) {
            inWord = 0;
        }
        i++;
    }
    return round(word_sumbols/count);
}
