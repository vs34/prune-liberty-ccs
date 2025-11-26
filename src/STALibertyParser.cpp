#include "STALibertyParser.hh"
#include "LibertyParser.hh" // Required for parseLibertyFile

STALibertyParser::STALibertyParser(const std::string &filename)
    : visitor_(new Visitor()),
      filename_(filename),
      err_(std::nullopt)
{
    try {
        // Parse the file using the visitor and 'this' as the Report handler
        parseLibertyFile(filename_.c_str(), visitor_, this);
    } catch (sta::Exception &e) {
        err_ = e.what();
    }
}

STALibertyParser::~STALibertyParser() {
    delete visitor_;
}

int STALibertyParser::check() const {
    return err_.has_value();
}

std::string STALibertyParser::get_error_text() const {
    return err_.value_or("unknown error");
}

size_t STALibertyParser::printConsole(const char *buffer, size_t length) {
    std::cerr << std::string_view(buffer, length);
    return length;
}
