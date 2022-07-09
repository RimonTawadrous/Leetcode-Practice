#include <bits/stdc++.h>
using namespace std;

string simplifyPath(string path)
{
    if (!path.size())
    {
        return "";
    }
    stack<string> s;
    string dir;
    string returnPath;
    dir.reserve(10);
    int size = path.size();
    returnPath.append("/");
    for (int i = 0; i < size; i++)
    {
        dir.clear();
        while (path[i] == '/')
        {
            i++;
        }
        while (i < size && path[i] != '/')
        {
            dir.push_back(path[i]);
            i++;
        }

        if (dir.compare("..") == 0)
        {
            if (!s.empty())
            {
                s.pop();
            }
        }
        else if (dir.compare(".") == 0)
        {
            continue;
        }
        else if (dir.length() != 0)
        {
            s.push(dir);
        }
    }
    stack<string> tempStack;

    while (!s.empty())
    {
        tempStack.push(s.top());
        s.pop();
    }
    while (!tempStack.empty())
    {
        string temp = tempStack.top();
        if (tempStack.size() != 1)
        {
            returnPath.append(temp + "/");
        }
        else
        {
            returnPath.append(temp);
        }
        tempStack.pop();
    }

    return returnPath;
}

int main()
{
    cout << simplifyPath("/../") << endl;
    return 0;
}