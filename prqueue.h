#pragma once
#ifndef PRQUEUE_H
#define PRQUEUE_H

struct Item {
	int _pr;
	std::string _data;
	Item() : _pr(0), _data("") {}
	Item(int Pr, const std::string& Data) : _pr(Pr), _data(Data) {}
};

#endif // !PRQUEUE_H
