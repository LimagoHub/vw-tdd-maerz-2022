#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../Tag1_04PersonenServiceProjekt/PersonenRepository.h"




class Mockpersonen_repository : public PersonenRepository {
 public:
  MOCK_METHOD(void, saveOrUpdate, (person person), (override));
  
  MOCK_METHOD(bool, remove, (person person), (override));
  MOCK_METHOD(bool, remove, (std::string id), (override));
  MOCK_METHOD(person, find_by_id, (std::string id), (override));
  MOCK_METHOD(std::vector<person>, find_all, (), (override));
};
