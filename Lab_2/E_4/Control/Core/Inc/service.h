/*
 * service.h
 *
 *  Created on: Oct 8, 2022
 *      Author: Nguyen Tran
 */

#ifndef INC_SERVICE_H_
#define INC_SERVICE_H_

class Service {
public:
	virtual void run(int& status) = 0;
};


#endif /* INC_SERVICE_H_ */
