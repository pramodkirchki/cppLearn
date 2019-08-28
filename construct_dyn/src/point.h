/*
 * point.h
 *
 *  Created on: Aug 24, 2019
 *      Author: pramod
 */

#ifndef SRC_POINT_H_
#define SRC_POINT_H_

class point{
	int* coOrdinates;

public:
	point(int, int);
	point();
	point& operator= (const point&);
	point(const point&);


	void getPoint(void);

};

// The inline keyword suggests the compiler to make this function inline.
// Note that the inline function definition should be in the same file as the declaration.
// if any of the above methods are defined with inline keyword in point.cpp, this means that there is a
// difference in declaration and definition. This results in linker error Undefined reference
// to the inlined function.
inline point::point(){
	coOrdinates = new int [2];
	for(int i = 0; i < 2; i++) coOrdinates[i] = 0;
}

#endif /* SRC_POINT_H_ */
