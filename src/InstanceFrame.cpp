/*
 * InstanceFrame.cpp
 *
 *  Created on: Aug 9, 2016
 *      Author: Ronaldo
 */

#include "InstanceFrame.h"

namespace Model {

InstanceFrame::InstanceFrame(const GenericFrame* instanceOf) {
	// TODO Auto-generated constructor stub

}

InstanceFrame::~InstanceFrame() {
	// TODO Auto-generated destructor stub
}

Property* InstanceFrame::getPropertyValue(std::string property) {
	return this->properties[property];
}

} /* namespace Model */
