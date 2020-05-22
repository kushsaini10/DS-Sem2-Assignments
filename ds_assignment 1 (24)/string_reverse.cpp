#include <iostream>
using namespace std;

// recursive function to find reverse of a string 

void reverse(string &str, int len, int i = 0)
{
    if (i >= len / 2)
    {
        return;
    }
    char temp = str[i];
    str[i] = str[len - i - 1];
    str[len - i - 1] = temp;
    reverse(str, len, i + 1);
}

int main()
{
    string str;
    int len;
    cout << "Enter the string: ";
    getline(cin, str);
    len = str.size();
    reverse(str, len);
    cout << str << "\n";
    return 0;
}