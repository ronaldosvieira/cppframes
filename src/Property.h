/*
 * Property.h
 *
 *  Created on: Aug 26, 2016
 *      Author: Ronaldo
 */

#ifndef SRC_PROPERTY_H_
#define SRC_PROPERTY_H_

#include <cstdio>
#include <iostream>
#include <cstdlib>

#include <typeinfo>

namespace Model {

class Property {
public:
	~Property();

	template<typename T>
	const T* get() const;

	template<typename T>
	void set(const T& value);

	template<typename T>
	static Property* create(const T& value);

protected:
	Property(const void* value, std::size_t size, const std::type_info& info);

private:
	void * value;
	const std::type_info& info;
};

} /* namespace Model */

#endif /* SRC_PROPERTY_H_ */