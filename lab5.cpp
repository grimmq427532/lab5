#include<iostream>
#include<iomanip>
#include<sstream>
#include<typeinfo>
#include<string>

using namespace std;

template <class T>
class HugeInt{

	// cout << overloaded
	friend ostream &operator<<(ostream & out,const HugeInt & obj){
		out << obj.value;
		return out;
	}

	// cin >> overloaded
	friend istream &operator>>(istream & in,HugeInt & obj){
		in >> obj.value;
		return in;
	}

public:
	// Initialize
	HugeInt(){ value = 0; }
	HugeInt(T init){
	// Check if T is string type
		if( typeid(T).name() == typeid(string).name() ){
			stringstream ss;
			ss.clear();
			ss.str("");
			// Convert string to integer and assign to menmber value
			ss << init ;
			int init_int;
			ss >> init_int;
			value = init_int;
		}

		else{
			value = init;
		}
	}

	// + overloaded
	int operator+(HugeInt & obj){
		return value+obj.getElement();
	}

	// - overloaded
        int operator-(HugeInt & obj){
                return value-obj.getElement();
        }


	// = overloaded
	void operator=(int assign_value){
		value = assign_value;
	}

	// Get member value
	int getElement(){
		return value;
	}

private:
	T value;
};


int main(){
	HugeInt<int> x;
	HugeInt<int> y(28825252);
	HugeInt<string> z("314159265358979323846");
	HugeInt<int> result;

	cin >> x;

	result = x+y;
	cout << x << "+" << y << " = " << result << endl;

	// conversion failed
	cout << z << endl;

	//result = z-x;
	//cout << result << endl;

	return 0;
}
