#include "Visitor.hh"

Visitor::Visitor() {}

void Visitor::begin(LibertyGroup *group) {
    std::cout << "BEGIN GROUP: " << group->type();

    // The "name" of a group is stored in params()
    if (group->params() && !group->params()->empty()) {
        std::cout << " (";
        bool first = true;
        for (auto p : *group->params()) {
            if (!first) std::cout << ", ";
            if (p->isFloat())
                std::cout << p->floatValue();
            else
                std::cout << p->stringValue();
            first = false;
        }
        std::cout << ")";
    }
    std::cout << std::endl;
}

void Visitor::end(LibertyGroup *group) {
    std::cout << "END GROUP: " << group->type() << std::endl;
}

void Visitor::visitAttr(LibertyAttr *attr) {
    std::cout << "ATTR: " << attr->name() << " = ";

    if (attr->isComplex()) {
        std::cout << "(";
        bool first = true;
        for (auto v : *attr->values()) {
            if (!first) std::cout << ", ";
            if (v->isFloat()) std::cout << v->floatValue();
            else std::cout << v->stringValue();
            first = false;
        }
        std::cout << ")";
    } else {
        auto v = attr->firstValue();
        if (v->isFloat()) std::cout << v->floatValue();
        else std::cout << v->stringValue();
    }

    std::cout << std::endl;
}

void Visitor::visitVariable(LibertyVariable *variable) {
    std::cout << "VARIABLE: " << variable->variable()
              << " = " << variable->value() << std::endl;
}

void Visitor::visitDefine(LibertyDefine *define) {
    std::cout << "DEFINE: " << define->name()
              << " type=" << (int)define->valueType()
              << std::endl;
}

bool Visitor::save(LibertyGroup*) { return true; }
bool Visitor::save(LibertyAttr*) { return true; }
bool Visitor::save(LibertyVariable*) { return true; }
