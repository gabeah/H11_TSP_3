//Daniel Kryzhanovsky and Gabe Howland

COMPILE:
Make file included, run make command

We ran program with population size 100 and mutation rate 0.5

TO RUN PROGRAM:
use following command
$ ./tsp challenge.tsv 100 0.5

it will output to a file called "output_tournament.tsv"

METHOD:

///////////////////////////////////////////////////////////////////////////////
Climb Chromosome: For climb chromosome, we started off by initializing the constructor and deconstructor of the inhertied class, while also implementing the original's mutate and clone class, since that's all we are changing for this class. We also created the best_fit and rearange class, helper functions that allow us to find the best fit among three chromosmes and rearange the order of the chromosome's indexs respectifully. To implement these functions, we had rearange swap the beginning and end of the specific chromsome to calculate its total fitness. Best_fit just compares the 3 individual chromosomes to see which one has a higher fitness. To clone the chromosme, we had it so it clones the chromosome from the climb chromosome class. In order to even check the best fitness in mutate, we find the index of the original, second(front), and third(back) chromosome to go through all of their indexs and find their fitnesses. At the end of Climb, all we do is compare the 3 chromosomes and choose the one with the highest fitness.

///////////////////////////////////////////////////////////////////////////////
Tournament Deme: To allow the chromosomes to go at each other in bracket style, we started off with the normal routine of creating a constructor and deconstructor. We then inherit the select_parent from the original deme. To implement select_parent(), we implemented a helper function that compares the two current iterators in the "contestent chromosomes" and checkes which one is the largest, eventually returning the "winner" of all the brackets. Within select_parent(), we use std::sample to generate the full tourney and then go through a for loop that essentially simulates the entire tournament. In the end, it's able to return the best tournament by having the chromosme of [0], the winner, come out on top.