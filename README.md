# Metallic Forest

This repo has the code for the investigation related to metallic forest.

This investigation was motivated by the problems of the 2021 edition of the
International Physics Tournament.

Then this problem was used for the investigation of the class *Introduction
to theoretical investigation* where a first version of the simulation was
developed. 

## How is this repo structured?

I'm working on keeping this repo as organized as possible and if not, at
least that everything is documented and explained. Here I'll go through 
each of the directories.

### Simulation

The simulation directory contains all the code in C++ that runs the
simulation. The idea is to store here only the code. The folder
should be clean and the code well modularized and very clear.

### Data

This directory is meant to remain empty in the repo. 
The idea is that all the data that is taken from the 
simulations is organized in this folder, but it should 
NOT be uploaded to the repository. 

### Analysis

This directory contains files that are used to analyse the data from
the simulation. It contains python files or Jupyter Notebooks where
the data is processed and analized. 

The analysis will be done in well documented Jupyter notebooks with all
the thought processes and analysis in markdown cells. However, some scripts
may be written in individual modules to be imported.

### Docs

In this directory the idea is to document important data and document what
is being done. The idea is to have markdown files that explain everything
on the code and every change we make should be logged there explaining
what changed and why. I started this late so the first doc will explain
the current state of the project and then everything should be there.

There we should have a clear explanation of every parameter and wnat needs
to be done in order to make any simulation we want. If we write scripts
for compiling and running simulations, they should be documented.

Additionally, it would be good to document whenever we run a given
simulation, with the parameters used and registering the time it took
running. The idea is that every step of the simulation is throughly tested,
documented and registered. A file should explain what was simulated, 
how long did it take, and where are the results 
(Probably a notebook in the analysis directory)
