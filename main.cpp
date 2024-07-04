#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

bool is_frac(const string& str) {
    regex fracregex(R"((-?\d+)/(\d+))");
    return regex_match(str, fracregex);
}

double parse(const string& str) {
    regex fracregex(R"((-?\d+)/(\d+))");
    smatch match;
    if (regex_match(str, match, fracregex)) {
        double num = stod(match[1].str());
        double denom = stod(match[2].str());
        return num / denom;
    }
    return 0.0;
}
//---------------------------------------
void process_file(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "ERROR: File don't open" << filename << endl;
        return;
    }

    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());


    file.close();
    //---------------------------------------
    regex regex(R"((\d{2}.\d{2}.\d{4})|(-?\d+(?:/\d+)?(?:\.\d+)?(?:[eE][+-]?\d+)?))");

    string::const_iterator search_start(content.cbegin());
    //---------------------------------------
    int xdate = 0;
    int xchislo = 0;

    auto pos = content.cbegin();
    auto end = content.cend();
    smatch m;
    string date;


    for (; regex_search(pos, end, m, regex); pos = m.suffix().first) {
        if (!m.str(1).empty()) {
            xdate += 1;
            date = m.str(1);
            pos = m.suffix().first;
            break;
        }
        else if (!m.str(2).empty()) {
            cout << "ERROR: found number before date" << endl;
            return;
        }
    }

    pos = content.cbegin();
    int xdate2 = 0;

    for (; regex_search(pos, end, m, regex); pos = m.suffix().first)
    {
        if (!m.str(1).empty()) {
            xdate2 += 1;
        }
    }
    if (xdate2 != 1) {
        cout << "ERROR: found more than one date" << endl;
        return; 
    }
    pos = content.cbegin();
    int sum_int = 0;
    double sum_floats = 0.0;

 

    for (; regex_search(pos, end, m, regex); pos = m.suffix().first) {
        if (!m.str(2).empty()) {
            string number_str = m.str(2);

            if (is_frac(number_str)) {
                sum_floats += parse(number_str);
            }
            else if (number_str.find('.') != string::npos || number_str.find('e') != string::npos || number_str.find('E') != string::npos) {
                sum_floats += stod(number_str);
            }
            else {
                sum_int += stoi(number_str);
            }
        }
    }
        cout << "Data: " << date << endl;
        cout << "Summa of int: " << sum_int << endl;
        cout << "Summa of not int: " << sum_floats << endl;

}

//---------------------------------------
int main() {
    string filename = "data2.txt";
    process_file(filename);
    return 0;
}

