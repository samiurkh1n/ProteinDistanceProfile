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

  std::string line;
  while (std::getline(file_name, line)) {
    Atom a;
    if (!ParseAtomRecord(line, &a)) {
      std::cerr << "Error reading protein\n";
      std::cerr << "Line:\n";
      std::cerr << "  " << line << std::endl;
      return;
    }
    protein_.push_back(a);
  }
}

