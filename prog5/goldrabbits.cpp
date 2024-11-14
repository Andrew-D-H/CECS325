#include <iostream>
#include <time.h>
#include <iomanip>
#include <map>
#include <climits>
#include <fstream>

using namespace std;

int goldRabbits(int); // prototype or signature

map<int, int> x;
int count = 0;
ofstream outputFile("goldrabbits.log");

int main()
{
	int const months = 12 * 10; // this is 10 years or 120 months
	int start = time(0); // number of seconds since Jan 1, 1970
	try{
		for(int i=0; i<months; i++)
		{
			int current = time(0); // number of seconds since program started
			outputFile << setw(5)<<current-start<<":"; // print elapsed seconds
			outputFile << " GoldRabbits("<<setw(2)<<i<<") = ";
			outputFile << setw(11)<< goldRabbits(i) << " fiboCount "  << count << endl;// the call to goldRabbitsz
		}
	} catch(const overflow_error& e){
		outputFile << e.what() << endl;
		goldRabbits(-1);
	}
	outputFile.close();
	return 0;
}
// this is the goldRabbits function
int goldRabbits(int n) {
	if (n == -1){
		outputFile << "Fibo map" << endl;
		for(const auto&entry: x){
			outputFile << entry.first << ": " << entry.second << endl;
		}
		return 0;
	}
	count++;
    if (n == 0 || n == 1) 
        return 1;
    if (x.find(n) != x.end()) {
        return x[n];
    }
	if(goldRabbits(n-1) > INT_MAX - goldRabbits(n-2))
		throw overflow_error("Overflow on:" + to_string(n));
    int result = goldRabbits(n - 1) + goldRabbits(n - 2);
    x[n] = result;
    return result;
}