// Andrew Hua
// CECS 325-01
// Prog 6 – biginttest
// Due 12/11/2024
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <vector>
#include <string>
#include <iostream>
#include <climits>
#include <iomanip>

using namespace std;

class BigInt {
    private:
        vector<char> v;
		
        BigInt fiboHelper(BigInt n, BigInt a = 0, const BigInt &num = 1) {
            if (n == 0)
                return a;
            else if (n == 1)
                return num;
            else
                return fiboHelper(--n, num, a + num);
        }

    public:
        BigInt() = default;

        BigInt(int num) {
            if (num == 0)
                v.push_back(0);
            else{
                while (num > 0) {
                    v.push_back(num % 10);
                    num /= 10;
                }
            }
        }

        BigInt(string str) {
            for (int i = str.size() - 1; i > -1; --i) {
                v.push_back(str[i] - '0');
            }
        }

        bool operator==(const BigInt &num) {
            return v == num.v;
        }

        bool operator>(const BigInt &num) const {
            int i = size();
            int j = num.size();
            if (i != j)
                return i > j;
            else {
                while (i--) {
                    if (v[i] != num[i])
                        return v[i] > num[i];
                }
                return false;
            }
        }

        BigInt &operator+=(const BigInt &num) {
            int aSize = size();
            int numSize = num.size();
            char carry = 0;
            for (int i = 0; i < max(aSize, numSize); ++i) {
                if (i >= aSize)
                    v.push_back(0);
                v[i] += carry;
                carry = 0;
                if (i < numSize) 
                    v[i] += num[i];
                if (v[i] > 9) {
                    v[i] -= 10;
                    carry = 1;
                }
            }
            if (carry)
                v.push_back(1);
            return *this;
        }

        BigInt operator+(const BigInt &num) {
            BigInt result = *this;
            result += num;
            return result;
        }

        friend BigInt operator+(const int a, const BigInt &num) {
            BigInt result(a);
            result += num;
            return result;
        }

        BigInt &operator-=(const BigInt &num) {
            int aSize = size();
            int numSize = num.size();
            char carry = 0;
            for (int i = 0; i < aSize; ++i) {
                v[i] -= carry;
                carry = 0;
                if (i < numSize) {
                    v[i] -= num[i];
                }
                if (v[i] < 0) {
                    v[i] += 10;
                    carry = 1;
                }
            }
            while (v.back() == 0 && size() > 1) {  // Remove leading zeros.
                v.pop_back();
            }
            return *this;
        }

        BigInt operator-(const BigInt &num) {
            BigInt result = *this;
            result -= num;
            return result;
        }

        friend BigInt operator-(const int a, const BigInt &num) {
            BigInt result(a);
            result -= num;
            return result;
        }

        BigInt &operator*=(const BigInt &num) {
            BigInt loopIdx = *this;
            BigInt result = num;
            BigInt toAdd = num;
            if ((*this) > num) {
                loopIdx = num;
                result = *this;
                toAdd = *this;
            }
            while (loopIdx > 1) {
                result += toAdd;
                loopIdx--;
            }
            *this = result;
            return *this;
        }

        BigInt operator*(const BigInt &num) {
            BigInt result = *this;
            result *= num;
            return result;
        }

        BigInt operator/(const BigInt &num) {
            BigInt remainder = *this;
            BigInt result(0);
            while (remainder > num) {
                remainder -= num;
                result++;
            }
            return result;
        }

        BigInt operator%(const BigInt &num) {
            BigInt remainder = *this;
            while (remainder > num) {
                remainder -= num;
            }
            return remainder;
        }

        // Crement operators
        BigInt operator++() {
            *this += 1;
            return *this;
        }

        BigInt operator++(int) {
            BigInt old = *this;
            ++(*this);
            return old;
        }

        BigInt operator--() {
            *this -= 1;
            return *this;
        }

        BigInt operator--(int) {
            BigInt old = *this;
            --(*this);
            return old;
        }

        char operator[](const int i) const {
            return v[i];
        }

        friend ostream& operator<<(ostream &out, const BigInt &num) {
            int size = num.v.size();
            if (size > 12) {
                out << int(num.v[size - 1]) << '.';
                for (int i = size - 2; i > size - 8; --i) {
                    out << int(num.v[i]);
                }
                out << "e" << size - 1;
            } else {
                for (int i = size - 1; i > -1; --i) {
                    out << int(num.v[i]);
                }
            }
            return out;
        }

        int size() const {
            return v.size();
        }

        void print() {
            for (int i = v.size() - 1; i > -1; --i) {
                cout << int(v[i]);
            }
			cout << endl;
        }

        BigInt fibo() {
            return fiboHelper(*this);
        }

        BigInt fact() const {
            BigInt result(1);
            for (BigInt i(0); *this > i; ++i) {
                result *= i + 1;
            }
            return result;
        }
};

void testUnit()
{
	int space = 10;
	cout << "\a\nTestUnit:\n"<<flush;
	system("whoami");
	system("date");
	// initialize variables
	BigInt n1(25);
	BigInt s1("25");
	BigInt n2(1234);
	BigInt s2("1234");
	BigInt n3(n2);
	BigInt fibo(12345);
	BigInt fact(50);
	BigInt imax = INT_MAX;
	BigInt big("9223372036854775807");
	// display variables
	cout << "n1(int) :"<<setw(space)<<n1<<endl;
	cout << "s1(str) :"<<setw(space)<<s1<<endl;
	cout << "n2(int) :"<<setw(space)<<n2<<endl;
	cout << "s2(str) :"<<setw(space)<<s2<<endl;
	cout << "n3(n2)  :"<<setw(space)<<n3<<endl;
	cout << "fibo(12345):"<<setw(space)<<fibo<<endl;
	cout << "fact(50) :"<<setw(space)<<fact<<endl;
	cout << "imax :"<<setw(space)<<imax<<endl;
	cout << "big :"<<setw(space)<<big<<endl;
	cout << "big.print(): "; big.print(); cout << endl;
	cout << n2 << "/"<< n1<< " = "<< n2/n1 <<" rem "<<n2%n1<<endl;
	cout << "fibo("<<fibo<<") = "<<fibo.fibo() << endl;
	cout << "fact("<<fact<<") = "<<fact.fact() << endl;
	cout << "10 + n1 = " << 10+n1 << endl;
	cout << "n1 + 10 = " << n1+10 << endl;
	cout << "(n1 == s1)? --> "<<((n1==s1)?"true":"false")<<endl;
	cout << "n1++ = ? --> before:"<<n1++<<" after:"<<n1<<endl;
	cout << "++s1 = ? --> before:"<<++s1<<" after:"<<s1<<endl;
	cout << "s2 * big = ? --> "<< s2 * big<<endl;
	cout << "big * s2 = ? --> "<< big * s2<<endl;
}

int main(){
	testUnit();
	return 0;
}