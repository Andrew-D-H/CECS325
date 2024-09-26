// Andrew Hua
// CECS 325-01
// Prog 1 – One Card War
// Due 10/14/2024
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cout << "Program did not provide 3 arguements" << endl;
        return 0;
    }
    srand(time(nullptr));
    ofstream generatedFile("numbers.dat");
	int count = stoi(argv[1]);
    int min = stoi(argv[2]);
    int max = stoi(argv[3]);
    for (int i = 0; i < stoi(argv[1]); i++) {
        generatedFile << rand() % (max-min+1) + min << '\n';
    }
	generatedFile.close();	
    return 0;
}