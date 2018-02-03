// Implementation of PDB IO methods

#include "cartesian.h"
#include "pdb_io.h"

#include <algorithm>

// Refer to PDB documentation on the ATOM record to understand substring index
// decisions
bool ParseAtomRecord(std::string line, Atom* atom) {
  if (line.empty()) {
    return false;
  }

  if (line.substr(0, 4) != "ATOM") {
    return false;
  }

  atom->atom_number = atoi(line.substr(6, 5).c_str());
  atom->residue_name = line.substr(17, 3);  // 3 letter amino acid identifier
  atom->sequence_identifier = line.substr(21, 1);
  atom->residue_id = line.substr(22, 5);

  // Remove whitespace
  atom->residue_name.erase
    (std::remove_if(atom->residue_name.begin(), atom->residue_name.end(),
		    isspace), atom->residue_name.end());
  atom->residue_id.erase
    (std::remove_if(atom->residue_id.begin(), atom->residue_id.end(),
		    isspace), atom->residue_id.end());
  atom->sequence_identifier.erase
    (std::remove_if(atom->sequence_identifier.begin(),
		    atom->sequence_identifier.end(),
		    isspace), atom->sequence_identifier.end());

  
  Coordinate c;  // Orthogonal coordinates measured in Angstroms
  c.x = atof(line.substr(30, 8).c_str());
  c.y = atof(line.substr(38, 8).c_str());
  c.z = atof(line.substr(46, 8).c_str());
  atom->coordinate = c;
  return true;
}
