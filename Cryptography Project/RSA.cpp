#include<string>
#include <ctime>
#include <iostream>
#include "headers\RSA.h"
#include "headers\IO.h"
#include "headers\Conversions.h"
using std::vector;
using std::cout;

char revShift(char input, int multiply, int add) {
	//return char((((multiInverse(input, 95)*multiply) % 95) + (multiInverse(input, 95)*add) % 95) - 32) % 95) + 32);

	return char(((((multiInverse(multiply,95)*((int(input) - 32)  + (95 - (add % 95)))) % 95) + 32)));
}

char shift(char input, int multiply, int add) {

	return char((((((int(input)*multiply%95) - 32) + add) % 95) + 32));
}

void passwordValues(string password, int&sum, int&product) {
	sum = 0;
	product = 1;
	for (int i = 0; i < password.size(); i++) {
		product *= password[i];
		sum += password[i];
		product =  product % 1000;
	}
}

vector<char> linearCipherEncrypt(vector<char>message) {
	vector<int> plaintext = charVecToInt(message);
	cout << "\nEnter password:\n";
	string password = getString();
	int product, sum;
	passwordValues(password, sum, product);
	
	
	for (int i = 0; i < message.size(); i++) {
		plaintext[i] = shift(plaintext[i], 1, product);
		
		
		
	}

	return intVecToChar(plaintext);
}



vector<char> linearCipherDecrypt(vector<char>message) {
	vector<int> plaintext = charVecToInt(message);
	cout << "\nEnter password:\n";
	string password = getString();
	int sum, product;
	passwordValues(password, sum, product);
	
	for (int i = 0; i < message.size(); i++) {	
		
		plaintext[i] = revShift(plaintext[i],1,product);	

	}

	return intVecToChar(plaintext);
}

int xGCD(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	int x1, y1, gcd = xGCD(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return gcd;
}

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);

}

int lcm(int a, int b) {
	return (a*b) / gcd(a, b);

}

int multiInverse(int num, int base) {

	int x, y, gcd = xGCD(base, num % base, x, y);
	return y;
}


/*int rsaEncrypt(string password) {
	srand(time(NULL));

	vector<bool> isPrime(4294967296, true);
	vector<int> listOfPrimes;
	listOfPrimes.push_back(2);
	for (int i = 2; i < 4294967296; i += 2) {
			if (isPrime[i] == true) {
			listOfPrimes.push_back(i + 1);
			for (int j = i + i + 1; j < 4294967296 && j != 1; j += i + 1) {
				isPrime[j] = false;
			}
		}
	}
	int p = listOfPrimes[rand() % 50000 + 50000];
	int q = listOfPrimes[rand() % 50000 + 50000];
	unsigned long long n = p*q;
	int a = multiInverse()
}*/
