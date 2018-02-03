// Unit tests for pdb io utilities

#include "pdb_io.h"

#include <cassert>

void test_atom_record_parser_processes_atom_record();  // uses 1tpo as a sample
void test_atom_record_parser_returns_error_on_empty();
void test_atom_record_parser_returns_error_on_non_atom();
void test_atom_record_parser_letter_in_residue_num();

int main() {
    test_atom_record_parser_processes_atom_record();
    test_atom_record_parser_returns_error_on_empty();
    test_atom_record_parser_returns_error_on_non_atom();
    test_atom_record_parser_letter_in_residue_num();
    return 0;
}

void test_atom_record_parser_processes_atom_record() {
    Atom a;
    std::string valid_atom_record = 
    "ATOM      1  N   ILE A  16      -8.124   9.603  20.387  1.00 14.54           N  ";
    assert(ParseAtomRecord(valid_atom_record, &a));
    assert(a.atom_number == 1);
    assert(a.residue_name == "ILE");
    assert(a.sequence_identifier == "A");
    assert(a.residue_id == "16");
    assert(a.coordinate.x == -8.124);
    assert(a.coordinate.y == 9.603);
    assert(a.coordinate.z == 20.387);
}

void test_atom_record_parser_returns_error_on_empty() {
    Atom a;
    std::string empty_record = "";
    assert(!ParseAtomRecord(empty_record, &a));
}

void test_atom_record_parser_returns_error_on_non_atom() {
    Atom a;
    std::string non_atom_record = 
    "ORIGX3      0.000000  0.000000  1.000000        0.00000                         ";
    assert(!ParseAtomRecord(non_atom_record, &a));
}

void test_atom_record_parser_letter_in_residue_num() {
  Atom a;
  std::string letter_in_residue_record =
    "ATOM   1236  O   GLY A 188A    -11.190   8.531  11.424  1.00 20.42           O  ";
  assert(ParseAtomRecord(letter_in_residue_record, &a));
  assert(a.residue_name == "GLY");
  assert(a.residue_id == "188A");
}
