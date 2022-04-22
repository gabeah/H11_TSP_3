// Daniel K and Gabe H
// Climb Chromosome

#include "climb_chromosome.hh"

Chromosome* best_fit(Chromosome* og, Chromosome* m1, Chromosome* m2){
	double og_fit = og->get_fitness();
	double m1_fit = m1->get_fitness();
	double m2_fit = m2->get_fitness();

	if (og_fit >= m1_fit && og_fit >= m2_fit) return og;
	else if (m1_fit >= og_fit && m1_fit >= m2_fit) return m1;
	else if (m2_fit >= og_fit && m2_fit >= m1_fit) return m2;
	else assert(false);
}

void mutate() {
	doublr curr_fitness = this->get_fitness();
	int rand_pt = random_gen(0,order_.size()-1);

	Chromosome* mutate1 = this->clone();
	Chromosome* mutate2 = this->clone()

	if(rand_pt==0){
		std::swap(mutate1->order_.begin(), mutate1->order_.end());	
	}
	else{
		std::swap(mutate1->order_[rand_pt], mutate1->order_[rand_pt-1]);
	}
	
	if(rand_pt == order_.size()-1) {
		std::swap(mutate2->order_.end(), mutate2->order_.begin());
	}
	else{
		std::swap(mutate2->order_[rand_pt], mutate2->order[rand_pt+1]);
	}

	Chromosome* best_chrom = best_fit(this, mutate1, mutate2);
}
