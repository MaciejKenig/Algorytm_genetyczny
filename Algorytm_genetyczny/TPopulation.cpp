#include <iostream>
#include <algorithm>

#include "TPopulation.h"

using namespace std;

unsigned int TPopulation::pop_count = 0;

TPopulation::TPopulation() : TPopulation(10) {}

const TCandidate* TPopulation::get_candidate_wsk(int _id) const
{
	const TCandidate* wsk = &candidates[_id];
	return wsk;
}

TPopulation::TPopulation(const TPopulation& original)
{
	TPopulation::pop_count += 1;
	_id = TPopulation::pop_count;

	candidated_count = original.get_candidates_count();
	best_val = original.get_best_val();

	for (unsigned int i = 0; i < candidated_count; i++)
	{
		const TCandidate* wsk_os_org = original.get_candidate_wsk(i);
		TCandidate copy{ *wsk_os_org };
		candidates.push_back(copy);
	}
}

void TPopulation::calculate()
{
	double best_val = 0.0;

	for (unsigned int i = 0; i < candidated_count; i++)
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
	cout << "====== POPULATION #" << _id << " ======\n";

	for (int i = 0; i < candidated_count; i++)
	{
		cout << "candidate #" << i << ": " << candidates[i].get_mark() << "\n";
	}

	cout << "==============================\n\n";
}

TPopulation::TPopulation(unsigned int cands_count)
{
	TPopulation::pop_count += 1;
	_id = TPopulation::pop_count;
	candidated_count = cands_count;

	// Tworzenie startowych osobników
	for (unsigned int i = 0; i < candidated_count; i++)
	{
		candidates.push_back(TCandidate{});
	}
}