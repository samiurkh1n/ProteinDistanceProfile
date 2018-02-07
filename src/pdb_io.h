// PDB IO facilities
// Methods and member variables to process PDB records

#ifndef PDB_IO_H
#define PDB_IO_H

#include "cartesian.h"

#include <string>

typedef Coordinate AlphaCarbon;

// Reads in a record and creates an alpha carbon coordinate
// Returns true if the record is a valid alpha carbon and
// false if the record is empty or if it's not an ATOM record
bool ParseCarbonAtomRecord(std::string pdb_record_line, AlphaCarbon* c);

#endif  // PDB_IO_H
