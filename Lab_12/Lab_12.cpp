#include <iostream>
#include "bilist.h"
#include "bi_node.h"

using namespace std;

int main()
{
	BiList A;
	int N;

	for ( int i = 0; i < 10; i++)
	{
		cin >> N;
		A.push_back(N);
	}
	A.forward_view();
	
	for ( int i = 0; i < A.size(); i++)
	{
		if (A[i] % 2 == 0)
		{
			BiNode* temp = A.get(i);
			A.insert(temp, A[i] - 1);
			i++;
		}
		else
		{
			BiNode* temp = A.get(i);
			A.insert(A[i] + 1, temp);
			i++;
		}
	}

	A.forward_view();

	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] % 3 == 0)
		{
			BiNode* temp = A.get(i);
			A.remove(temp);
			i--;
		}
	}

	A.forward_view();
}