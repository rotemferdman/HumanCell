#include "Nucleus.h"

void Gene::init(const unsigned int start, const unsigned int end, const bool on_complementary_dna_strand)
{
	/*
	init the gene
	input: all the vars that you need in the class
	*/
	_start = start;
	_end = end;
	_on_complementary_dna_strand = on_complementary_dna_strand;
}

unsigned int Gene::get_start() const
{
	/*
	getting the start index
	*/
	return _start;
}

unsigned int Gene::get_end() const
{
	/*
	getting the end index
	*/
	return _end;
}


bool Gene::is_on_complementary_dna_strand() const
{
	/*
	getting the state of whech string to use
	*/
	return _on_complementary_dna_strand;
}

void Gene::set_start(const unsigned int start)
{
	/*
	setting the start
	*/
	_start = start;
}

void Gene::set_end(const unsigned int end)
{
	/*
	setting the end
	*/
	_end = end;
}

void Gene::set_on_complementary_dna_strand(const bool on_complementary_dna_strand)
{
	/*
	setting the dna strand
	*/
	_on_complementary_dna_strand = on_complementary_dna_strand;
}


void Nucleus::init(const std::string dna_sequence)
{
	/*
	init the class
	input: the dna sting
	*/
	int x = 0;
	x = dna_sequence.size();
	int i = 0;
	std::string new_str = "";

	for (i = 0; i < x; i++) //check the string
	{
		if (dna_sequence[i] != 'G' && dna_sequence[i] != 'C' && dna_sequence[i] != 'T' && dna_sequence[i] != 'A')
		{
			std::cerr << "String isn't right" << std::endl;
			_exit(1);
		}
	}

	_DNA_strand = dna_sequence;
	new_str = dna_sequence;

	for (i = 0; i < x; i++)
	{
		if (new_str[i] == 'A')
		{
			new_str[i] = 'T';
		}

		else if (new_str[i] == 'T')
		{
			new_str[i] = 'A';
		}

		else if (new_str[i] == 'C')
		{
			new_str[i] = 'G';
		}

		else if (new_str[i] == 'G')
		{
			new_str[i] = 'C';
		}
	} //end of changes

	_complementary_DNA_strand = new_str;
}

std::string Nucleus::get_RNA_transcript(const Gene& gene) const
{
	/*
	getting the RNA
	input: the gene
	output: the RNA
	*/

	int j = 0;
	std::string RNA = "";
	std::string new_RNA = "";
	int i = 0;
	int max = 0;
	if (gene.is_on_complementary_dna_strand() == 0)
	{
		RNA = _DNA_strand;
	}
	else
	{
		RNA = _complementary_DNA_strand;
	}

	i = gene.get_start();
	max = gene.get_end();

	for (i = i; i < max; i++)
	{
		if (RNA[i] == 'T')
		{
			new_RNA += 'U';
		}
		else
		{
			new_RNA += RNA[i];
		}
		j++;
	}
	std::cout << new_RNA << std::endl;
	return new_RNA;
}

std::string Nucleus::get_reversed_DNA_strand() const
{
	/*
	reversed the DNA
	output: the string
	*/
	std::string input = _DNA_strand;
	std::string output = "";
	int size = input.size();
	int i = 0;
	int j = size;
	for (j = size - 1; j >= 0; j--)
	{
		output += input[j];
	}
	std::cout << output << std::endl;
	return output;
}


unsigned int Nucleus::get_num_of_codon_appearances(const std::string& codon) const
{
	/*
	getting the number of codon appearences ib the DNA string
	input: codon
	output: the num of codon appearences
	*/
	char a = codon[0];
	char b = codon[1];
	char c = codon[2];
	int i = 0;
	int size = _DNA_strand.size();
	int num = 0;

	for (i = 0; i < size; i++)
	{
		if (_DNA_strand[i] == a)
		{
			if (_DNA_strand[i + 1] == b)
			{
				if (_DNA_strand[i + 2] == c)
				{
					num++;
					i = i + 2;
				}
			}
		}
	}
	return num;
}

