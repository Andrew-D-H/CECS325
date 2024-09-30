// Andrew Hua
// CECS 325-01
// Prog 1 – One Card War
// Due 10/14/2024
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void bubble(int A[], int size){
	bool swapped;
	for(int i = 0;i < size - 1; i++){
		swapped = false;
		for(int j = 0; j < size - 1; j++){
				if (A[j + 1]  < A[j]){
					int temp = A[j+1];
					A[j+1] = A[j];
					A[j] = temp;
					swapped = true;
				}		
		}
		if(!swapped)
			break;		
	}
}

int main(int argc, char*argv[]){
	if(argc != 3){	
		cout << "Program did not provide 2 arguements";
		return 0;
	}
	int index = 0;
	int A[1000000];
	ifstream inputFile(argv[1]);
	if(inputFile){
		string line;
		while(getline(inputFile, line)){
			A[index] = stoi(line);
			index++;
		}
	}
	else{
		cout << "Could not open file " << argv[1] << endl;
		return 0;
	}
	bubble(A, index);
	ofstream outputFile(argv[2]);
	for (int i = 0;i < index; i++)
		outputFile << A[i] << endl;
	return 0;
}