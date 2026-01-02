#ifndef VISITOR_H
#define VISITOR_H

#include "LibertyParser.hh"
#include <iostream>

using namespace sta;

class Visitor : public LibertyGroupVisitor {
public:
    Visitor();
    float skip_this_;
    LibertyGroup *group_skip_;
    int size_index1;
    int size_index2;
    int tab_formating;

    // Custom method to skip groups that are not needed
    void skipGroup(LibertyGroup *group);
    
    // Override methods from LibertyGroupVisitor
    void begin(LibertyGroup *group) override;
    void end(LibertyGroup *group) override;
    void visitAttr(LibertyAttr *attr) override;
    void visitVariable(LibertyVariable *variable) override {}

    // Save methods required by the interface
    bool needsQuotes(const char* str);
    bool save(LibertyGroup*) override;
    bool save(LibertyAttr*) override;
    bool save(LibertyVariable*) override;
};

#endif // VISITOR_H
