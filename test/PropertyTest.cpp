#include "CatchInit.h"
#include "../include/Property.h"

TEST_CASE("Testing the Property class", "[property]") {
	SECTION ("int creation") {
		int integer = 100;

		Model::Property* prop = Model::Property::create(integer);

		REQUIRE(prop->getType() == typeid(int));

		REQUIRE_NOTHROW(prop->get<int>());

		auto value = prop->get<int>();
		REQUIRE(typeid(value) == typeid(int));
	}

	SECTION ("float creation") {
		float floatNum = 100.1f;

		Model::Property* prop = Model::Property::create(floatNum);

		REQUIRE(prop->getType() == typeid(float));

		REQUIRE_NOTHROW(prop->get<float>());

		auto value = prop->get<float>();
		REQUIRE(typeid(value) == typeid(float));
	}
}
