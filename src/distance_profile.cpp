// Implementation of functions associated with the protein object

#include "distance_profile.h"

#include <fstream>
#include <iostream>
#include <string>

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
  for (size_t i = 0; i < residue_table_.size(); ++i) {
    residue_table_[i].resize(opts.num_distances);
  }
  
  for (size_t i = 0; i < opts.num_distances; ++i) {
    residue_distances_.push_back(opts.distances[i]);
  }
  
  for (size_t protein_i = 0; protein_i < proteins.size(); ++protein_i) {
    Protein protein = proteins[protein_i];
    for (size_t i = 0; i < protein.ResidueCount(); ++i) {
      for (size_t distance_i = 0; distance_i < residue_distances_.size();
	   ++distance_i) {
	size_t distance = residue_distances_[distance_i];
	if (i % distance == 0) {
	  AdjacentResidue r;
	  r.residue_a_id = i;
	  r.residue_b_id = i + distance;
	  r.distance =
	    CartesianDistance(protein.GetResidue(i),
			      protein.GetResidue(i + distance));
	  residue_table_[protein_i][distance_i].push_back(r);
	}
      }
    }
  }
}

void DistanceProfile::PrintDistanceProfile(std::string output_dir) {
  for (size_t i = 0; i < NumProteins(); ++i) {
    std::string output_path = output_dir;
    output_path.append("pdp");
    output_path.push_back(i);
    std::ofstream pdp_out;
    pdp_out.open(output_path.c_str());
    if (!pdp_out.is_open()) {
      std::cerr << "Error printing protein distance profile to file\n";
      return;
    }

    for (size_t distance_i = 0; distance_i < residue_distances_.size();
	 ++distance_i) {
      for (size_t residue_i = 0;
	   residue_i < residue_table_[i][distance_i].size(); ++residue_i) {
	pdp_out << residue_distances_[distance_i] << " "
		<< residue_table_[i][distance_i][residue_i].distance << "\n";
      }
    } 
    pdp_out.close();
  }
}
