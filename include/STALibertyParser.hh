#ifndef STA_LIBERTY_PARSER_H
#define STA_LIBERTY_PARSER_H

#include <string>
#include <optional>
#include <iostream>

#include "Sta.hh"
#include "Visitor.hh" 

using namespace sta;

class STALibertyParser : public Report {
public:
    Visitor *visitor_;
    std::string filename_;
    std::optional<std::string> err_;

    STALibertyParser(const std::string &filename);
    ~STALibertyParser();

    int check() const;
    std::string get_error_text() const;

    // Report interface override
    size_t printConsole(const char *buffer, size_t length) override;
};

#endif // STA_LIBERTY_PARSER_H
