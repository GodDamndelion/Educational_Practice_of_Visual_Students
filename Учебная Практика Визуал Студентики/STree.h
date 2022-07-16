#pragma once
#include <iostream>
#include <string>
#include <fstream>

template<class STInfo>
struct NODE_ST
{
	STInfo info;
	int count;
	NODE_ST* left, * right;
	NODE_ST(STInfo elem, int count, NODE_ST* left = nullptr, NODE_ST* right = nullptr) : info(elem), left(left), right(right), count(count) {};
	~NODE_ST() { left = nullptr; right = nullptr; }
};

template<class STInfo>
using Search_Tree = NODE_ST<STInfo>*;

template<class STInfo>
void Add(Search_Tree<STInfo>& t, STInfo elem)
{
	if (!t)
	{
		t = new NODE_ST<STInfo>(elem, 1);
	}
	else
		if (elem < t->info)
			Add(t->left, elem);
		else
			if (elem > t->info)
				Add(t->right, elem);
			else
				t->count++;
}

template<class STInfo>
void Print_Tree(Search_Tree<STInfo> t, int level)
{
	if (t)
	{
		Print_Tree(t->right, level + 1);
		for (int i = 1; i <= level; i++)
			std::cout << '\t';
		std::cout << t->info << '\n';
		Print_Tree(t->left, level + 1);
	}
}

template<class STInfo>
void Print_order(Search_Tree<STInfo> t)
{
	if (t)
	{
		Print_order(t->left);
		for (int i = 1; i <= t->count; i++)
			std::cout << t->info << ' ';
		Print_order(t->right);
	}
}

template<class STInfo>
void Clear_tree(Search_Tree<STInfo>& t)
{
	if (t)
	{
		Clear_tree(t->left);
		Clear_tree(t->right);
		delete t;
		t = nullptr;
	}
}

template<class STInfo>
void find_elem(Search_Tree<STInfo>& r, Search_Tree<STInfo>& q);

template<class STInfo>
bool Delete_element(Search_Tree<STInfo>& t, STInfo elem)
{
	bool result = true;
	if (!t)
		result = false;
	else
	{
		if (elem < t->info)
			result = Delete_element(t->left, elem);
		else
			if (elem > t->info)
				result = Delete_element(t->right, elem);
			else
			{
				if (t->count > 1)
					t->count--;
				else
				{
					Search_Tree<STInfo> q = t;
					if (!q->right)
						t = q->left;
					else
						if (!q->left)
							t = q->right;
						else
							find_elem(q->left, q);
					delete q;
				}
			}
	}
	return result;
}

template<class STInfo>
struct Search_binary_tree
{
private:
	Search_Tree<STInfo> root;
public:
	Search_binary_tree(std::string file_name)
	{
		std::ifstream file(file_name);
		STInfo elem;
		root = nullptr;
		while (file >> elem)
			Add(root, elem);
		file.close();
	}
	~Search_binary_tree()
	{
		Clear_tree(root);
	}
	void print()
	{
		Print_Tree(root, 0);
	}
	Search_Tree<STInfo> get_tree()
	{
		return root;
	}
	void print_elements()
	{
		Print_order(root);
		std::cout << '\n';
	}
	bool search(STInfo elem);
	bool Delete(STInfo elem)
	{
		return Delete_element(root, elem);
	}
};

template<class STInfo>
bool Search_binary_tree<STInfo>::search(STInfo elem)
{
	Search_Tree<STInfo> ptr = root;
	bool result = false;
	while (ptr && !result)
	{
		if (elem < ptr->info)
			ptr = ptr->left;
		else
			if (elem > ptr->info)
				ptr = ptr->right;
			else
				result = true;
	}
	return result;
}

template<class STInfo>
void find_elem(Search_Tree<STInfo>& r, Search_Tree<STInfo>& q)
{
	if (r->right)
		find_elem(r->right, q);
	else
	{
		q->info = r->info;
		q->count = r->count;
		q = r;
		r = r->left;
	}

}