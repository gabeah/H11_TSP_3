#include "tournament_deme.hh"
#include <algorithm>

std::vector<Chromosome*> TournamentDeme::cur_bracket(std::vector<Chromosome*> cur_conts){
	for(size_t d, d < cur_conts.size()/2, ++ d){
		if
	}
}

Chromosome* TournamentDeme::select_parent(){
	std::vector<Chromosome*> tourney_conts;
	std::select(pop_, tourney_conts, 8, generator_);
	
}