// Andrew Hua
// CECS 325-01
// Prog 4 – threads
// Due 10/30/2024
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>

using namespace std;

const int numThreads = 16;
const int arrSize = 1000000;
long long swapCount = 0;
mutex swapMutex;

void bubble(int A[], int size, string processName){
	long long localSwapCount = 0;
	bool swapped;
	for(int i = 0;i < size - 1; i++){
		for(int j = 0; j < size - 1; j++){
				if (A[j + 1]  < A[j]){
					int temp = A[j+1];
					A[j+1] = A[j];
					A[j] = temp;
					localSwapCount++;
				}		
		}	
	}
	lock_guard<mutex> lock(swapMutex);
	swapCount += localSwapCount;
	cout << processName << " swap count: " << localSwapCount << endl;
}

void merge(int *arr, int left, int mid, int right){
    int i = left; 
    int j = mid; 
    int k = 0;
    int *temp = new int[right - left];
    while (i < mid && j < right) {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i < mid)
        temp[k++] = arr[i++];
    while (j < right)
        temp[k++] = arr[j++];
    for (int x = left, y = 0; x < right; x++, y++)
        arr[x] = temp[y];
    delete[] temp;
}

int main(int argc, char* argv[]) {
	if(argc != 3){	
		cout << "Program did not provide 2 arguements";
		return 0;
	}
    int n;
    int index = 0;
    int* A = new int[arrSize];
	ifstream inputFile(argv[1]);
	if(inputFile){
		string line;
		while(getline(inputFile, line)){
			A[index] = stoi(line);
			index++;
		}
	}
    while (inputFile >> n && index < arrSize) {
        A[index++] = n;
    }
    const int THREADS = 16;
    int SECTIONS = (index + THREADS - 1) / THREADS; 
    thread threads[THREADS];
    for (int i = 0; i < THREADS; i++) {
        int left = i * SECTIONS;
        int right = (i == THREADS - 1) ? index : (i + 1) * SECTIONS;
        threads[i] = thread(bubble, A + left, right - left, "Process " + to_string(i + 1));
    } 
    for (int i = 0; i < THREADS; i++)
        threads[i].join();
    for (int i = 1; i < THREADS; i++)
        merge(A, 0, i * SECTIONS, min(index, (i + 1) * SECTIONS));
    cout << "Total swaps: " <<  swapCount << endl;
	ofstream outputFile(argv[2]);
    for (int i = 0; i < index; ++i) {
        outputFile << A[i] << '\n';
    }
	outputFile.close();
    inputFile.close();
    delete[] A;

    return 0;
}