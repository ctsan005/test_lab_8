#include "visitor.h"
#include <iostream>
// #include "vit.h"

// Visitor::Visitor(){}

PrintVisitor::PrintVisitor(){};
void PrintVisitor::rootNode(){ //For visiting a root node (do nothing)
	// std::cout << output << std::endl;		
}
void PrintVisitor::sqrNode(){ //For visiting a square node

	output += " ^2 ";
	// std::cout << output << std::endl;
} 
void PrintVisitor::multNode(){ //For visiting a multiple node
	output += " * ";
	// std::cout << output << std::endl;
}
void PrintVisitor::subNode(){ //For visiting a subtraction node
	output += " - ";
	// std::cout << output << std::endl;
}
void PrintVisitor::addNode(){ //For visiting an add node
	output += " + ";
	// std::cout << output << std::endl;
}
void PrintVisitor::opNode(Op* op){ //For visiting a leaf node
	output += " ";
	// std::cout << output << std::endl;
	double temp = op->evaluate();
	stringstream ss;
	ss << temp;
	string str = ss.str();
	output += str;
	output += "  ";
	// std::cout << output << std::endl;
}

void PrintVisitor::execute(){ //Prints all visited nodes
	std::cout << output << std::endl;
}