#include <cstring>
#include <iostream>

bool IsPolly(const char *s){
    const int len = strlen(s);
    for(int strart = 0, end = len -1; strart < end; ++strart,--end){
        while (s[strart] == ' ' && strart < end){++strart;}
        while (s[end] == ' ' && strart < end){--end;}

        if(strart < end && s[strart] != s[end]){
            return false;
        }
    }
    return true;
}



int main(){
    constexpr int str_size = 50;
    char *str = new char[str_size];
    std::cin.getline(str, str_size);
    std::cout << IsPolly(str) << '\n';
}