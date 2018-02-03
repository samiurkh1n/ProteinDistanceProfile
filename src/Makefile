# Protein Distance Profile Experiment Makefile

CXXFLAGS = -static -ffast-math -lm
RLSFLAGS = $(CXXFLAGS) -O3  # release build flags
DBGFLAGS = $(CXXFLAGS) -g3  # debugging build flags

PROJECT = pdp

pdb_io_test: pdb_io.o
	g++ $(DBGFLAGS) pdb_io.o pdb_io_test.cpp -o pdb_io_test 

pdb_io.o: pdb_io.cpp
	g++ $(DBGFLAGS) -c pdb_io.cpp

cartesian.o: cartesian.cpp
	g++ $(DBGFLAGS) -c cartesian.cpp

distance_profile_test: distance_profile.o pdb_io.o cartesian.o
	g++ $(DBGFLAGS) distance_profile.o pdb_io.o cartesian.o \
		distance_profile_test.cpp -o distance_profile_test

distance_profile.o: distance_profile.cpp
	g++ $(DBGFLAGS) -c distance_profile.cpp

clean:
	rm -f *.o pdb_io_test distance_profile_test

.PHONY: clean
