#ifndef COLOR_H
#define COLOR_H

#include <string>
#include <stdexcept>

class Color {
private:
    std::string name;
    std::string hexCode;

    bool isValidHex(const std::string& code) const;

public:
    Color(const std::string& name, const std::string& hexCode);

    // Getters e Setters:
    std::string getName() const { return name; }
    std::string getHexCode() const { return hexCode; }
};

#endif
