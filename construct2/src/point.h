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



#endif /* SRC_POINT_H_ */
