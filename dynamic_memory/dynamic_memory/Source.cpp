#include <iostream>
#include <vector>
#include "boost/tuple/tuple.hpp"


using boost::tuple;
typedef std::vector< tuple<double, double, double> > tuple_list;//list of tuples of values t time, P probabilty, and C cost 
typedef std::vector< tuple<double, double> > PCtuples;//list of tuples of P and C
typedef std::vector<tuple_list> node_mode; //node_mode 
typedef std::vector<node_mode> node;//node 
typedef std::vector<node> nodes;
void setupInput();
void displayInput();
void findBestPC_t(node, int);
void findBestPC(double probability, double cost);

//variables for setupInput
	node_mode n0R1, n0R2, n1R1, n1R2, n2R1, n2R2, n3R1, n3R2;
	node n0, n1, n2, n3; 
	nodes n;
    tuple_list n0R1l1, n0R2l1, n1R1l1, n1R2l1, n2R1l1, n2R2l1, n3R1l1, n3R2l1;
//variables for findBestPC_t and findBestPC
	PCtuples temp_tuples;


int main ()
{ 




setupInput();
displayInput();
std::cout << "for n0, best (P, C) at time 1 is: " << std::endl;
findBestPC_t(n0, 1);
std::cout << "for n0 best (P, C) at time 2 is: " << std::endl;
findBestPC_t(n0, 2);
std::cout << "for n0, best (P, C) at time 3 is: " << std::endl;
findBestPC_t(n0, 3);
std::cout << "for n0 best (P, C) at time 4 is: " << std::endl;
findBestPC_t(n0, 4);
std::cout << "for n0 best (P, C) at time 5 is: " << std::endl;
findBestPC_t(n0, 5);

  std::cin.get();

  return 0;
}

void setupInput(){

	// setup table input

	
    n0R1l1.push_back(tuple<double, double, double> (1, 0.8, 9)); 
	n0R1l1.push_back(tuple<double, double, double> (2, 0.2, 9));
	
	n0R2l1.push_back(tuple<double, double, double> (2, 0.8, 5));
	n0R2l1.push_back(tuple<double, double, double> (3, 0.2, 5));
	
	n1R1l1.push_back(tuple<double, double, double> (1, 0.9, 10));
	n1R1l1.push_back(tuple<double, double, double> (3, 0.1, 10));
	
	n1R2l1.push_back(tuple<double, double, double> (2, 0.7, 4)); 
	n1R2l1.push_back(tuple<double, double, double> (4, 0.3, 4)); 
	
	n2R1l1.push_back(tuple<double, double, double> (1, 0.9, 9));
	n2R1l1.push_back(tuple<double, double, double> (4, 0.1, 9));
	
	n2R2l1.push_back(tuple<double, double, double> (2, 0.8, 5));
	n2R2l1.push_back(tuple<double, double, double> (6, 0.2, 5));
	
	n3R1l1.push_back(tuple<double, double, double> (1, 0.2, 8));
	n3R1l1.push_back(tuple<double, double, double> (2, 0.8, 8));

	n3R2l1.push_back(tuple<double, double, double> (3, 0.4, 2));
	n3R2l1.push_back(tuple<double, double, double> (6, 0.6, 2));


	n0R1.push_back(n0R1l1);
	n0R2.push_back(n0R2l1);
	n1R1.push_back(n1R1l1);
	n1R2.push_back(n1R2l1);
	n2R1.push_back(n2R1l1);
	n2R2.push_back(n2R2l1);
	n3R1.push_back(n3R1l1);
	n3R2.push_back(n3R2l1);
	n0.push_back(n0R1);
	n0.push_back(n0R2);
	n1.push_back(n1R1);
	n1.push_back(n1R2);
	n2.push_back(n2R1);
	n2.push_back(n2R2);
	n3.push_back(n3R1);
	n3.push_back(n3R2);
	n.push_back(n0);
	n.push_back(n1);
	n.push_back(n2);
	n.push_back(n3);


}

void displayInput() {


	for (int i = 0; i < n.size(); i++) {
	for (int j = 0; j < n[i].size(); j++) {
		std::cout << "n" << i << "R" << j+1 << std::endl;
		for (int k = 0; k < n[i][j].size(); k++) {
			for (int l = 0; l < n[i][j][k].size(); l++) {
			std::cout << "(" << n[i][j][k][l].get<0>() << ", " << n[i][j][k][l].get<1>() << ", " << n[i][j][k][l].get<2>() << ")" << std::endl;
			}
		}
	}
}	



}
void findBestPC_t(node node_num, int time)
{
			
		for (int i = 0; i < node_num.size(); i++) {
				for (int j = 0; j < node_num[i].size(); j++) {
					
					for (int k = 0; k < node_num[i][j].size(); k++) {
					
						if(node_num[i][j][k].get<0>() <= time && node_num[i][j][k].get<0>() > 0){
							if(k % 2 == 1){
							findBestPC(1, node_num[i][j][k].get<2>());
					
							}
							else{
								findBestPC(node_num[i][j][k].get<1>(), node_num[i][j][k].get<2>());
								
							}
							
						
						}
					
					}
					
				}
					
		}
	for(int index=0; index < temp_tuples.size(); index++)
						{
						std::cout << "(" << temp_tuples[index].get<0>() 
						<< ", " << temp_tuples[index].get<1>() << ")" << std::endl;
						
						}
						std::cout << "clear list" << std::endl;
						temp_tuples.clear();
}

void findBestPC(double probability, double cost){
	if (!temp_tuples.empty()){
		for(int index=0; index < temp_tuples.size(); index++)
					{
						if (temp_tuples[index].get<0>() > probability && temp_tuples[index].get<1>() <= cost) //if the items in list is better choice than input, don't add to list
						{
							std::cout << "temp_tuples[index].get<0>() > probability && temp_tuples[index].get<1>() < cost" << std::endl;
						}
						else if (temp_tuples[index].get<0>() == probability && temp_tuples[index].get<1>() == cost)// if the items in list is equal to the input tuple (P,C), then don't add to list
						{
							std::cout << "temp_tuples[index].get<0>() == probability && temp_tuples[index].get<1>() == cost" << std::endl;
						}
						else if (temp_tuples[index].get<0>() <= probability && temp_tuples[index].get<1>() < cost)// if the item in the list has bigger or equal P but lower cost, 
						{
							std::cout << "erased and added" << std::endl;
						temp_tuples.erase(temp_tuples.begin() + index);
						

							temp_tuples.push_back(tuple<double, double> (probability, cost));
						}
						else{
							
						std::cout << "added" << std::endl;
							//temp_tuples.erase(temp_tuples.begin() + index);

						
							temp_tuples.push_back(tuple<double, double> (probability, cost));
						}
						
					}
	}
	

	else {	

		std::cout << "tuple empty, one tuple added to list" << std::endl;
	temp_tuples.push_back(tuple<double, double> (probability, cost));//if empty
	}
}




