#pragma once

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../Tag1_04PersonenServiceProjekt/personen_service_impl.h"
#include "../Tag1_04PersonenServiceProjekt/personen_service_execption.h"
#include "Mockpersonen_repository.h"
#include "Mockblacklist_service.h"


class personen_service_test : public testing::Test
{
protected:
	Mockblacklist_service blacklistMock;
	Mockpersonen_repository repoMock;
	personen_service_impl object_under_test{ repoMock, blacklistMock};
};
