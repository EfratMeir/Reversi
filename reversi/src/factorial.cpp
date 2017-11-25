/*
 * factorial.cpp
 *
 *  Created on: Nov 25, 2017
 *      Author: keren
 */

int factorial(int n) {
	int result = 1;
	for(int i = 2; i<= n; i++) {
		result *=i;
	}
	return result;
}


