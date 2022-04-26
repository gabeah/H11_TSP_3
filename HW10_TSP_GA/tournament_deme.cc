#include "tournament_deme.hh"
#include <algorithm>

std::vector<Chromosome*> TournamentDeme::cur_bracket(std::vector<Chromosome*> cur_conts){
	for(size_t d; d < cur_conts.size()/2; ++ d){
		if(cur_conts[d] > cur_conts[d+1]){
			cur_conts.erase(cur_conts.begin()+d+1);
		}
		else{
			cur_conts.erase(cur_conts.begin()+d);
		}
	}
	return cur_conts;
}

Chromosome* TournamentDeme::select_parent(){
	std::vector<Chromosome*> tourney_conts (8,nullptr);
	
	std::sample(pop_.begin(), pop_.end(), tourney_conts.begin(), 8, generator_);

	for(size_t i = 0; i < 3; i++){
		tourney_conts = cur_bracket(tourney_conts);
	}

	return tourney_conts[0];
}
