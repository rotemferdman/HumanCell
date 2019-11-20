#pragma once
#include <string>
#include <iostream>
#include <stdio.h>

class Gene
{
private:
	unsigned int _start;
	unsigned int _end;
	bool _on_complementary_dna_strand;

public:
	void init(const unsigned int start, const unsigned int end, const bool on_complementary_dna_strand);

	//getters:
	unsigned int get_start() const;
	unsigned int get_end() const;
	bool is_on_complementary_dna_strand() const;

	//setters:

	void set_start(const unsigned int start);
	void set_end(const unsigned int end);
	void set_on_complementary_dna_strand(const bool on_complementary_dna_strand);
};


class Nucleus
{

private:
	std::string _DNA_strand;
	std::string _complementary_DNA_strand;


public:
	void init(const std::string dna_sequence);
	std::string get_RNA_transcript(const Gene& gene) const;
	std::string get_reversed_DNA_strand() const;
	unsigned int get_num_of_codon_appearances(const std::string& codon) const;
}; 
