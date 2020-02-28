#include <iostream>
#include <fstream>
#include "prqueue.h"

using namespace std;

//#define NORMAL_MODE
#ifdef NORMAL_MODE

//PrQueue PQ;

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
#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
TEST_CASE("remove_max") {
	PrQueue PQ;
	CHECK_THROWS(PQ.remove_max());
	Item item(23, "Csapat1");
	Item item2(69, "Csapat2");
	Item item3(420, "Csapat3");
	PQ.add(item);
	PQ.add(item2);
	PQ.add(item3);
	CHECK(PQ.remove_max()._pr == 420);
	CHECK_FALSE(PQ.is_empty());
}
#endif