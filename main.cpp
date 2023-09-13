#include <iostream>
#include <string>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

void err() {
    cout << "error" << endl;
    exit(1);
}

bool IsCorrect(string str) {
    stack<char> s;
    char x;
    size_t len = strlen(str.c_str());
    for (int i = 0; i < len; ++i) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            s.push(str[i]);
            continue;
        }
        if (s.empty())
            return false;
        switch (str[i]) {
            case ')':
                x = s.top();
                s.pop();
                if (x == '{' || x == '[')
                    return false;
                break;
            case '}':
                x = s.top();
                s.pop();
                if (x == '(' || x == '[')
                    return false;
                break;
            case ']':
                x = s.top();
                s.pop();
                if (x == '(' || x == '{')
                    return false;
                break;
        }
    }
    return (s.empty());
}

int main(int argc, char* argv[]) {
    if (argc == 2) {
        string str;
        size_t len = strlen(argv[1]);
        string brackets;
        for (int i = 0; i < len; ++i) {
            if (argv[1][i] == '(' or argv[1][i] == ')')
                brackets += argv[1][i];
            else
                str += argv[1][i];
        }
//        printf("%s", brackets.c_str());
        if (IsCorrect(brackets)) {
            size_t len2 = str.length() - 1;
            string num;
            if (str[0] == '-' || str[len2] == '-')
                err();
            for (int i = 0; i < len2; ++i) {
                if (str[i] == '-') {
                    if (str[i] == str[i + 1])
                        err();
                }
                else {
                    if (str[i] >= '0' && str[i] <= '9')
                        num += str[i];
                }
            }

//            cout << str << endl;

            int pos = 0;
            for (int i = 0; i < str.length(); ++i)
                if (str[i] <= '9' && str[i] >= '0') {
                    pos = i;
                    break;
                }
            if (str[0] == '+' && str[pos] != 7)
                err();
            if (str[len2] >= '0' && str[len2] <= '9')
                num += str[len2];

//            cout << num << endl;

            if (num.length() < 11)
                err();
            if ((num[0] == '+' && num[1] != '7') || (num[0] != '8' && str[0] != '+'))
                err();
            size_t len0 = num.length();
            string res_num = "+7";
            for (int i = 1; i < len0; ++i)
                res_num += num[i];
            cout << res_num << endl;
        }
        else
            err();
    }
    return 0;
}
