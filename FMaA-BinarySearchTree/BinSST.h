#pragma once
#ifndef _BINSST_H
#define _BINSST_H

#include <string>
#include <iostream>
#include <vector>

class BinSST
{
public:
	BinSST(int value);

	int GetValue();
	BinSST* GetLeft();
	BinSST* GetRight();

	BinSST* Find(int value);
	void Insert(int value);
	void Delete(int value);
private:
	int _value;
	BinSST* _left = nullptr;
	BinSST* _right = nullptr;
};
#endif
