// Implementation of functions associated with the protein object

#include "distance_profile.h"

#include <fstream>
#include <iostream>

Protein::Protein(std::string file_name) {
  std::ifstream pdb_file;
  pdb_file.open(file_name.c_str());
  if (!pdb_file.is_open()) {
    std::cerr << "Error in opening file " << file_name << std::endl;
    return;
  }

  size_t last_backslash = file_name.find_last_of('/');
  std::string protein_name = file_name.substr(last_backslash + 1);
  name_ = protein_name.substr(0, protein_name.size() - 4);
  
  std::string line;
  while (std::getline(pdb_file, line)) {
    AlphaCarbon a;
    if (!ParseCarbonAtomRecord(line, &a)) {
      continue;
    }
    protein_.push_back(a);
  }
}

DistanceProfile::
DistanceProfile(const std::vector<Protein>& proteins,
		const DistanceProfileSettings& opts) {

  residue_table_.resize(proteins.size());
  
  std::vector<size_t> residue_distances = opts.distances;
  residue_distances_ = residue_distances;
  
  size_t distance = 0;
  for (size_t protein_i = 0; protein_i < proteins.size(); ++protein_i) {
    // TODO(samiurkh1n): Don't copy an entire protein.
    Protein protein = proteins[protein_i];
    for (size_t i = 0; i < protein.ResidueCount(); ++i) {
      for (size_t distance_i = 0; distance_i < residue_distances.size();
	   ++distance_i) {
	distance = residue_distances[distance_i];
      
	if (i % distance == 0) {
	  AdjacentResidue r;
	  r.residue_a_id = i;
	  r.residue_b_id = i + distance;
	  r.distance = CartesianDistance
	    (protein.GetResidue(i), protein.GetResidue(i + distance));
	  residue_table_[protein_i].push_back(r);
	}
      }
    }
  }
}
