
#include <iostream>
#include "Vector.h"
#include "Set.h"
#include <ctime>
#include <cstdlib>

using namespace std;

void populateList(Vector<int> &list, const int size) {
	srand(time(0)); //seed time
	for (int i = 0; i < size; ++i) {
		int randomValue = rand() % 54 + 1;
		list.push_back(randomValue);
	}
}

void fillSetA(const Vector<int>& list, Set<int>& set) { //between 3 and 36 and multiple of 3
	for (int i = 0; i < list.size(); i++) {
		if (list[i] % 3 == 0 && list[i] >= 3 && list[i] <= 36) {
			set.insert(list[i]);
		}

	}

}

void fillSetB(const Vector<int>& list, Set<int>& set) { //between 18 and 54 and multiple of 3
	for (int i = 0; i < list.size(); ++i) {
		if (list[i] % 3 == 0 && list[i] >= 18 && list[i] <= 54) {
			set.insert(list[i]);
		}
	}

}


int main() {

	
	const int size = 100; //store n elements in the vector/set
	Vector<int> list;
	populateList(list,size);

	Set<int> setA;
	Set<int> setB;

	fillSetA(list,setA);
	fillSetB(list,setB);

	cout << "Set A:\n";
	setA.printTree();
	cout << "Set B:\n";
	setB.printTree();

	int depthA = setA.getMaxDepth();
	int depthB = setB.getMaxDepth();

	cout << "\nThe Maximum depth of Set A is: " << depthA << endl;
	cout << "\nThe Maximum depth of set B is: " << depthB << endl;

	Set<int> unionSet = setA.Union(setB);
	Set<int> intersectionSet = setA.intersection(setB);

	Set<int> AdifB = setA.difference(setB);
	Set<int> BdifA = setB.difference(setA);

	cout << "Union set:\n";
	unionSet.printTree();

	cout << "Intersection Set:\n";
	intersectionSet.printTree();

	cout << "Difference of A and B:\n";
	AdifB.printTree();

	cout << "Difference of B and A:\n";
	BdifA.printTree();




	return 0;
}