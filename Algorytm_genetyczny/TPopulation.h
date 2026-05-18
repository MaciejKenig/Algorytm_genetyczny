#pragma once

#include "TCandidate.h"
#include <vector>

class TPopulation
{
	unsigned int				candidated_count;
	std::vector<TCandidate>		candidates;
	double						best_val = 0;

public:
				TPopulation(unsigned int cands_count = 10);
	void		calculate();
	TCandidate	get_best_candidate();

	void		info();	
};