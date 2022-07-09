#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    map<string, string> encodedURLMap;
    map<string, string> decodedURLMap;
    string basename = "http://tinyurl.com/";

public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        string shortUrl = basename + to_string(longUrl.size() + 1);
        encodedURLMap[longUrl] = shortUrl;
        decodedURLMap[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        return decodedURLMap[shortUrl];
    }
};

int main()
{
}