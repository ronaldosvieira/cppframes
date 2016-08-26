#include <cstdio>
#include <iostream>
#include <cstdlib>

#include <typeinfo>


class Property {
public:

	~Property() {
		operator delete(value);
	}

	template<typename T>
	const T* get() const { 
		if( typeid(T) == info ) {
			return static_cast<const T*>(value);
		}

		return nullptr;
	}

	template<typename T>
	void set(const T& value) {
		if( typeid(T) == this->info ) {

			T* v = static_cast<T*>(this->value);

			*v = value;
		} else {
			printf("Error: parameter type: %s member type: %s\n", typeid(T).name(), this->info.name());
		}
	}

	template<typename T>
	static Property* create(const T& value) {
		return new Property(static_cast<const void *>(&value), sizeof(T), typeid(T));
	}
	
protected:

	Property(const void* value, std::size_t size, const std::type_info& info) : value( operator new (size) ), info(info) { 
		this->value = const_cast<void *>(value);
	}

private:

	void * value;
	const std::type_info& info;
};

int main(int argc, char const *argv[]) {
	
	Property* a = Property::create(1);

	auto v = a->get<int>();

	if(v) {
		std::printf("%d\n", *v);
	} else {
		std::printf("error\n");
	}

	a->set(5);

	if(v) {
		std::printf("%d\n", *v);
	} else {
		std::printf("error\n");
	}

	return 0;
}
