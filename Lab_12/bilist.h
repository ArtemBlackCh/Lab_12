#pragma once
#include "bi_node.h"

struct BiList {

	BiNode* front;

	BiList();

	~BiList();

	void clear();

	BiNode* get_back();

	int size();

	void push_back(int x);

	void push_front(int x);

	void insert(int x, BiNode* node);

	void insert(BiNode* node, int x);

	void remove(BiNode* node);

	void forward_view();

	void reverse_view();

	BiNode* find(int key);

	BiNode* get(int index);

	int& operator[] (size_t index);

	void splice_in(BiList& List,int index);

	void splice_out(BiList& List, int index1, int index2);

	void sort();
};
