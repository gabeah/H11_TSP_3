// Daniel K and Gabe H
// Climb Chromosome

#include "climb_chromosome.hh"
#include <cassert>
#include <algorithm>

Chromosome* ClimbChromosome::clone() const
{
   return new ClimbChromosome(*this);
}


void ClimbChromosome::rearrange(size_t index, bool direction){
	if(direction){
	
		if(index==0){
			std::swap(order_[0], order_[order_.size()-1]);	
		}
		else{
			std::swap(order_[index], order_[index-1]);
		}

	}
	else{
	
		if(index == order_.size()-1) {
			std::swap(order_[0], order_[order_.size()-1]);
		}
		else{
			std::swap(order_[index], order_[index+1]);
		}

	}
}

void ClimbChromosome::best_fit(double og, double m1, double m2, size_t index){

	if (og >= m1 && og >= m2) {}
	else if (m1 >= og && m1 >= m2) {rearrange(index, true);}
	else if (m2 >= og && m2 >= m1) {rearrange(index,false);}
	else assert(false);
}

void ClimbChromosome::mutate() {
	double curr_fitness = this->get_fitness();
	int rand_pt = random_gen(0,order_.size()-1);

	//Backward swap
	rearrange(rand_pt, true);

	double back_fit = this->get_fitness();

	rearrange(rand_pt, true);

	//Forward swap
	rearrange(rand_pt, false);

	double front_fit = this->get_fitness();

	rearrange(rand_pt, false);

	best_fit(curr_fitness, back_fit, front_fit, rand_pt);
}


