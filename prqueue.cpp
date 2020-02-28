#include "prqueue.h"

bool PrQueue::is_empty() const {
	return (_vec.size() == 0);
}
void PrQueue::clear_pr() {
	_vec.clear();
}
void PrQueue::add(const Item& item) {

}
Item PrQueue::remove_max() {

}
Item PrQueue::f_max() const {

}
int PrQueue::_max_index() const{
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