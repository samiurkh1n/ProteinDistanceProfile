// PDB IO facilities
// Methods and member variables to process PDB records

#ifndef PDB_IO_H
#define PDB_IO_H

#include "cartesian.h"

#include <string>

// Atom struct
// Contains data about the atom of a protein including where it was physically
//   and what residue it was part of.
struct Atom {
  unsigned int atom_number;
  std::string residue_name;
  std::string sequence_identifier;
  std::string residue_id;
  Coordinate coordinate;
};

// Constructs an Atom object from an "ATOM" record in a pdb file
// Stores it in the atom argument
// Returns true if successful. Returns false on failure or error.
bool ParseAtomRecord(std::string pdb_record_line, Atom* atom);

#endif  // PDB_IO_H
