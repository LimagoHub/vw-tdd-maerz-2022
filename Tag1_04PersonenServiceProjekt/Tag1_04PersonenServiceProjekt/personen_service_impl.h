#pragma once

#include "PersonenRepository.h"
#include "blacklist_service.h"
#include "Person.h"
#include "personen_service_execption.h"
class personen_service_impl
{
private:
	PersonenRepository& repo;
	blacklist_service& blacklist;

	void validate_person(person p)
	{
		if (p.get_vorname().length() < 2)
			throw personen_service_execption("Vorname zu kurz.");
		if (p.get_nachname().length() < 2)
			throw personen_service_execption("Nachname zu kurz.");
	}

	void business_check(person p)
	{
		if (! blacklist.is_allowed(p.get_vorname()))
			throw personen_service_execption("Antipath");
	}

public:
	personen_service_impl(PersonenRepository& repo, blacklist_service& blacklist)
		: repo(repo),blacklist(blacklist)
	{
	}


	

	// Vorname min 2 Zeichen -> pse
	// nachname min 2 Zeichen -> pse
	// Vorname Attila -> pse
	// Irgendeine Exception im darunter liegenden -> pse
	// Happy Day -> call SaveOrUpdate
	void speichern(person p)
	{
		
		try {
			validate_person(p);
			business_check(p);
			p.set_id("1");
			repo.saveOrUpdate(p);

		}
		catch (personen_service_execption& ex)
		{
			// Log
			throw ex;
		}
		catch (std::exception& ex)
		{
			// Log
			throw personen_service_execption("Fehler im Service");
		}
	}

	void speichern(std::string vorname, std::string nachname)
	{
		person p{ vorname, nachname };
		speichern(p);
	}
};

