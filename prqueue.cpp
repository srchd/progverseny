#include "prqueue.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const Item& item) {
	os << "Team: " << item._data << ", points: " << item._pr << endl;
	return os;
}
std::istream& operator>>(std::istream& is, Item& item) {
	is >> item._data >> item._pr;
	return is;
}

bool PrQueue::is_empty() const {
	return (_vec.size() == 0);
}
void PrQueue::clear_pr() {
	_vec.clear();
}
void PrQueue::add(const Item& item) {
	_vec.push_back(item);
}
Item PrQueue::remove_max() {
	if (is_empty()) throw EMPTY_PRQUEUE;
	int ind = _max_index();
	Item result = _vec[ind];
	_vec[ind] = _vec.back();
	//_vec[ind] = _vec[_vec.end()];
	_vec.pop_back();
	return result;
}
Item PrQueue::f_max() const {
	if (is_empty()) throw EMPTY_PRQUEUE;
	return _vec[_max_index()];
}
int PrQueue::_max_index() const{
	if (is_empty()) throw EMPTY_PRQUEUE;
	int max_pr = _vec[0]._pr;
	int ind = 0;
	for (unsigned int i = 1; i < _vec.size(); i++) {
		if (_vec[i]._pr > max_pr) {
			max_pr = _vec[i]._pr;
			ind = i;
		}
	}
	return ind;
}