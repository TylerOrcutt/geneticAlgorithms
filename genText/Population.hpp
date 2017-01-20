#ifndef __POPULATION_H_
#define __POPULATION_H_
#include <string>
#include <string.h>
#include <vector>
#include "Member.hpp"
#include <thread>
class Population{
	public:
		std::vector<Member> members;
		std::string target;
		int maxPop=0;
		float mutationRate=0.f;

		static const int threads = 2;	
		int generation = 0;

		Population(std::string  _target,int _maxPop, float _mutationRate){
		target=_target;
		maxPop =_maxPop;
		mutationRate = _mutationRate;
		std::cout<<"Target length: "<<target.length()<<"\n";
		
		for(int i=0;i<maxPop;i++){
			members.push_back(Member(target.length()));
		}
		}


		bool executeCycle(){
			int maxfit = 0;
			int maxid=0;
			for(int i=0;i<maxPop;i++){
				int ft = members[i].calcFitness(target);
				if(ft>maxfit){
					maxfit=ft;
					maxid = i;
				}
			//	std::cout<<members[i].chs<<"\n";
			}
			generation++;

			std::cout<<"Max Fittness: "<<maxfit<<" : "<<members[maxid].chs<<"  Generation: "<<generation<<"\n";
			selection(maxfit);
			return (maxfit>=(target.length()+1)*2)?true:false;
		
		}

		void selection(int maxfit){
		
		
			std::vector<Member> npop;
			for(int i=0;i<maxPop;i++){
				if(((float)(rand()%100))/100.0f  <=mutationRate){
				
				        Member m(target.length());
				       	npop.push_back(m);
					continue;
				}
					
					while(true){
						int mate = rand()%maxPop;
						if (mate ==i){ continue;}
						if(rand()%((target.length()+1)*2) < members[mate].fitness){
							std::string data =  members[i].crossover(members[mate]);
							Member  m(data);
						        npop.push_back(m);
						break;
						}
					}							

				}
			//for(int i=0;i<maxPop;++i){
			//	members[i]=npop[i];
			//}
			members=npop;
		}



};


#endif
