#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <bitset>

using namespace std;

string intToBinary1(int n)
{
    bitset<8> binary(n);
    return binary.to_string();
}

string intToBinary2(int n)
{
    const int numBits = 8;
    string binary = "";
    for (int i = numBits - 1; i >= 0; i--)
    {
        int bitValue = (n >> i) & 1;
        binary += (bitValue == 0 ? '0' : '1');
    }
    return binary;
}

int binaryToInt(string binaryString)
{
    int result = 0;
    int size = binaryString.size();
    for (int i = size - 1; i >= 0; i--)
        if (binaryString[i] == '1')
            result += (1 << (size - i - 1));
    return result;
}

int count1s(int n)
{
    int count = 0;
    while (n != 0)
    {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}

int count0s(int n)
{
    int count = 0;
    while (n != 0)
    {
        count += (n & 1) == 0;
        n >>= 1;
    }
    return count;
}

int toggleKthbit(int n, int k)
{
    int mask = 1 << (k - 1);
    n ^= mask;
    return n;
}

string addBinary(string a, string b)
{
    string result = "";
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;
    while (i >= 0 || j >= 0 || carry > 0)
    {
        int sum = carry;
        if (i >= 0)
        {
            sum += (a[i] - '0');
            i--;
        }
        if (j >= 0)
        {
            sum += (b[j] - '0');
            j--;
        }
        result += char(sum % 2 + '0');
        carry = sum / 2;
    }
    reverse(result.begin(), result.end());
    return result;
}

string subtractBinary(string a, string b)
{
    string result = "";
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;
    while (i >= 0 || j >= 0)
    {
        int numA = (i >= 0) ? (a[i] - '0') : 0;
        int numB = (j >= 0) ? (b[j] - '0') : 0;
        int diff = numA - numB - carry;
        if (diff < 0)
        {
            diff += 2;
            carry = 1;
        }
        else
            carry = 0;
        result += char(diff + '0');
        i--;
        j--;
    }
    while (result.length() > 1 && result[0] == '0')
        result.erase(result.begin());
    return result;
}

bool checkIfPowerOf2(int n)
{
    return n && (!(n & (n-1)));
}

int xorFrom1toN(int n)
{
    if(n%4 == 0) return n;
    if(n%4 == 1) return 1;
    if(n%4 == 2) return n+1;
    return 0;
}

bool allBitsAreSet(int n)
{
    if (((n + 1) & n) == 0) return true;
    return false;
}

bool bitsAreInAltOrder(int n)
{
    int num = n ^ (n >> 1);
    return allBitsAreSet(num);
}

int countTrailingZeroes(int n) 
{
    int count = 0;
    while ((n & 1) == 0) 
    {
        count++;
        n >>= 1;
    }
    return count;
}

int reverseBits(int n) 
{
    int result = 0;
    int bitSize = sizeof(n) * 8;
    for (int i = 0; i < bitSize; i++) 
    {
        result <<= 1;
        result |= n & 1; 
        n >>= 1;
    }
    return result;
}

int main()
{
    int n = 37;
    string binary = "100101", a = "101", b = "1011";
    auto binary1 = 0b100101;
    cout << intToBinary1(n) << endl;
    cout << intToBinary2(n) << endl;
    cout << binaryToInt(binary) << endl;
    cout << binary1 << endl;
    cout << count1s(n) << endl;
    cout << count0s(n) << endl;
    cout << toggleKthbit(n, 5) << endl;
    cout << addBinary(a, b) << endl;
    cout << subtractBinary(b, a) << endl;
    cout << checkIfPowerOf2(n) << endl;
    cout << xorFrom1toN(n) << endl;
    cout << allBitsAreSet(n) << endl;
    cout << bitsAreInAltOrder(n) << endl;
    cout << countTrailingZeroes(n) << endl;
    cout << reverseBits(n) << endl;
    return 0;
}
