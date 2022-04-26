//Daniel Kryzhanovsky and Gabe Howland
#include "deme.hh"

class TournamentDeme: public Deme{
public:
	TournamentDeme(const Cities* cities_ptr, unsigned pop_size, double mut_rate)
		:Deme(cities_ptr, pop_size, mut_rate){}
	std::vector<Chromosome*> cur_bracket();

protected:
	 virtual Chromosome* select_parent();
}