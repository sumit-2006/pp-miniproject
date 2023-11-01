#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
#include <cmath>
using namespace std;
class properties
{

private:
    int n, digits;
    int getDigits(int n)
    {
        int x = n, digit = 0;
        while (x > 0)
        {
            digit++;
            x = x / 10;
        }
        return digit;
    }

public:
    properties(int m)
    {
        n = m;
        digits = getDigits(n);
        range();
        isOddEven();
        isPrime();
        squareRoot();
        cubeRoot();
        scientificNotation();
        getLog();
        getFactorial();
        factors();
        isPalindromic();
        isTriangular();
        isHappy();
        isFibonacci();
        isNarcissistic();
        getBase();
    }
    void getLog()
    {
        double d;
        d = log(n);
        cout << "The LOG of n to natural base is " << d << endl;
        d = log10(n);
        cout << "The LOG of n to the base 10 is " << d << endl;
        d = exp(n);
        cout << "The ANTILOG or e^n is " << d << endl;
    }
    void getFactorial()
    {
        long long factorial = 1;
        for (int i = 1; i <= n; i++)
        {
            factorial = factorial * i;
        }
        if (factorial == 0)
        {
            cout << "The FACTORIAL of the number is very large to be displayed" << endl;
        }
        else
            cout << "The FACTORIAL of the number is " << factorial << endl;
    }
    void squareRoot()
    {
        double d;
        d = pow(n, 1.0 / 2.0);
        cout << "Its SQUAREROOT is " << d << endl;
    }
    void cubeRoot()
    {
        double d, y;
        d = pow(n, 1.0 / 3.0);
        cout << "Its CUBEROOT is " << d << endl;
    }
    void isHappy()
    {
        int sum, x = n;
        do
        {
            sum = 0;
            while (x != 0)
            {
                sum = sum + pow(x % 10, 2);
                x = x / 10;
            }
            x = sum;
        } while (getDigits(sum) != 1);
        if (sum == 1)
        {
            cout << "It is a HAPPY number." << endl;
        }
        else
            cout << "It is NOT a HAPPY number." << endl;
    }
    void isTriangular()
    {
        int sum = 0;
        for (int i = 0; sum < n; i++)
        {
            sum = sum + i;
        }
        if (sum == n)
        {
            cout << "It is a TRIANGULAR number" << endl;
        }
        else
            cout << "It is NOT a TRIANGULAR number" << endl;
    }
    void scientificNotation()
    {
        double x = n;
        cout << "Scientific Notation: ";
        std::cout << std::scientific << std::setprecision(digits - 1) << x << std::endl;
    }
    void range()
    {
        if (n > 0)
        {
            cout << "It is a POSITIVE number." << endl;
        }
        else
            cout << "It is a NEGATIVE number." << endl;
    }
    void isOddEven()
    {
        if (n % 2 == 0)
        {
            cout << "This number is EVEN." << endl;
        }
        else
        {
            cout << "This number is ODD." << endl;
        }
    }
    void isPrime()
    {
        int flag;
        flag = 0;
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            cout << "It is a PRIME number." << endl;
        }
        else
            cout << "It is NOT a PRIME number." << endl;
    }
    void isPalindromic()
    {
        int a = n, c, rev = 0;
        while (a > 0)
        {
            c = a % 10;
            a = a / 10;
            rev = rev * 10 + c;
        }
        if (rev == n)
        {
            cout << "It is a PALINDROME." << endl;
        }
        else
            cout << "It is NOT a PALINDROME." << endl;
    }
    void factors()
    {
        int sum = 0;
        cout << "Its divisors are: ";
        for (int i = 1; i < n; i++)
        {
            if (n % i == 0)
            {
                cout << i << "\t";
                sum = sum + i;
            }
        }
        cout << endl;
        if (n == sum)
        {
            cout << "It is a PERFECT number." << endl;
        }
        else
            cout << "It is NOT a PERFECT number." << endl;
    }
    void isFibonacci()
    {
        int prev = 2, pprev = 1, i = 0;

        while (i < n)
        {
            i = prev + pprev;
            pprev = prev;
            prev = i;
        }
        if (i == n || n == 1 || n == 2)
        {
            cout << "It is a FIBONNACI number." << endl;
        }
        else
            cout << "It is NOT a FIBONNACI number." << endl;
    }
    void baseNumber(int base)
    {
        int x, y = 0, z = n;
        char c;
        vector<int> rem;
        while (z != 0)
        {
            if (z < base)
            {
                rem.push_back(z);
                break;
            }
            else
            {
                x = z % base;
                rem.push_back(x);
                z = z / base;
            }
        }
        for (int j = rem.size() - 1; j >= 0; j--)
        {
            if (rem[j] <= 9)
            {
                cout << rem[j];
            }
            else
            {
                c = rem[j] + 55;
                cout << c;
            }
        }
        cout << endl;
    }
    void getBase()
    {
        cout << "Binary representation: ";
        baseNumber(2);
        cout << "Octal representation: ";
        baseNumber(8);
        cout << "Hexadecimal representation: ";
        baseNumber(16);
    }
    void isNarcissistic()
    {
        int sum = 0, x = n;
        while (x > 0)
        {
            sum = sum + pow(x % 10, digits);
            x = x / 10;
        }
        if (sum == n)
        {
            cout << "It is a NARCISSISTIC number." << endl;
        }
        else
            cout << "It is NOT a NARCISSISTIC number." << endl;
    }
};
int main()
{
    int queries;
    cout << "Number Analysis System" << endl;
    cout << "Enter the number of queries: ";
    cin >> queries;
    while (queries--)
    {
        int number;
        cout << "Enter the Number: ";
        cin >> number;
        cout << "Number analysis of " << number << ":" << endl;
        properties m(number);
    }
}