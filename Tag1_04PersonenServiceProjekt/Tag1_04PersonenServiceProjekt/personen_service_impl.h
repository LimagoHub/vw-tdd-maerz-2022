#pragma once

#include "PersonenRepository.h"
#include "Person.h"
class personen_service_impl
{
private:
	PersonenRepository& repo;


public:
	personen_service_impl(PersonenRepository& repo)
		: repo(repo)
	{
	}

	// Vorname min 2 Zeichen -> pse
	// nachname min 2 Zeichen -> pse
	// Vorname Attila -> pse
	// Irgendeine Exception im darunter liegenden -> pse
	// Happy Day -> call SaveOrUpdate
	void speichern(person p)
	{
		
	}
};

