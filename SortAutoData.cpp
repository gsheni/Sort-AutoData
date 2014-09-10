
#include <cstring>
#include <string>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <sstream>
#include "AutoData.h"
#include "Brick.h"
#include "Bubble.h"
#include "QuickSort.h"

using namespace std;

int main (int argc, char *argv[]){
	if (argc != 5){ //if there is an incorrect number of arguments
		cout << "Incorrect Number of Command Line Arguments" << endl;
		exit(1);//exit program
	}
	std::string filetoopen;
	filetoopen = argv[1];
	std::ifstream infile(filetoopen.c_str()); // This uses the ifstream class to open and read the text file line by line
	vector<AutoData> autodat; //create vector of autodata objects
	std::string line;
	std::string token;
	vector<string> tempinput; //this is for temporarily taking the input of string inputs from fstream
	int  tosort = atoi(argv[3]); //how many to sort
	int linecount = 0;
	if (infile.is_open()){ // as long as file can be open 
		while (std::getline(infile, line))	{
			istringstream ss(line);
			while(std::getline(ss, token, ':')) {
				tempinput.push_back(token); //push the string stream.
			}
			linecount++;
			if (linecount == tosort){
				goto leave; //if the number of data to be read is reached, then stop. 
			}
		}
}
		
	else{
		cout << "Can't open the file. Wrong filename or doesn't exist." << endl;
		exit(1); //can't open file, exit. 
	}
leave://come here if you reach the number of data ot be read. 
for (int i  = 0; i < tempinput.size() ; i = i + 9 ){ //take the string stream inputs and put them into the correct data type, and push onto vector of autodata objects 
			float tempmpg = atof(tempinput[i].c_str());
			int tempcyl = atoi(tempinput[i+1].c_str());
			float tempdis = atof(tempinput[i+2].c_str());
			float temphor = atof(tempinput[i+3].c_str());
			float tempwei = atof(tempinput[i+4].c_str());
			float tempacc = atof(tempinput[i+5].c_str());
			int tempmod = atoi(tempinput[i+6].c_str());
			int tempori = atoi(tempinput[i+7].c_str());
			string tempcar = tempinput[i+8];
			AutoData tempdata(tempmpg,tempcyl,tempdis,temphor,tempwei,tempacc,tempmod,tempori,tempcar); // take the data types and make a AutoData object
			autodat.push_back(tempdata);//push that autodata object onto the vector of Autodata 
		}
	string check1 = argv[2];
	if(check1 == "bubble"){
		bubblesort(autodat); //sort bubble
	}
	else if(check1 == "quick"){
		quicksort(autodat); //sort quick
	}
	else if(check1 == "brick"){
		bricksort(autodat); //sort brick
	}
	string check3 = argv[4];
	 if (check3 ==  "verbose"){
		for (int i  = 0; i < autodat.size() ; i ++ ){
			cout << autodat[i]; //print out the data if the user wants it verbose.
		}
	}
	else if (check3 ==  "terse"){ //print the number of swaps if the user wants it terse.
		if(check1 == "bubble"){
			cout << "The number of bubble sort swaps is " << bubbleswapcount <<endl;

		}
		else if(check1 == "quick"){
			cout << "The number of quick sort swaps is " << quickswapcount  <<endl;

		}
		else if(check1 == "brick"){
			cout << "The number of brick sort swaps is " << brickswapcount<<endl;


		}
	}
}
