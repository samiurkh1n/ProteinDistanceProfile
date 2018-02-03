// Unit tests for the Protein library
// Test data and PDB files are located in the test-data directory

#include <cassert>

#include "distance_profile.h"

void test_protein_filename_constructor();

int main() {
    test_protein_filename_constructor();
    return 0;
}

// Method to test that a protein file was properly read.
void test_protein_filename_constructor() {
  Protein p("./test-data/1tpo.pdb");
  assert(p.Name() == "1tpo");
  assert(p.AtomCount() == 1629);
}
