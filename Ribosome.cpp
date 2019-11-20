#include "Ribosome.h"
#include <string>
#include <stdio.h>
#include <iostream>

Protein* Ribosome::create_protein(std::string& RNA_transcript) const
{
	std::string letters = "";
	Protein* b = new Protein;
	b->init();
	AminoAcid f;
	int i = 0;
	int new_beg = 0;

	while (RNA_transcript.size() - new_beg >= 3)
	{
		letters = RNA_transcript.substr(new_beg, 3);
		new_beg = new_beg + 3;

		
		f = get_amino_acid(letters);

		if (f == UNKNOWN)
		{
			b->clear();
			return nullptr;
		}
		else
		{
			b->add(f);
		}
	}
	return b;

}

