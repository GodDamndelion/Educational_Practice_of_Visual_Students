#pragma once
#include <iostream>
#include <string>
#include <fstream>

template<class STInfo>
struct NODE_SBBT
{
	STInfo info;
	int count;
	NODE_SBBT* left, * right;
	NODE_SBBT(STInfo elem, int count, NODE_SBBT* left = nullptr, NODE_SBBT* right = nullptr) : info(elem), left(left), right(right), count(count) {};
	~NODE_SBBT() { left = nullptr; right = nullptr; }
};

template<class STInfo>
using Search_Balansed_Tree = NODE_SBBT<STInfo>*;

namespace Balansed_search_tree
{
	template<class STInfo>
	void Print_Tree(Search_Balansed_Tree<STInfo> t, int level);
	template<class STInfo>
	void Print_order(Search_Balansed_Tree<STInfo> t);
	template<class STInfo>
	void Clear_tree(Search_Balansed_Tree<STInfo>& t);
	template<class STInfo>
	void find_elem(Search_Balansed_Tree<STInfo>& r, Search_Balansed_Tree<STInfo>& q);
	template<class STInfo>
	bool Delete_element(Search_Balansed_Tree<STInfo>& t, STInfo elem);
}

template<class STInfo>
void Balansed_search_tree::Print_Tree(Search_Balansed_Tree<STInfo> t, int level)
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
void Balansed_search_tree::Print_order(Search_Balansed_Tree<STInfo> t)
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
void Balansed_search_tree::Clear_tree(Search_Balansed_Tree<STInfo>& t)
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
bool Balansed_search_tree::Delete_element(Search_Balansed_Tree<STInfo>& t, STInfo elem)
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
					Search_Balansed_Tree<STInfo> q = t;
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
struct Search_balansed_binary_tree
{
private:
	Search_Balansed_Tree<STInfo> root;
public:
	Search_balansed_binary_tree(std::string file_name)
	{
		std::ifstream file(file_name);
		STInfo elem;
		root = nullptr;
		while (file >> elem)
			Add(root, elem);
		file.close();
	}
	~Search_balansed_binary_tree()
	{
		Balansed_search_tree::Clear_tree(root);
	}
	void print()
	{
		Balansed_search_tree::Print_Tree(root, 0);
	}
	Search_Balansed_Tree<STInfo> get_tree()
	{
		return root;
	}
	void print_elements()
	{
		Balansed_search_tree::Print_order(root);
		std::cout << '\n';
	}
	bool search(STInfo elem);
	bool Delete(STInfo elem)
	{
		return Balansed_search_tree::Delete_element(root, elem);
	}
	void Balanse(Search_Balansed_Tree<STInfo>& tree);
	int count_levels(Search_Balansed_Tree<STInfo> tree);
	void Add(Search_Balansed_Tree<STInfo>& t, STInfo elem);
};

template<class STInfo>
bool Search_balansed_binary_tree<STInfo>::search(STInfo elem)
{
	Search_Balansed_Tree<STInfo> ptr = root;
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
void Balansed_search_tree::find_elem(Search_Balansed_Tree<STInfo>& r, Search_Balansed_Tree<STInfo>& q)
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

template<class STInfo>
inline void Search_balansed_binary_tree<STInfo>::Balanse(Search_Balansed_Tree<STInfo>& tree)
{
	if (tree->left)
		Balanse(tree->left);
	if (tree->right)
		Balanse(tree->right);
	if (tree)
	{
		if (count_levels(tree->left) > count_levels(tree->right) + 1)
		{
			Search_Balansed_Tree<STInfo> oldroot = tree;
			tree = oldroot->left;
			oldroot->left = tree->right;
			tree->right = oldroot;
		}
		else
			if (count_levels(tree->right) > count_levels(tree->left) + 1)
			{
				Search_Balansed_Tree<STInfo> oldroot = tree;
				tree = oldroot->right;
				oldroot->right = tree->left;
				tree->left = oldroot;
			}
	}
}

template<class STInfo>
inline int Search_balansed_binary_tree<STInfo>::count_levels(Search_Balansed_Tree<STInfo> tree)
{
	int result = 0, left = 0, right = 0;
	if (tree)
	{
		result = 1;
		if (tree->left)
		{
			left = count_levels(tree->left);
		}
		if (tree->right)
		{
			right = count_levels(tree->right);
		}
	}
	return result + (left > right ? left : right);
}

template<class STInfo>
inline void Search_balansed_binary_tree<STInfo>::Add(Search_Balansed_Tree<STInfo>& t, STInfo elem)
{
	if (!t)
	{
		t = new NODE_SBBT<STInfo>(elem, 1);
		Balanse(root);
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