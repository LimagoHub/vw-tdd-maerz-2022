#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../Tag1_04PersonenServiceProjekt/blacklist_service.h"




class Mockblacklist_service : public blacklist_service {
public:
	MOCK_METHOD(bool, is_allowed, (std::string), (override));

	
};
