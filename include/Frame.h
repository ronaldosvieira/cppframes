/*
 * Frame.h
 *
 *  Created on: Aug 9, 2016
 *      Author: Ronaldo
 */


#ifndef CLASSES_FRAME_H_
#define CLASSES_FRAME_H_

#include <string>
#include <map>

#include "Property.h"

namespace Model {

class Frame {

public:
	Frame();
	virtual ~Frame();

	virtual Property* getPropertyValue(std::string property) = 0;

protected:
	std::map<std::string, Property*> properties;
};

} /* namespace Model */

#endif /* CLASSES_FRAME_H_ */
