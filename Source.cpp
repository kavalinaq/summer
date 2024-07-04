#include <iostream>
#include <format>
using namespace std; 

int main() {

    cout << format("I want go home, {}\n", "now:(") << '\n';

    string buffer;

    format_to(
        back_inserter(buffer),
        "I want go home {}\n",
        "now:(");

    cout << buffer << '\n';

    format_to_n(
        back_inserter(buffer), 6,
        "I want go home {}\n",
        "now:(");

    cout << buffer << '\n';

    cout << '\n';

    cout << format("{} {} {}, {}?\n", "How", "are", "you", "John"); //здесь просто по порядку 
    cout << format("{3}, {1} {2}? \n", "How", "are", "you", "John"); //тут цифра обозначает номер слова 
    cout << format("{3}, {0} {1} {2}? \n", "How", "are", "you", "John");
    cout << format("{2} {1} {3}.\n", "How", "are", "you", "John");

    cout << '\n';

    int num = 15; 
    cout << format("{:3}", num) << '\n';
    cout << format("{:*<3}", num) << '\n'; //к левому краю
    cout << format("{:*>3}", 'x') << '\n';// к правому 
    cout << format("{:*^3}", 'x') << '\n';// центрировать 
    cout << format("{:3d}", num) << '\n';

    cout << '\n';

    cout << format("{0:},  {1:+},  {1:-},  {0: }", 5, 4) << '\n'; //0 в скобках это номер символа, который мы выводим 
    cout << format("{1:},  {1:+},  {0:-},  {0: }", -5, -4) << '\n';
    cout << format("{1:},  {0:+},  {0:-},  {1: }", 1, 2) << '\n';
    cout << format("{1:},  {0:+},  {1:-},  {0: }", -1, -2) << '\n';

    cout << '\n';

    cout << format("{:#012}", 0x78) << '\n';
    cout << format("{:#015b}", 0x78) << '\n';
    cout << format("{:#020x}", 0x78) << '\n';

    cout << '\n';

    cout << format("{:g}", 145.0) << '\n';
    cout << format("{:#g}", 145.0) << '\n'; 


}