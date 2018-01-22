// Implementation of PDB IO methods

#include "cartesian.h"
#include "pdb_io.h"

#include <fstream>

// Refer to https://www.wwpdb.org/documentation/file-format-content/format33/sect9.html#ATOM
// for more information about the ATOM record in the PDB file
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
    Coordinate c;  // Orthogonal coordinates measured in Angstroms
    c.x = atof(line.substr(30, 8).c_str());
    c.y = atof(line.substr(38, 8).c_str());
    c.z = atof(line.substr(46, 8).c_str());
    atom->coordinate = c;
    return true;
};
