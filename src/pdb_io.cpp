// Implementation of PDB IO methods

#include "cartesian.h"
#include "pdb_io.h"

#include <algorithm>

// Refer to PDB documentation on the ATOM record to understand substring index
// decisions
bool ParseCarbonAtomRecord(std::string line, AlphaCarbon* c) {
  if (line.empty() || line.substr(0, 4) != "ATOM" ||
      line.substr(13, 2) != "CA") {
    return false;
  }  
  c->x = atof(line.substr(30, 8).c_str());
  c->y = atof(line.substr(38, 8).c_str());
  c->z = atof(line.substr(46, 8).c_str());
  return true;
}
