#include "BinSST.h"
void Recurse(std::vector<std::string>& vector, BinSST* node, int depth);

int main(int argc, char* argv[])
{
	BinSST* root;
	std::string str;
	std::cout << "Enter Root: ";
	std::getline(std::cin, str);
	int value = std::stoi(str);
	root = new BinSST(value);
	int count = 1;
	while (count < 8)
	{
		std::cout << "Enter Int: ";
		std::getline(std::cin, str);
		value = std::stoi(str);
		root->Insert(value);
		count++;
	}

	/*root = new BinSST(5);
	root->Insert(3);
	root->Insert(2);
	root->Insert(4);
	root->Insert(7);
	root->Insert(8);
	root->Insert(6);
	root->Insert(1);
	root->Insert(0);*/

	// Write Tree
	std::vector<std::string> output;
	Recurse(output, root, 0);
	for (int i = 0; i < output.size(); i++)
		std::cout << output[i] << std::endl;
}

void Recurse(std::vector<std::string>& vector, BinSST* node, int depth)
{
	if (vector.size() > depth)
	{
		std::string str = vector[depth];

		for (int i = 0; i < depth - 1; i++)
		{
			str += "";
		}

		str += " " + (node == nullptr ? "x" : std::to_string(node->GetValue()));
		vector[depth] = str;
	}
	else
	{
		for (int i = 0; i < depth - 1; i++)
		{
			vector[i] = " " + vector[i];
		}
		vector.push_back(node == nullptr ? "x" : std::to_string(node->GetValue()));
	}

	if (node == nullptr)
		return;

	Recurse(vector, node->GetLeft(), depth + 1);
	Recurse(vector, node->GetRight(), depth + 1);
}

BinSST::BinSST(int value)
{
	_value = value;
}

int BinSST::GetValue()
{
	return _value;
}

BinSST* BinSST::GetLeft()
{
	return _left;
}

BinSST* BinSST::GetRight()
{
	return _right;
}

BinSST* BinSST::Find(int value)
{
	if (value == _value)
		return this;

	BinSST* find = nullptr;

	if (value < _value && _left != nullptr)
		find = _left;
	else if (value > _value && _right != nullptr)
		find = _right;

	return find;
}

void BinSST::Insert(int value)
{
	if (value <= _value)
	{
		if (_left != nullptr)
			_left->Insert(value);
		else
			_left = new BinSST(value);
	}
	else if (value > _value)
	{
		if (_right != nullptr)
			_right->Insert(value);
		else
			_right = new BinSST(value);
	}
}

void BinSST::Delete(int value)
{
}
