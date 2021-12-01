#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int Count(const char* s, const char c, int i)
{
    if (s[i] != '\0')
        if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c' && s[i + 1] != '\0' && s[i + 2] != '\0')
            return 1 + Count(s, c, i + 1);
        else
            return Count(s, c, i + 1);
    else
        return 0;
}


void IterStr(char* s, int i)
{
    if (s[i] != '\0')
    {
        s[i] = s[i + 1];
        IterStr(s, i + 1);
    }
}

void Change(char* s, char c, int i)
{
    if (Count(s, c, i))
    {
        if (s[i] != '\0')
        {
            if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c' && s[i + 1] != '\0' && s[i + 2] != '\0')
            {
                s[i] = '*';
                s[i + 1] = '*';
                IterStr(s, i + 2);
            }
                Change(s, c, i + 1);
        }
    }
}

int main()
{
    char c{};
    char* R{};
    int i{};

    cout << "Enter string:" << endl;

    char* s = new char[101];
    cin.getline(s, 100);

    cout << endl;

    if (Count(s, c, 0))
        cout << "String contained " << Count(s, c, 0) << " groups of abc" << endl;

    cout << endl;

    Change(s, i, c);

    cout << s << endl;
}