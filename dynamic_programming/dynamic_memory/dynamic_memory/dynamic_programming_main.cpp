#include <iostream>
#include <vector>
#include "boost/tuple/tuple.hpp"
#include "inputData.h"


using boost::tuple;

typedef std::vector< tuple<double, double> > PCtuples;//list of tuples of P and C

void setupInput();
void displayInput();
void findPC_t(node, int);
void findBestPC();


//variables for findBestPC_t and findBestPC
	PCtuples temp, bestPC;


int main ()
{ 



setupInput();
//displayInput();
std::cout << "for n0, best (P, C) at time 1 is: " << std::endl;
findPC_t(n0, 1);
std::cout << "for n0 best (P, C) at time 2 is: " << std::endl;
findPC_t(n0, 2);
std::cout << "for n0, best (P, C) at time 3 is: " << std::endl;
findPC_t(n0, 3);
std::cout << "for n0 best (P, C) at time 4 is: " << std::endl;
findPC_t(n0, 4);
std::cout << "for n0 best (P, C) at time 5 is: " << std::endl;
findPC_t(n0, 5);

  std::cin.get();

  return 0;
}


void findPC_t(node node_num, int time)// find and display possible (P, C) for particular node# and t
{
			
		for (int i = 0; i < node_num.size(); i++) {
				for (int j = 0; j < node_num[i].size(); j++) {
					
					for (int k = 0; k < node_num[i][j].size(); k++) {
					
						if(node_num[i][j][k].get<0>() <= time && node_num[i][j][k].get<0>() > 0){
							if(k % 2 == 1)
							temp.push_back(tuple<double, double> (1, node_num[i][j][k].get<2>()));
							else
								temp.push_back(tuple<double, double> (node_num[i][j][k].get<1>(), node_num[i][j][k].get<2>()));
						}
					
					}
				}
		}

	std::cout << "TEMP LIST" << std::endl;
		for(int index1=0; index1 < temp.size(); index1++)
						{
							
						std::cout << "(" << temp[index1].get<0>() 
						<< ", " << temp[index1].get<1>() << ")" << std::endl;
						
						}
	//	temp.clear();
		
		findBestPC();

		std::cout << "BESTPC LIST" << std::endl;
		

	     for (int bestIndex = 0; bestIndex < bestPC.size(); bestIndex++) {
			std::cout << "(" << bestPC[bestIndex].get<0>() 
						<< ", " << bestPC[bestIndex].get<1>() << ")" << std::endl;
		 }		
					

					//	std::cout << "clear list" << std::endl;
						temp.clear();
						bestPC.clear();
					
}

void findBestPC(){
	
	bestPC.clear();
	
	
	int tempIndex = 0;
	if(bestPC.empty()){
	//	std::cout << "tuple empty, one tuple added to list" << std::endl;// initial for comparison
		bestPC.push_back(tuple<double, double> (temp[0].get<0>(), temp[0].get<1>()));//if bestPC is empty, get value of temp at index=0
		
	
	}
		             
			tempIndex =1;
					  double probability, cost;// value for each (P, C) in bestPC list
						int index = 0;
						int maxSize = bestPC.size();


						
				while(index < maxSize) {
					 probability = bestPC[index].get<0>();
						cost = bestPC[index].get<1>();
					   while(tempIndex<temp.size())
					{
						
						//std::cout << "tempIndex = " << tempIndex << std::endl;
						//std::cout << "temp.size() = " << temp.size() << std::endl;
						probability = bestPC[index].get<0>();
						cost = bestPC[index].get<1>();

							
						

				//	std::cout << " TEMP(" << temp[tempIndex].get<0>() 
						//<< ", " << temp[tempIndex].get<1>() << ")" << std::endl;
					//std::cout << " BESTPC(" << probability 
					//	<< ", " << cost << ")" << std::endl;
						
						if (temp[tempIndex].get<0>() <= probability && temp[tempIndex].get<1>() > cost) 
						{
							//std::cout << "temp (P, C) has worse cost and worst and equal probability, do nothing" << std::endl;
						}
						else if (temp[tempIndex].get<0>() == probability && temp[tempIndex].get<1>() == cost) 
						{
							//std::cout << "temp (P, C) has equal cost and probability, do nothing" << std::endl;
						}
				
						else if (temp[tempIndex].get<0>() > probability && temp[tempIndex].get<1>() <= cost)
						{
							//std::cout << "temp (P, C) has better or equal cost and  better probability, erase bestPC[bestIndex] and add temp (P,C) to bestPC" << std::endl;
							
							bestPC[index].get<0>() = temp[tempIndex].get<0>();
							bestPC[index].get<1>() = temp[tempIndex].get<1>();
							//std::cout << "bestPC[index].get<0>(), bestPC[index].get<1>() = " << bestPC[index].get<0>() << ", " << bestPC[index].get<1>() << std::endl;
						   // std::cout << "bestPC.size() = " << bestPC.size() << std::endl;
							
							
						}
						else if (temp[tempIndex].get<0>() == probability && temp[tempIndex].get<1>() < cost)
						{
							//std::cout << "temp (P, C) has better cost and equal probability" << std::endl;
							
							bestPC[index].get<0>() = temp[tempIndex].get<0>();
							bestPC[index].get<1>() = temp[tempIndex].get<1>();
						}
						else 
						{
							//std::cout << "temp (P, C) has better cost but worse probability" << std::endl;
							bestPC.push_back(tuple<double, double> (temp[tempIndex].get<0>(), temp[tempIndex].get<1>()));
						}
							// std::cout << "bestPC.size() = " << bestPC.size() << std::endl;
						tempIndex ++;
						
					}
					
						maxSize = bestPC.size();
						 //std::cout << "maxSize = " << maxSize << std::endl;
						  
						index ++;
						  //std::cout << "index = " << index << std::endl;
				}

				
						
					
	

	



	

	
}



