// Unit tests for the Protein library
// Test data and PDB files are located in the test-data directory

#include <cassert>

#include "distance_profile.h"

void test_protein_filename_constructor();
void test_distance_profile_constructor();
void test_distance_profile_accessor();

int main() {
    test_protein_filename_constructor();
    test_distance_profile_constructor();
    test_distance_profile_accessor();
    return 0;
}

void test_protein_filename_constructor() {
  Protein p("./test-data/1tpo.pdb");
  assert(p.Name() == "1tpo");
  assert(p.ResidueCount() == 223);
}

void test_distance_profile_constructor() {
  Protein p("./test-data/1tpo.pdb");
  std::vector<Protein> ps;
  ps.push_back(p);
  DistanceProfileSettings d;
  d.distances.push_back(6);
  d.distances.push_back(12);
  d.distances.push_back(24);
  DistanceProfile pdp(ps, d);
}
