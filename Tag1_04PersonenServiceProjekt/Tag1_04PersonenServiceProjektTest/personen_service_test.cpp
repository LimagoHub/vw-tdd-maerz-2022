#include "personen_service_test.h"
#include <exception>
person validPerson{ "John","Doe" };

using namespace testing;
TEST_F(personen_service_test, speichern_vornameZuKurz_throwsPersonenServiceException_andErrorMessage_VornameZuKurz)
{
	try
	{
		// Arrange
		person p{ "J", "Doe" };
		// Act
		object_under_test.speichern(p);
		
		FAIL() << "expected exception is not thrown";
	}
	catch (personen_service_execption& ex)
	{
		EXPECT_STREQ("Vorname zu kurz.", ex.what());
	}
}

TEST_F(personen_service_test, speichern_nachnameZuKurz_throwsPersonenServiceException_andErrorMessage_nachNameZuKurz)
{
	try
	{
		// Arrange
		person p{ "John", "D" };
		// Act
		object_under_test.speichern(p);

		FAIL() << "expected exception is not thrown";
	}
	catch (personen_service_execption& ex)
	{
		EXPECT_STREQ("Nachname zu kurz.", ex.what());
	}
}



TEST_F(personen_service_test, speichern_unexpectedExceptionInUnderlyingService_throwsPersonenServiceException)
{
	try
	{
		// Arrange
		std::invalid_argument e("Upps");

		ON_CALL(blacklistMock, is_allowed(_)).WillByDefault(Return(true));
		ON_CALL(repoMock, saveOrUpdate(_)).WillByDefault(Throw(e));
		// Act
		object_under_test.speichern(validPerson);

		FAIL() << "expected exception is not thrown";
	}
	catch (personen_service_execption& ex)
	{
		EXPECT_STREQ("Fehler im Service", ex.what());
	}
}


TEST_F(personen_service_test, speichern_antipath_throwsPersonenServiceException_andErrorMessage_Antipath)
{

	try
	{
		// Arrange

		ON_CALL(blacklistMock, is_allowed(_)).WillByDefault(Return(false));
		
		person p{ "John", "Doe" };
		// Act
		object_under_test.speichern(p);

		FAIL() << "expected exception is not thrown";
	}
	catch (personen_service_execption& ex)
	{
		EXPECT_STREQ("Antipath", ex.what());
	}
	
}


TEST_F(personen_service_test, speichern_happyDay_personIsPassedToRepo)
{
	InSequence s;
	
	
	EXPECT_CALL(blacklistMock, is_allowed(_)).WillOnce(Return(true));
	EXPECT_CALL(repoMock, saveOrUpdate(_)).Times(1);
	
	// Act
	object_under_test.speichern(validPerson);

	

}

TEST_F(personen_service_test, speichern_xyz_personIsPassedToRepo)
{
	person result;
	EXPECT_CALL(blacklistMock, is_allowed(_)).WillOnce(Return(true));
	EXPECT_CALL(repoMock, saveOrUpdate(_)).Times(1).WillOnce(DoAll(SaveArg<0>(&result)));
	// Act
	object_under_test.speichern("Peter","Schmidt");

	

	EXPECT_EQ("1", result.get_id());
	EXPECT_EQ("Peter", result.get_vorname());

}

//TEST_F(personen_service_test, dummy)
//{
//
//	person result;
//
//	person p1{"Max","Mustermann"};
//	person p2{ "Jane","Doe" };
//
//	EXPECT_CALL(repoMock, save(p1)).Times(3).WillRepeatedly()
//
//	//EXPECT_CALL(repoMock, save(_)).Times(1).WillOnce(DoAll(Return(3), SaveArg<0>(&result)));
//
//	//ON_CALL(repoMock, save(_)).WillByDefault(Return(3));
//
//	
//	// Act
//	/*object_under_test.speichern("Peter", "Schmidt");
//
//
//
//	EXPECT_EQ("1", result.get_id());
//	EXPECT_EQ("Peter", result.get_vorname());*/
//
//}