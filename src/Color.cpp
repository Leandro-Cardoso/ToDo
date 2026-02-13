#include <iomanip>

#include "Color.hpp"

Color::Color(const std::string& name, const std::string& hexCode) : name(name), hexCode(hexCode) {
    if (isValidHex(hexCode)) {
        this->hexCode = hexCode;
    } else {
        std::cerr << "Erro: Codigo hexadecimal " << hexCode << " invalido.\n";
    }
}

bool Color::isValidHex(const std::string& hexCode) const {
    if (hex.size() != 7 || hex[0] != '#') return false;
    for (int i = 1; i < 7; i++) {
        if (!isxdigit(hex[i])) return false; // Verifica se é 0-9 ou A-F.
    }
    return true;
}
