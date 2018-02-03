// Distance Profile Library
// Contains data structure and methods to represent proteins and construct
// the distance profile.

#ifndef DISTANCE_PROFILE_H
#define DISTANCE_PROFILE_H

#include "pdb_io.h"

#include <string>
#include <vector>

// Protein class
// Gives utilities to construct a protein. Used by the distance profile object
class Protein {
 public:
  Protein();

  // Construct a protein from a PDB file
  // Expects a path to a PDB file. Returns a default Protein() if there
  //  is an error in reading the protein file.
  Protein(std::string file_name);

 private:
  std::vector<Atom> protein_;
};

// Distance Profile settings are used to control what type of distance profile
// is generated for each protein.
// You can manipulate this struct to experiment with the optimal parameter
// set for constructing the protein profile
struct DistanceProfileSettings {
  std::vector<size_t> distances;
  // TODO(samiurkh1n): Add more parameters
};

struct AdjacentResidue {
  int residue_a_id;
  int residue_b_id;
  double distance;
};

// Construct a distance profile for a set of proteins using the options
// specified in the options struct
std::vector<AdjacentResidue>
DistanceProfile(std::vector<Protein> proteins, DistanceProfileSettings& opts);

// Display histogram
void DisplayDistanceProfileHistogram();

#endif  // DISTANCE_PROFILE_H
