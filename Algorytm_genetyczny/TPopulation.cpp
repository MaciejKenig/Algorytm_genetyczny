#include <iostream>
#include <algorithm>

#include "TPopulation.h"

using namespace std;

TPopulation::TPopulation(unsigned int cands_count)
{
	candidated_count = cands_count;

	for (int i = 0; i < cands_count; i++) candidates.push_back({});

}

void TPopulation::calculate()
{
	double best_val = 0.0;

	for (int i = 0; i < candidated_count; i++)
	{
		candidates[i].rate();
		double val = candidates[i].get_mark();

		if (i == 0) best_val = val;
		else			best_val = max(best_val, val);
	}

	this->best_val = best_val;
}

TCandidate TPopulation::get_best_candidate()
{
	int i = 0;

	while (candidates[i].get_mark() != best_val) i++;
	
	return candidates[i];
}

void TPopulation::info()
{
	cout << "\n\n";
	cout << "====== POPULATION #" << 0 << " ======\n";

	for (int i = 0; i < candidated_count; i++)
	{
		cout << "candidate #" << i << ": " << candidates[i].get_mark() << "\n";
	}

	cout << "==============================\n\n";
}