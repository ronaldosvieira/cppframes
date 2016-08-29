/*
 * Property.cpp
 *
 *  Created on: Aug 26, 2016
 *      Author: Ronaldo
 */

#include "Property.h"

namespace Model {

Property::Property(const void* value, std::size_t size, const std::type_info& info)
	: value(operator new (size)), info(info) {
	this->value = const_cast<void *>(value);
}

Property::~Property() {
	operator delete(value);
}

template<typename T>
Property* Property::create(const T& value) {
	return new Property(static_cast<const void *>(&value), sizeof(T), typeid(T));
}

template<typename T>
const T Property::get() const {
	if (typeid(T) == this->info) {
		auto temp = static_cast<const T*>(this->value);

		return *temp;
	} else {
		throw std::bad_cast();
	}
}

inline const std::type_info& Property::getType() const {
	return this->info;
}

template<typename T>
void Property::set(const T& value) {
	if (typeid(T) == this->info) {
		T* v = static_cast<T*>(this->value);
		*v = value;
	} else {
		printf("Error: parameter type: %s member type: %s\n",
				demangle(typeid(T).name()).c_str(),
				demangle(this->info.name()).c_str());
	}
}

std::string demangle(const char * mangled) {
	int status;

	char* c_demangled = abi::__cxa_demangle(mangled, nullptr, 0, &status);

	if (status == 0) {
		std::string demangled(c_demangled);
		free(c_demangled);

		return demangled;
	} else {
		throw std::runtime_error("Error demangling name");
	}
}

} /* namespace Model */
