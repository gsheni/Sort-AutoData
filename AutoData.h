#include<stdlib.h>
#include<iostream>
#include<string>

using namespace std;

class AutoData{
private:
	float mpg;
	int cylinders;
	float displacement;
	float horsepower;
	float weight;
	float acceleration;
	int modelyear;
	int origin;
	string carname;
public:
	AutoData(){
		mpg = 0;
		cylinders = 0;
		displacement = 0;
		horsepower = 0;
		weight = 0;
		acceleration = 0;
		modelyear= 0;
		origin= 0;
		carname= "";
		//Constructor
	}
	AutoData(float mpg1,int cylind1,float displace1,float horse,float weigh1,float acce1,int model1,int orig1,string carn1){
		mpg = mpg1;
		cylinders = cylind1;
		displacement = displace1;
		horsepower = horse;
		weight = weigh1;
		acceleration = acce1;
		modelyear= model1;
		origin= orig1;
		carname= carn1;
	}
	~AutoData()
	{}
//accessor functions below 
	float getmpg() const{
		return mpg;
	}
	int getcylinders() const{
		return cylinders;
	}
	float getdisplacement() const{
		return displacement;
	}
	float gethorsepower() const{
		return horsepower;
	}
	float getweight() const{
		return weight;
	}
	float getacceleration() const{
		return acceleration;
	}
	int getmodelyear() const{
		return modelyear;
	}
	int getorigin() const{
		return origin;
	}
	string getcarname() const{
		return carname;
	}
//mutator functions below.
	void setmpg(float mpg1){
		mpg = mpg1;
	}
	void setcylinders(int cylinders1){
		cylinders=cylinders1;
	}
	void setdisplacement(float displacement1){
		displacement = displacement1;
	}
	void sethorsepower(float horsepower1){
		horsepower = horsepower1;
	}
	void setweight(float weight1){
		weight= weight1;
	}
	void setacceleration(float acceleration1){
		acceleration = acceleration1;
	}
	void setmodelyear(int modelyear1){
		modelyear = modelyear1;
	}
	void setorigin(int origin1){
		origin = origin1;
	}
	void setcarname(string carname1){
		carname = carname1;
	}
//compare two autodata objects
	bool operator < ( const AutoData & rhs ) const{
		if ( getmpg() < rhs.getmpg() ){ //compare by mpg
			return true;
		}
		else if(getmpg() ==  rhs.getmpg()){//if mpg is same, compare by horse power.
			if(gethorsepower() < rhs.gethorsepower()){
				return true;
			}
			else {
				return false;
			}
		}
		else{
			return false;
		}
	}
    friend ostream& operator<<(ostream& os, const AutoData & rhs); //make the ostream an friend function so it can be defined later
	bool operator== ( const AutoData & rhs ) const{ //operator to see if two autodata objects are equal, not needed
		if(getmpg() ==  rhs.getmpg()){
			if(gethorsepower() == rhs.gethorsepower()){
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	bool operator!= ( const AutoData & rhs ) const
    		  { return !( *this == rhs ); } //just the opposite of the equals
//compare two autodata objects
	bool operator>( const AutoData & rhs ) const{
		if ( getmpg() > rhs.getmpg() ){ //compare by mpg
			return true;
		}
		else if(getmpg() ==  rhs.getmpg()){
			if(float(gethorsepower()) > float(rhs.gethorsepower())){ //if mpg is same, compare by horse power.
				return true;
			}
			else {
				return false;
			}
		}
		else{
		return false;
		}
	}
};
ostream& operator<<(ostream& os, const AutoData & rhs) //friend fucntion is defined below to get the data of the currect Autodata object and give a ostream back.
{
    os << rhs.getmpg() << ":"<< rhs.getcylinders() << ":"<< rhs.getdisplacement() << ":" <<
    rhs.gethorsepower() << ":"<< rhs.getweight( )<< ":"<< rhs.getacceleration() << ":"<<
    rhs.getmodelyear() << ":"<< rhs.getorigin() << ":"<< rhs.getcarname() << endl;
    return os; 

}
