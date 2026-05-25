#pragma once

#include "TCandidate.h"
#include <vector>

class TPopulation
{
	static unsigned int			pop_count;
	unsigned int				_id;
	unsigned int				candidated_count;
	std::vector<TCandidate>		candidates;
	double						best_val = 0;

public:
	unsigned int get_id() { return _id; }
	unsigned int get_candidates_count() { return candidated_count; }
	double get_best_val() { return best_val; }

				TPopulation(unsigned int cands_count = 10);
	void		calculate();
	TCandidate	get_best_candidate();

	void		info();	
};