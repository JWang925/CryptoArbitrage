#include "aux.h"

double string_to_double(string input){
	double output;
//	if (input.front()=='"' && input.back()=='"'){ //check if input is quoted.
//		input.erase(0,1);
//		input.erase(input.size()-1);
//	}
//	else{
//		cout << "warning: input format of \"string_to_value\" is incorrect" <<endl;
//		cout << "input is:" << input;
//	}
	//here I should check if the string consists of numbers and at most one dot. Will do later.

	std::stringstream temp(input);
	temp >> output; //create stringstream from string and dump it into output;

	return output;
}


