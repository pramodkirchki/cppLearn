/*
 * point.cpp
 *
 *  Created on: Aug 24, 2019
 *      Author: pramod
 */
#include <iostream>
#include "point.h"

 point::point(){
	coOrdinates = new int [2];
	for(int i = 0; i < 2; i++) coOrdinates[i] = 0;
}
 void point::getPoint(){
	std::cout << "x = " << coOrdinates[0] << ", y = " << coOrdinates[1] << std::endl;
}

 point& point::operator= (const point& p){
	std::cout << "Copy assignment called" << std::endl;
	coOrdinates = new int[2];
	for(int i = 0; i < 2;i++) coOrdinates[i] = p.coOrdinates[i];
	return *this;
}

 point::point(const point& p){
	std::cout << "Copy constructor called" << std::endl;
	coOrdinates = new int[2];
	for(int i = 0; i < 2;i++) coOrdinates[i] = p.coOrdinates[i];
}

 point::point(int a, int b){
	std::cout << "Normal constructor called" << std::endl;
	coOrdinates = new int [2];
	coOrdinates[0] = a;
	coOrdinates[1] = b;
}




