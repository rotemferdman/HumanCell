#include "Mitochondrion.h"
#include "Protein.h"
#include <iostream>
#include <string>

void Mitochondrion::init()
{
	/*
	init the class
	*/
	_glocuse_level = 0;
	_has_glocuse_receptor = false;
}

void Mitochondrion::insert_glucose_receptor(const Protein& protein)
{
	/*
	checking if its the right list
	*/
	AminoAcidNode* u = protein.get_first();
	AminoAcid* a = new AminoAcid[7];
	a[0] = ALANINE;
	a[1] = LEUCINE;
	a[2] = GLYCINE;
	a[3] = HISTIDINE;
	a[4] = LEUCINE;
	a[5] = PHENYLALANINE;
	a[6] = AMINO_CHAIN_END;
	int i = 0;
	bool failed = false;

	while (u != nullptr)
	{
		if (u->get_data() == a[i])
		{
			//pass
		}
		else
		{
			failed = true;
		}
		i++;
		u = u->get_next();
	}

	if (failed == true)
	{
		_has_glocuse_receptor = false;
	}
	else
	{
		set_glucose(50); //i didnt know where the glucose level is being set(and i searched), so i setted him if receptor is true.
		_has_glocuse_receptor = true;
	}
	

	
}

void Mitochondrion::set_glucose(const unsigned int glocuse_units)
{
	/*
	setting the glocus level
	*/
	_glocuse_level = glocuse_units;
}

bool Mitochondrion::produceATP() const
{
	/*
	checking if it can produce atp.
	*/

	if (_has_glocuse_receptor == true && _glocuse_level >= 50)
	{
		return true;
	}
	else
	{
		return false;
	}
}
