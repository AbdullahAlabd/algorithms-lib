#include <bits/stdc++.h>
using namespace std;

int main(){
    /// C
    double d = 1.2;
    int n = 4;
    printf("%.*f\n",n, d); //print n digits after comma.
    
    ///C++
    //string split.
    string s;
    getline(cin, s);
    stringstream ss(s);
    int n;
    while(ss >> n) {
        cout << n << endl;
    }
    // Ouput a specific number of digits past the decimal point,
    // in this case 5
    cout.setf(ios::fixed); cout << setprecision(5);
    cout << 100.0/7.0 << endl;
    cout.unsetf(ios::fixed);

    // Output the decimal point and trailing zeros
    cout.setf(ios::showpoint);
    cout << 100.0 << endl;
    cout.unsetf(ios::showpoint);

    // Output a ’+’ before positive values
    cout.setf(ios::showpos);
    cout << 100 << " " << -100 << endl;
    cout.unsetf(ios::showpos);

    // Output numerical values in hexadecimal
    cout << hex << 100 << " " << 1000 << " " << 10000 << dec << endl;
}

//////////////////////////////////////////
//////////////////////////////////////////

//scanf regex examples:
int main() {
    char s[100], t[100];
    scanf("%*[0-9]%*[a-z]%[0-9]", s); //ignore any number of chars in range [0-9] then ignore any number of chars in range [a-z] then read any number of chars in range [0-9].
    scanf("%*5[0-9]%[a-zA-Z0-9]", s); //ignore first 5 digits then read any char in range [a-z] or [A-Z] or [0-9]
    scanf("%[^\n]", s); // read until the end of the line
    scanf("%[^-]-->%[^\n]", s, t); //read string1, string2 in "string1-->string2"
    scanf("%[abc12.]", s); //read string consists of letters {'a', 'b', 'c', '1', '2', '.'} until any other latter appears
}
//for more:
//https://regexr.com/
//http://www.gnu.org/software/libc/manual/html_node/String-Input-Conversions.html
//https://bytes.com/topic/c/answers/521077-scanf-information
//https://stackoverflow.com/questions/14873542/use-scanf-with-regular-expressions
