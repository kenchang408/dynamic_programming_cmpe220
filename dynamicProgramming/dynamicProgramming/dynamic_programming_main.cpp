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
void findBestPC_parallel(PCtuples);
void displayPClist(PCtuples);
int pnode_num=0;

//variables for findBestPC_t and findBestPC
	PCtuples temp, bestPC, temp2, bestPCnode2, bestPCnode3, parallel_bestPC, parallel_bestPC1, parallel_bestPC2; 


int main ()
{ 

double node_num;
double time; 
char exit = NULL;

setupInput();
//displayInput();
std::cout<<"WELCOME.  THIS PROMGRAM WILL CALCULATE B TABLE AND D TABLE \n";
std::cout<<"------------------------------------------------------------------------------------------- \n";


while (exit != 'y') {
std::cout<<"Enter node# (0-3).  Note that 2 or 3 indicates combined parallel node (2,3): ";
std::cin>>node_num;
if (node_num < 0 || node_num > 3)
{
	
	std::cout<<"Not Valid !!!";
	std::cout<<"Enter node# (0-3).  Note that 2 or 3 indicates combined parallel node (2,3): ";
	std::cin>>node_num;

}
std::cout<<"Enter time constraint (integers > 0): ";
std::cin>>time;

std::cout<<"B TABLE\n";

if(node_num == 2 || node_num == 3){
std::cout << "for node (2,3), best (P, C) at time = " << time << " is: " << std::endl;
pnode_num = 2;
findPC_t(n[2], time);
pnode_num = 3;
findPC_t(n[3], time);

findBestPC_parallel(parallel_bestPC1);

}
else {
	std::cout << "for node" << node_num << ", best (P, C) at time = " << time << " is: " << std::endl;
	findPC_t(n[node_num], time);
}
std::cout<<"D TABLE\n";
if(node_num == 2 || node_num == 3){
std::cout << "for node (2,3), best (P, C) at time = " << time << " is: " << std::endl;
pnode_num = 2;
findPC_t(n[2], time);
pnode_num = 3;
findPC_t(n[3], time);

findBestPC_parallel();

}
else {
	std::cout << "for node" << node_num << ", best (P, C) at time = " << time << " is: " << std::endl;
	findPC_t(n[node_num], time);
}




parallel_bestPC.clear();
std::cout<<"Enter y to exit: ";
std::cin>>exit;

};
 

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
/*
	std::cout << "TEMP LIST" << std::endl;
		for(int index1=0; index1 < temp.size(); index1++)
						{
							
						std::cout << "(" << temp[index1].get<0>() 
						<< ", " << temp[index1].get<1>() << ")" << std::endl;
						
						}

						*/
	//	temp.clear();
		
		findBestPC();

	//std::cout << "BESTPC LIST" << std::endl;
		

	     	
					


					//	std::cout << "clear list" << std::endl;
						if( pnode_num == 2)
							 bestPCnode2 = bestPC;
						else if ( pnode_num == 3)
							bestPCnode3 = bestPC;
						else {

							for (int bestIndex = 0; bestIndex < bestPC.size(); bestIndex++) {
			std::cout << "(" << bestPC[bestIndex].get<0>() 
						<< ", " << bestPC[bestIndex].get<1>() << ")" << std::endl;
		 }	



						}
						
						temp.clear();
						bestPC.clear();
					   
}

void findBestPC(){
	
	bestPC.clear();
	
	if(bestPC.empty()){
	//	std::cout << "tuple empty, one tuple added to list" << std::endl;// initial for comparison
		bestPC.push_back(tuple<double, double> (temp[0].get<0>(), temp[0].get<1>()));//if bestPC is empty, get value of temp at index=0
	}
		             
			
					  double probability, cost;// value for each (P, C) in bestPC list
						int index = 0;
						int maxSize = bestPC.size();


						
				while(index < maxSize) {
					
					
					   for(int tempIndex=1; tempIndex < temp.size(); tempIndex++){
					
					
						probability = bestPC[index].get<0>();
						cost = bestPC[index].get<1>();
						int ignore = 0;

						for (int test = 1; (test < bestPC.size()); test++){
								if ((temp[tempIndex].get<0>() == bestPC[test].get<0>()) && (temp[tempIndex].get<1>() == bestPC[test].get<1>()) ){
									ignore = 1;
								}
								if (temp[tempIndex].get<0>() <= bestPC[test].get<0>() && temp[tempIndex].get<0>() > bestPC[test].get<1>()) {
										ignore = 1;
								}
										
								
								

							}	
						

				//	std::cout << " TEMP(" << temp[tempIndex].get<0>() 
						//<< ", " << temp[tempIndex].get<1>() << ")" << std::endl;
				//	std::cout << " BESTPC(" << probability 
						//<< ", " << cost << ")" << std::endl;
						if (ignore !=1)
						{   

							int duplicate = 0;
								
								for(int i = 0; (i < bestPC.size()) && (duplicate != 1); i++){
									if(temp[tempIndex].get<0>() == bestPC[i].get<0>() && temp[tempIndex].get<1>() == bestPC[i].get<1>())
									duplicate = 1;
								}
							

							if (temp[tempIndex].get<0>() <= probability && temp[tempIndex].get<1>() > cost) 
							{
									//std::cout << "temp (P, C) has worse cost and worst and equal probability, do nothing" << std::endl;
							}
							else if (temp[tempIndex].get<0>() > probability && temp[tempIndex].get<1>() <= cost)
							{
									//std::cout << "temp (P, C) has equal or better cost and  better probability" << std::endl;
									if(duplicate!= 1){
									bestPC[index].get<0>() = temp[tempIndex].get<0>();
									bestPC[index].get<1>() = temp[tempIndex].get<1>();
									}
									
							}
							else if (temp[tempIndex].get<0>() > probability && temp[tempIndex].get<1>() > cost)
							{
								//std::cout << "temp (P, C) has worst cost and better probability" << std::endl;
								if(duplicate!= 1)
								bestPC.push_back(tuple<double, double> (temp[tempIndex].get<0>(), temp[tempIndex].get<1>()));	
							}

							else if (temp[tempIndex].get<0>() == probability && temp[tempIndex].get<1>() < cost)
							{
									//std::cout << "temp (P, C) has better cost and  equal probability" << std::endl;
								if(duplicate!= 1){
									bestPC[index].get<0>() = temp[tempIndex].get<0>();
									bestPC[index].get<1>() = temp[tempIndex].get<1>();
								}
						
							}
							else 
							{
									//std::cout << "temp (P, C) has better cost but worse probability" << std::endl;
								
									if(duplicate!= 1)
									bestPC.push_back(tuple<double, double> (temp[tempIndex].get<0>(), temp[tempIndex].get<1>()));
						
							}
						
						
						
						}
						
						
						
						
						}
					

						maxSize = bestPC.size();
						// std::cout << "maxSize = " << maxSize << std::endl;
						  
						index ++;
						  //std::cout << "index = " << index << std::endl;
				}	

	temp2 = bestPC;
	for (int test1 = 0; test1 < temp2.size(); test1++){				
		for(int test2 = 0; test2 < bestPC.size(); test2++)
		{
		if ((temp2[test1].get<0>() > bestPC[test2].get<0>()) && (temp2[test1].get<1>() <= bestPC[test2].get<1>()) )
			bestPC.erase(bestPC.begin() + test2);
		if ((temp2[test1].get<0>() == bestPC[test2].get<0>()) && (temp2[test1].get<1>() < bestPC[test2].get<1>()) )
			bestPC.erase(bestPC.begin() + test2);
		}
		


	}
	



}

void findBestPC_parallel(PCtuples tuplelist){

	for(int i = 0; i < bestPCnode2.size(); i++) {

		for(int j = 0; j < bestPCnode3.size(); j++) {


			parallel_bestPC.push_back(tuple<double, double> (bestPCnode2[i].get<0>() * bestPCnode3[j].get<0>(), bestPCnode2[i].get<1>()+bestPCnode3[j].get<1>()));

		}


	}


	displayPClist(parallel_bestPC);

   




}

void displayPClist(PCtuples tuplelist){
	for (int bestIndex = 0; bestIndex < tuplelist.size(); bestIndex++) {
			std::cout << "(" << tuplelist[bestIndex].get<0>() 
						<< ", " << tuplelist[bestIndex].get<1>() << ")" << std::endl;
		 }	



}
void create_Dtable()
{




}