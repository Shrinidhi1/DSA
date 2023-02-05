#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

class stringFunctions
{
public:
    vector<string> array;
    void subsequence(string input, string output)
    {
        if (input.empty())
        {
            array.push_back(output);
            // cout << output << endl;
            return;
        }
        // cout<< input.substr(1)<< endl;
        subsequence(input.substr(1), output + input[0]);
        subsequence(input.substr(1), output);
    }

    void substring(string str, int n)
    {
        string temp = "";
        for (int len = 1; len <= n; len++)
        {
            for (int i = 0; i <= n - len; i++)
            {
                int j = i + len - 1;
                for (int k = i; k <= j; k++)
                    temp += str[k];

                array.push_back(temp);
                temp = "";
            }
        }
    }

    void reverse1(string str, int n)
    {
        for (int i = 0; i < n / 2; i++)
            swap(str[i], str[n - i - 1]);
        cout << str;
    }

    void leftrotate(string &s, int d)
    {
        reverse(s.begin(), s.begin() + d);
        reverse(s.begin() + d, s.end());
        reverse(s.begin(), s.end());
    }

    void rightrotate(string &s, int d)
    {
        leftrotate(s, s.length() - d);
    }

    void binaryString(int arr[], int n)
    {
        string str = "";
        for (int i = 0; i < n; i++)
        {
            str += to_string(arr[i]);
        }
        cout << str;
    }

    bool palindrome(string str, int n)
    {
        for (int i = 0; i < n / 2; i++)
        {
            if (str[i] != str[n - i - 1])
            {
                return false;
            }
        }
        return true;
    }

    int fact(int n)
    {
        return (n <= 1) ? 1 : n * fact(n - 1);
    }

    int findSmallerInRight(string str, int low, int high)
    {
        int countRight = 0, i;

        for (i = low + 1; i <= high; ++i)
            if (str[i] < str[low])
                ++countRight;

        return countRight;
    }

    int lexicoRank(string str)
    {
        int len = str.size();
        int mul = fact(len);
        int rank = 1, countRight;
        int i;
        for (i = 0; i < len; ++i)
        {
            mul /= len - i;
            countRight = findSmallerInRight(str, i, len - 1);
            rank += countRight * mul;
        }
        return rank;
    }

    int patternSearch(string text, string pattern)
    {
        int n = text.size(), m = pattern.size(), j;
        for(int i=0; i<= n - m; i++)
        {
            j=0;
            while(j < m && pattern[j] == text[i + j])
            {
                j++;
            }
            if(j == m)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    string str = "abba", str1 = "ba";
    stringFunctions s1;
    // s1.subsequence(str, str1);
    // s1.substring(str, 4);
    // s1.reverse1(str, 4);
    // s1.leftrotate(str, 1);
    // s1.rightrotate(str, 1);

    // int array[5] = {1, 0, 0, 1, 1};
    // s1.binaryString(array, 5);

    // cout << s1.palindrome(str, 4);
    // cout << s1.lexicoRank(str);
    // cout << s1.patternSearch(str, str1);

    return 0;
}