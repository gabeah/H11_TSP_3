// Daniel K and Gabe H
// Climb chromosome

#include "chromosome.hh"

class ClimbChromosome: public Chromosome {

public:
	ClimbChromosome(const Cities* cities_ptr)
		:Chromosome(cities_ptr){}

	~ClimbChromosome();

	virtual Chromosome* clone() const override;	

	virtual void mutate() override;

	void rearrange(size_t  index, bool direction);

	void best_fit(double og, double m1, double m2, size_t index);

};

