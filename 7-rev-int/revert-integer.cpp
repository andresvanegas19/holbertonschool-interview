#include <string>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        string itoa = to_string(x);
        string result;
        int total_len = itoa.length();

        for (int i = total_len - 1; i >= 0; i--)
        {
            if (x < 0 & i == total_len - 1)
            {
                result += "-";
            }
            result += itoa[i];
        }

        try
        {
            return stoi(result);
        }
        catch (out_of_range &e)
        {
            return 0;
        }
    }
};
