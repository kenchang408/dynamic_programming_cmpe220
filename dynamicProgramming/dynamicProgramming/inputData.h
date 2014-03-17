//inputData.h

#ifndef __INPUTDATA_H_INCLUDED__   // if x.h hasn't been included yet...
#define __INPUTDATA_H_INCLUDED__   //   #define this so the compiler knows it has been included





#include <vector>
#include "boost/tuple/tuple.hpp"

using boost::tuple;

typedef std::vector< tuple<double, double, double> > tuple_list;//list of tuples of values t time, P probabilty, and C cost 
typedef std::vector<tuple_list> node_mode; //node_mode 
typedef std::vector<node_mode> node;//node 
typedef std::vector<node> nodes;

//variables for setupInput
	node_mode n0R1, n0R2, n1R1, n1R2, n2R1, n2R2, n3R1, n3R2;
	node n0, n1, n2, n3; 
	nodes n;
    tuple_list n0R1l1, n0R2l1, n1R1l1, n1R2l1, n2R1l1, n2R2l1, n3R1l1, n3R2l1;

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



#endif 