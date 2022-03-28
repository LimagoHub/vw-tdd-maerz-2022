#pragma once
#include "gtest/gtest.h"
#include  "../Tag1_01Stapel/Stapel.h"
#include  "../Tag1_01Stapel/StapelException.h"


class StapelTest :public testing::Test {

protected:
	Stapel object_under_test; // jeder Test hat eine neue frische Instanz
};
