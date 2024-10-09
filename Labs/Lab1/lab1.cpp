/*HOW TO EXECUTE PROGRAM
1. On command line (Cygwin): ./a.exe lab1.cpp
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//Computing GCD
long long computeGCD(long long x, long long y) {
    if (y == 0) return x;
    return computeGCD(y, x % y);
}

//Computing modular inverse
long long modInv(long long a, long long b) {
    long long x = 0, y = 1;

}

//Computing modular exponentiation (a^b % mod)
long long modExp(long long a, long long b, long long mod) {
    long long x = 1;
    a = a % mod;

    while (b > 0) {
        if (b % 2 == 1) x = (x * a) % mod;
        b = b >> 1;
        a = (a * a) % mod;
    }

    return x;
}

int main(int argc, char **argv) {

    cout << "Starting program..\n";

    //Obtaining p and q
    long long p = stoll(argv[1]);
    long long q = stoll(argv[2]);

    //Computing n
    long long n = p*q;

    //Computing z
    long long z = (p-1)*(q-1);

    //Finding smallest e such that it doesn't have a common factor (except 1) starting at 2
    long long e = 2;
    while (e < z) {
        if (computeGCD(e,z) == 1) break; //If GCD = 1 then break
        e++;
    }

    //Find smallest d
    long long d = modInv(e,z);

    cout << "Public key: " << e << ", " << n << endl;
    cout << "Private key: " << d << ", " << n << endl;

    //Getting user input
    string input;
    cout << "Enter an alphabetic phrase (UPPER COASE LETTERS):";
    cin >> input;

    return 0;
}