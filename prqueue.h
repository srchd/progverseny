#pragma once
#ifndef PRQUEUE_H
#define PRQUEUE_H

#include <string>
#include <vector>
#include <iostream>

struct Item {
	int _pr;
	std::string _data;
	Item() : _pr(0), _data("") {}
	Item(int Pr, const std::string& Data) : _pr(Pr), _data(Data) {}
	bool operator==(const Item& item) {
		return (this->_pr == item._pr && this->_data == item._data);
	}
	friend std::ostream& operator<<(std::ostream& os, const Item& item);
	friend std::istream& operator>>(std::istream& is, Item& item);
};

class PrQueue {
public:
	enum Error {EMPTY_PRQUEUE};
	bool is_empty() const;
	void clear_pr();
	void add(const Item& item);
	Item remove_max();
	Item f_max() const;

private:
	std::vector<Item> _vec;
	int _max_index() const;
};

#endif // !PRQUEUE_H