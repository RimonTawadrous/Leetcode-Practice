#include <bits/stdc++.h>
using namespace std;

bool isInterleave(string s1, string s2, string s3)
{
    int s1L = s1.size(), s2L = s2.size(), s3L = s3.size();
    if (s3L != (s1L + s2L))
    {
        return false;
    }
    vector<vector<bool>> db(s2L + 1, vector<bool>(s1L + 1, false));
    db[0][0] = true;

    for (int i = 1; i < s1L + 1; i++)
    {
        if (s1[i - 1] == s3[i - 1])
        {
            db[0][i] = true;
        }
    }
    for (int i = 1; i < s2L + 1; i++)
    {
        if (s2[i - 1] == s3[i - 1])
        {
            db[i][0] = true;
        }
    }

    for (int i = 1; i < s2L + 1; i++)
    {
        for (int j = 1; j < s1L + 1; j++)
        {
            cout << "s1[j - 1]" << s1[j - 1] << " , s3[i + j - 1] = " << s3[i + j - 1] << endl;
            cout << "s2[i - 1]" << s2[i - 1] << " , s3[i + j - 1] = " << s3[i + j - 1] << endl;

            if (s1[j - 1] == s3[i + j - 1])
            {
                db[i][j] = db[i][j] || db[i - 1][j];
            }
            if (s2[i - 1] == s3[i + j - 1])
            {
                db[i][j] = db[i][j] || db[i][j - 1];
            }
        }
    }

    for (int i = 0; i < s2L + 1; i++)
    {
        for (int j = 0; j < s1L + 1; j++)
        {
            cout << db[i][j] << " ";
        }
        cout << endl;
    }

    return db[s1L][s2L];
}

// bool isInterleave(string s1, string s2, string s3)
// {
//     int len1 = (int)s1.length();
//     int len2 = (int)s2.length();
//     int len = (int)s3.length();

//     if (len1 + len2 != len) {
//         return false;
//     }

//     vector<vector<bool>> match(len1+1,vector<bool>(len2+1,false));

//     match[0][0] = true;

//     for (int i = 1; i <= len1; i++) {
//         if (s1[i-1] == s3[i-1])
//             match[i][0] = true;
//         else
//             break;
//     }
//     for (int i = 1; i <= len2; i++) {
//         if (s2[i-1] == s3[i-1])
//             match[0][i] = true;
//         else
//             break;
//     }

//     for (int i = 1; i <= len1; i++) {
//         for (int j = 1; j <= len2; j++) {
//             if (s1[i-1] == s3[i+j-1]) {
//                 match[i][j] = match[i][j] || match[i-1][j];
//             }
//             if (s2[j-1] == s3[i+j-1]) {
//                 match[i][j] = match[i][j] || match[i][j-1];
//             }
//         }
//     }

//     return match[len1][len2];
// }

int main()
{
    cout << isInterleave("aab", "axy", "aaxaby") << endl;
}