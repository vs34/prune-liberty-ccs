#include <iostream>
#include "Sta.hh"
#include "STALibertyParser.hh"

using namespace sta;

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: prunecss <file.lib>\n";
        return 1;
    }

    const char *filename = argv[1];

    // Initialize OpenSTA environment
    sta::initSta();
    Sta *sta = new Sta();
    Sta::setSta(sta);
    sta->makeComponents();

    // Run the parser
    STALibertyParser parser(filename);

    if (parser.check()) {
        std::cerr << "ERROR: " << parser.get_error_text() << std::endl;
        return 1;
    }

    return 0;
}
