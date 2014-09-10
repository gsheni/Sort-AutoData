#include <iostream>
#include <vector>
#include <functional>
using namespace std;
int brickswapcount = 0; //keep track of how many brick swaps occur, global so access by main. 
template<typename Comparable>
void bricksort(vector<Comparable>&a){
	bool even = true;//to keep track of which pair
	bool odd = true;//to keep track of which pair	
	bool occuredeven = true;//to keep track of which pair
	bool occuredodd = true; //to keep track of which pair
	const int sizeofvector = a.size(); //get size of input vector to be used later on. 
	while (occuredeven || occuredodd){
		occuredeven = false;
		occuredodd = false;
		even = false;
		odd = false; 
		//Compares all (odd-even) indexed pairs of adjacent
		//elements in a list and switches them if they are out of
		//order.
		for(int b=1;b < sizeofvector - 1; b = b + 2){
			if(a[b]>a[b+1]){
				swap(a[b],a[b+1]); //swap added later on, takes into account parrallel. 
				occuredeven = true;
				even = true;
			}
		}

		if (occuredeven == true){ // see if the swap occurred
			brickswapcount++; //add to swap count. 
		}
		//The next step repeats this process for (even-
		//odd) indexed pairs and continues alternating until the
		//list is sorted.
		for(int b=0;b<sizeofvector - 1;b = b +2){
			if(a[b]>a[b+1]){
				swap(a[b],a[b+1]); //swap added later on, takes into account parrallel. 
				occuredodd = true;
				odd = true;
			}
		}
		if(occuredodd == true){ // see if the swap occurred
			brickswapcount++; //add to swap count. 
			}
		}	
	}




