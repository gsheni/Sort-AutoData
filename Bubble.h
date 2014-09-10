#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <functional>
using namespace std;
int bubbleswapcount = 0;
template <typename Comparable>
void bubblesort( vector<Comparable> & a ){
bool swapped = true;
while (swapped){
	swapped = false;
	for (int i =0; i < a.size() - 1 ; i++){
		if (a[i+1]< a[i]){
			swap (a[i],a[i+1]);
			bubbleswapcount++;
			swapped = true;
		}
	}
}
}
