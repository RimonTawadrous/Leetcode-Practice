#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void tokenize(string const &str, const char delim, vector<string> &out)
    {
        // construct a stream from the string
        std::stringstream ss(str);

        std::string s;
        while (std::getline(ss, s, delim))
        {
            out.push_back(s);
        }
    }

    void extractContent(string s, string &content, string &path)
    {
        bool flag = false;
        int i = 0;
        while (i < s.size())
        {
            if (s[i] == ')')
            {
                flag = false;
            }

            else if (flag)
            {
                content += s[i];
            }

            else if (s[i] == '(')
            {
                flag = true;
            }
            else
            {
                path += s[i];
            }
            i++;
        }
    }

public:
    vector<vector<string>> findDuplicate(vector<string> &paths)
    {
        unordered_map<string, vector<string>> map;
        unordered_map<string, int> contentFreq;

        vector<vector<string>> res;
        string content = "";
        string currentPath = "";

        const char delim = ' ';
        for (string path : paths)
        {
            vector<string> out;
            tokenize(path, delim, out);
            for (int i = 1; i < out.size(); i++)
            {
                content = "";
                currentPath = "";
                extractContent(out[i], content, currentPath);
                cout << content << endl;
                cout << currentPath << endl;
                contentFreq[content]++;

                if (map.find(content) == map.end())
                {
                    vector<string> temp;
                    temp.push_back(out[0] + "/" + currentPath);
                    map[content] = temp;
                }
                else
                {
                    map[content].push_back(out[0] + "/" + currentPath);
                }
            }
        }

        for (auto it : map)
        {
            if (contentFreq[it.first] > 1)
            {
                res.push_back(it.second);
            }
        }

        return res;
    }
};