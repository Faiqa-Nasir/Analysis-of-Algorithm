#include <iostream>
#include <string>
using namespace std;

int recursionLCS(string str1, string str2, int size1, int size2, string& ans)
{
    if (size1 == 0 || size2 == 0)
    {
        return 0;
    }

    if (str1[size1 - 1] == str2[size2 - 1])
    {
        ans = str1[size1 - 1] + ans;
        return 1 + recursionLCS(str1, str2, size1 - 1, size2 - 1, ans);
    }
    else
    {
        return max(recursionLCS(str1, str2, size1 - 1, size2, ans), recursionLCS(str1, str2, size1, size2 - 1, ans));
    }
}

int main()
{
    cout << "Input string 1: ";
    string str1 = "";
    cin >> str1;

    cout << "Input string 2: ";
    string str2 = "";
    cin >> str2;

    string ans = "";
    int size1 = str1.length();
    int size2 = str2.length();

    int length = recursionLCS(str1, str2, size1, size2, ans);

    cout << "The longest common subsequence is: " << ans << endl;
    cout << "Its length is: " << length << endl;

    return 0;
}
