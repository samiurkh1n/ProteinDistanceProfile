// Unit tests for the Protein library
// Test data and PDB files are located in the test-data directory

#include <cassert>
#include <string.h>

#include "distance_profile.h"

void test_protein_filename_constructor();
void test_distance_profile_constructor();
void test_distance_profile_printing();

int main() {
  test_protein_filename_constructor();
  test_distance_profile_constructor();
  test_distance_profile_printing();
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
  d.num_distances = 3;
  DistanceProfile pdp(ps, d);
  assert(pdp.NumProteins() == 1);
}

void test_distance_profile_printing() {
  Protein p("./test-data/1tpo.pdb");
  std::vector<Protein> proteins;
  proteins.push_back(p);
  DistanceProfileSettings d;
  d.distances.push_back(6);
  d.distances.push_back(12);
  d.distances.push_back(24);
  d.num_distances = 3;
  DistanceProfile pdp(proteins, d);
  pdp.PrintDistanceProfile("./test-data/");
}
