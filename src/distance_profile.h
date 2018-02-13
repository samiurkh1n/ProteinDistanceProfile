// Distance Profile Library
// Contains data structure and methods to represent proteins and construct
// the distance profile.

#ifndef DISTANCE_PROFILE_H
#define DISTANCE_PROFILE_H

#include "pdb_io.h"

#include <string>
#include <vector>

// Protein Class
// Gives utilities to construct a protein. Used by the distance profile object
class Protein {
 public:
  Protein();

  // Construct a protein from a PDB file
  // Expects a path to a PDB file. Returns a default Protein() if there
  //  is an error in reading the protein file.
  Protein(std::string file_name);

  // Getters
  std::string Name() { return name_; }
  size_t ResidueCount() { return protein_.size(); }
  AlphaCarbon GetResidue(size_t i) { return protein_[i]; }
  
 private:
  std::string name_;

  // protein_ is composed of residues, each residue containing a set of atoms
  std::vector<AlphaCarbon> protein_;
};

// Distance Profile settings are used to control what type of distance profile
// is generated for each protein.
// You can manipulate this struct to experiment with the optimal parameter
// set for constructing the protein profile
struct DistanceProfileSettings {
  std::vector<size_t> distances;
  size_t num_distances;
};

// DistanceProfile Class
class DistanceProfile {
public:

  // Construct a distance profile for a set of proteins using the options
  // specified in the options struct
  DistanceProfile(const std::vector<Protein>& proteins,
		  const DistanceProfileSettings& opts);

  // Getters
  int NumProteins() { return residue_table_.size(); }
  
  // Prints histogram into a gnuplot servable format
  void PrintDistanceProfile(std::string output_dir);
private:
  
  struct AdjacentResidue {
    int residue_a_id;
    int residue_b_id;
    double distance;
  };

  // Each column is reserved for on protein. Within each column, there
  // is one column for each residue distance being recorded. Within each
  // residue distance column, there is a vector of adjacent residue distance
  std::vector<std::vector <std::vector<AdjacentResidue> > > residue_table_;
  std::vector<size_t> residue_distances_;
  std::vector<std::string> protein_names_;
};

#endif  // DISTANCE_PROFILE_H
