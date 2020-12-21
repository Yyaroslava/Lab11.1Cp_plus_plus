#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>

using namespace std;

void Create(char* FileName, int N, int min, int max) {
	ofstream f(FileName, ios::binary);
	if (!f) {
		cerr << "File open fails" << endl;
		exit(1);
	}
	int a;
	for (int i = 0; i < N; i++) {
		a = min + rand() % (max - min + 1);
		f.write((char*)&a, sizeof(int));
	}
	cout << endl;
}

void Process(char* FileName, char* OddFileName, char* EvenFileName) {
	ifstream file(FileName, ios::binary);
	if (!file) {
		cerr << "Can not open input file" << endl;
		exit(1);
	}
	ofstream file_odd(OddFileName, ios::binary);
	if (!file_odd) {
		cerr << "Can not open output file" << endl;
		exit(1);
	}
	ofstream file_even(EvenFileName, ios::binary);
	if (!file_even) {
		cerr << "Can not open output file" << endl;
		exit(1);
	}
	int a = 0;
	while (file.read((char*)&a, sizeof(int))) {
		if (a % 2 == 0) {
			file_odd.write((char*)&a, sizeof(int));
		}
		else {
			file_even.write((char*)&a, sizeof(int));
		}
	}
}

void Print(char* FileName) {
	ifstream f(FileName, ios::binary);
	if (!f) {
		cerr << "Can not open file " << FileName << endl;
		exit(1);
	}
	cout << "File name: " << FileName << endl;
	int a;
	while (f.read((char*)&a, sizeof(int))) { 
		cout << a << " ";
	}
	cout <<  endl;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned)time(NULL));
	int N = 20, min = 5, max = 100;
	char FileName[] = "input.txt";
	char OddFileName[] = "odd.txt";
	char EvenFileName[] = "even.txt";
	cout << "Select a menu item" << endl;
	Create(FileName, N, min, max);
	Process(FileName, OddFileName, EvenFileName);
	Print(FileName);
	Print(OddFileName);
	Print(EvenFileName);
}
