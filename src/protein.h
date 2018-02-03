// Protein.h
// Contains data structure and methods to represent proteins and construct
// the distance profile.

#ifndef PROTEIN_H
#define PROTEIN_H

#include "distance_profile.h"
#include "pdb_io.h"

#include <string>
#include <vector>

class Protein {
public:
    Protein();

    // Construct a protein from a PDB file
    // Expects a path to a PDB file
    Protein(std::string file_name);

private:
    std::vector<Atom> proteins_;
};

#endif  // PROTEIN_H
