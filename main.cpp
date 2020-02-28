#include <iostream>
#include <fstream>
#include "prqueue.h"

using namespace std;

PrQueue PQ;

void load_file(const std::string& filename, PrQueue& PQ);
void print_result(PrQueue& PQ);

int main() {
	PrQueue PQ;
	load_file("teams.txt", PQ)
	try {
		cout << PQ.f_max() << endl;
	}
	catch (PrQueue::Error ex) {
		if (ex == PrQueue::EMPTY_PRQUEUE) {
			cout << "ure sprior" << endl;
		}
	}
	//cout << "Hello World!\n";
	return 0;
}
void load_file(const std::string& filename, PrQueue& PQ) {
	ifstream in(filename.c_str());
	if (f.fail()) {
		cout << "File doesn't exist!\n";
		exit(1);
	}
	Item item;
	while (in >> item) {
		PQ.add(item);
	}
	in.close();
}
void print_result(PrQueue& PQ) {
	while (!PQ.is_empty()) {
		cout << PQ.remove_max() << endl;
	}
}
