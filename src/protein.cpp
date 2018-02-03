// Implementation of functions associated with the protein object

#include "protein.h"

#include <ifstream>

Protein::Protein(std::string file_name) {
    std::ifstream pdb_file(file_name);
    std::string line;
    while (getline(filename, line)) {
        Atom a;
        if (!ParseAtomRecord(line, &a)) {
            std::cerr << "Error reading protein\n";
            std::cerr << "Line:\n";
            std::cerr << "  " << line << "\n";
            return Protein();
        }
        proteins_.push_back(a);
    }
}

