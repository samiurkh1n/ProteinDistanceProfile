// Unit tests for pdb io utilities

#include "pdb_io.h"

#include <cassert>

void test_atom_record_parser_processes_atom_record();
void test_atom_record_parser_ignore_nonca_atom_record();
void test_atom_record_parser_returns_error_on_empty();
void test_atom_record_parser_returns_error_on_non_atom();

int main() {
  test_atom_record_parser_processes_atom_record();
  test_atom_record_parser_returns_error_on_empty();
  test_atom_record_parser_returns_error_on_non_atom();
  test_atom_record_parser_ignore_nonca_atom_record();
  return 0;
}

void test_atom_record_parser_ignore_nonca_atom_record() {
  AlphaCarbon a;
  std::string non_ca_record = 
    "ATOM      1  N   ILE A  16      -8.124   9.603  20.387  1.00 14.54           N  ";
  assert(!ParseCarbonAtomRecord(non_ca_record, &a));
}

void test_atom_record_parser_returns_error_on_empty() {
  AlphaCarbon a;
  std::string empty_record = "";
  assert(!ParseCarbonAtomRecord(empty_record, &a));
}

void test_atom_record_parser_returns_error_on_non_atom() {
  AlphaCarbon a;
  std::string non_atom_record = 
    "ORIGX3      0.000000  0.000000  1.000000        0.00000                         ";
  assert(!ParseCarbonAtomRecord(non_atom_record, &a));
}

void test_atom_record_parser_processes_atom_record() {
  AlphaCarbon a;
  AlphaCarbon b;
  std::string ca_record = "ATOM      2  CA  ILE A  16      -8.108   8.694  19.218  1.00 14.54           C";
  assert(ParseCarbonAtomRecord(ca_record, &a));
  assert(a.x == -8.108);
  assert(a.y == 8.694);
  assert(a.z == 19.218);
  std::string ca_record_2 = "ATOM    144  CA  GLY A  38      -5.229  17.151  38.743  1.00 13.76           C";
  assert(ParseCarbonAtomRecord(ca_record_2, &b));
  assert(b.x == -5.229);
  assert(b.y == 17.151);
  assert(b.z == 38.743);
}
