#pragma once
#include <vector>

#include "Person.h"
class PersonenRepository
{

public:
	virtual void saveOrUpdate(person p)=0; // Potenziell Exception
	virtual bool remove(person p)=0;
	virtual bool remove(std::string id)=0;
	virtual person find_by_id(std::string id)=0; // null wenn keine person gefunden wird
	virtual std::vector<person> find_all()=0;
};

