#include<iostream>
#include<string>
#include<climits>
using namespace std;

int main(){
	string s;
	cout << "Max string length: " << s.max_size() << "\n" << CHAR_BIT*sizeof(void*) <<"\n";
	
	return 0;
}

