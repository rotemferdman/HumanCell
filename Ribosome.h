#pragma once
#include "Protein.h"

class Ribosome
{

public:
	Protein* create_protein(std::string& RNA_transcript) const;

};
