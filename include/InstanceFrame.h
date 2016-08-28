/*
 * InstanceFrame.h
 *
 *  Created on: Aug 9, 2016
 *      Author: Ronaldo
 */

#ifndef CLASSES_INSTANCEFRAME_H_
#define CLASSES_INSTANCEFRAME_H_

#include "Frame.h"
#include "GenericFrame.h"

namespace Model {

class InstanceFrame: public Frame {
public:
	InstanceFrame(const GenericFrame* instanceOf);
	virtual ~InstanceFrame();

private:
	const GenericFrame* instanceOf;
};

} /* namespace Model */

#endif /* CLASSES_INSTANCEFRAME_H_ */
