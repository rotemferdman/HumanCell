#pragma once
#include <iostream>
#include <string>
#include "Protein.h"


class Mitochondrion
{
private:
	unsigned int _glocuse_level;
	bool _has_glocuse_receptor;

public:
	void init();
	void insert_glucose_receptor(const Protein& protein);
	void set_glucose(const unsigned int glocuse_units);
	bool produceATP() const;

};
