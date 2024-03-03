#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str1[] = "hello";
    char str2[] = "world";
    strcat(str1, str2);
    cout << str1 << endl;

    if (strcmp(str1, str2))
    {
        strcpy(str2, str1);
        cout << str2 << endl;
    }

    cout << strlen(str2) << endl;

    return 0;
}