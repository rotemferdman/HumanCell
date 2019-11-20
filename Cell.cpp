#include "Cell.h"
#include <string>

void Cell::init(const std::string dna_sequence, const Gene glucose_receptor_gene)
{
	_nucleus.init(dna_sequence);
	_glocus_receptor_gene = glucose_receptor_gene;
	_mitochondrion.init();
	
	
}

bool Cell::get_ATP()
{
	bool state;
	std::string n = _nucleus.get_RNA_transcript(_glocus_receptor_gene);
	Protein* v = nullptr;
	AminoAcidNode* c = nullptr;

	v = _ribosome.create_protein(n);
	if (v == nullptr)
	{
		std::cerr << "couldnt make a protein.";
		_exit(1);
	}
	else
	{
		
		 _mitochondrion.insert_glucose_receptor(*v);
		 state = _mitochondrion.produceATP();
		 if (state == false)
		 {
			 return false;
		 }
		 else
		 {
			 _atp_units = 100;
			 return true;
		 }
	}
	
}
