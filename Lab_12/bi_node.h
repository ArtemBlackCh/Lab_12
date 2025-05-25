#pragma once

struct BiNode 
{
	int data;
	BiNode* prev, * next;

	BiNode(int x = 0) { data = x; prev = nullptr; next = nullptr; }

	BiNode* get_back(BiNode* F);

	BiNode* push_back(BiNode* F, int x);

	BiNode* push_front(BiNode* F, int x);

	BiNode* insert(BiNode* F, int x, BiNode* node);

	BiNode* insert(BiNode* F, BiNode* node, int x);

	BiNode* remove(BiNode* F, BiNode* node);

	void forward_view(BiNode* F);

	void reverse_view(BiNode* F);

	BiNode* clear(BiNode* F);

	BiNode* find(BiNode* F, int key);

	BiNode* get(BiNode* F, int index);
	
	BiNode* splice_in(BiNode* F1, BiNode* F2,int index1);

	BiNode* splice_out(BiNode* F1, BiNode* F2, int index1, int index2);

	void swap(BiNode* N1, BiNode* N2);

	BiNode* sort(BiNode* F);

	int size(BiNode* F);
};