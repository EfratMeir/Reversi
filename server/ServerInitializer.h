/*
 * ServerInitializer.h
 *
 *  Created on: Jan 1, 2018
 *      Author: efrat
 */

#ifndef SERVERINITIALIZER_H_
#define SERVERINITIALIZER_H_

#include "Server.h"
class ServerInitializer {
public:
	ServerInitializer();
	void initialize(int port_num);
	virtual ~ServerInitializer();
private:
	static void* goToStart(void *);

};

#endif /* SERVERINITIALIZER_H_ */
