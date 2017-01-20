#include <iostream>
#include <string>
#include <string.h>
#include "Population.hpp"
#include "Member.hpp"
std::string target="the quick brown fox jumped";
int popMax=10000;
float mutationRate=0.01f;

int main(){
char a;
	Population p(target,popMax,mutationRate);
	while(!p.executeCycle()){
//	std::cin>>a;
//	 break;
	}
	return 0;
}
