#ifndef __MEMBER_H_
#define __MEMBER_H_
#include <string>
//#include <vector>
#include <stdlib.h>
#include <time.h>
#include <math.h>
class Member{
	public:
	int targetsize;
	std::string chs;
	float fitness=0;

	Member(int _targetsize){
	targetsize=_targetsize;
		for(int i=0;i<targetsize;i++){
			chs+=randomchar();
		}
	}

	Member(std::string c){
		chs = c;
		targetsize=c.length();
	}
	void reset(std::string data){
		fitness=0;
		chs=data;
	}
	
	std::string randomchar(){
		std::string rc = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";
	  return rc.substr(rand()%rc.length(),1);
	}

	
	float calcFitness(std::string target){
		float ft=0;
		
		for(int i=0;i<target.length();i++){
			if(target.substr(i,1) == chs.substr(i,1)){
				ft++;

			}
		}
		++ft;
		ft*=2;
		fitness=ft;
			return ft;
	}

	std::string crossover(Member &m){
		std::string nc="";
		
		int mid = rand()%targetsize;
		for(int i=0;i<targetsize;i++){
			if(i> mid){
				nc+=chs.substr(i,1);
			}else{
				nc+=m.chs.substr(i,1);
			}
		}
		return nc;
	}

	void mutation(int len){


		for(int i=0;i<len;i++){
			chs+=randomchar();
		}
	}

	

};


#endif 
