/*
 * GenericFrame.h
 *
 *  Created on: Aug 9, 2016
 *      Author: Ronaldo
 */

#ifndef CLASSES_GENERICFRAME_H_
#define CLASSES_GENERICFRAME_H_

#include "Frame.h"
#include "boost/any.hpp"

namespace Model {

class GenericFrame: public Frame {
public:
	GenericFrame(const GenericFrame* isA);
	virtual ~GenericFrame();

private:
	const GenericFrame* isA;
	std::map<std::string, boost::any> procedures;
};

} /* namespace Model */

#endif /* CLASSES_GENERICFRAME_H_ */
