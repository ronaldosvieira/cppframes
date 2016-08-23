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
#include "boost/variant.hpp"

namespace Model {

class Frame {
typedef boost::variant<int, float, std::string, Frame*> PropertyValue;

public:
	Frame();
	virtual ~Frame();

	virtual PropertyValue getPropertyValue(std::string property) = 0;

private:
	std::map<
		std::string,
		boost::variant<int, float, std::string, Frame*>
	> properties;
};

} /* namespace Model */

#endif /* CLASSES_FRAME_H_ */
