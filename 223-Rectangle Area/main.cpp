#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int reactangleArea(int width, int length)
    {
        return width * length;
    }

public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
    {
        int leftX = max(A, E);
        int rightX = min(C, G);

        int topY = min(D, H);
        int bottomY = max(B, F);

        int overlap = 0;

        if (rightX > leftX && topY > bottomY)
        {
            overlap = reactangleArea((rightX - leftX), (topY - bottomY));
        }

        return reactangleArea((D - B), (C - A)) + reactangleArea((H - F), (G - E)) - overlap;
    }
};

int main()
{
}