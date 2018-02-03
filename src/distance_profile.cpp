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
    Atom a;
    if (!ParseAtomRecord(line, &a)) {
      continue;
    }
    protein_.push_back(a);
  }
}

