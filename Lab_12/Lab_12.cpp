#include <iostream>
#include "bilist.h"
#include "bi_node.h"

using namespace std;

int main()
{
	BiList A, B;
	int inputA[] = { 1,3,5,7,9 };
	int inputB[] = { 2,4,6,8,10 };

	for (auto const& N : inputA)
	{
		A.push_back(N);
	}

	for (auto const& N : inputB)
	{
		B.push_back(N);
	}

	cout << "A : ";
	A.forward_view();
	cout << "B : ";
	B.forward_view();

	int index;
	cin >> index;

	A.splice_in(B, index);

	cout << "A : ";
	A.forward_view();
	cout << "B : ";
	B.forward_view();
}
