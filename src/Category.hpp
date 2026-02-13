#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>

#include "Color.hpp"

class Category {
private:
    std::string name;
    Color color;

public:
    Category(const std::string& name, const Color& color);

    void save() const;
    void del() const;

    // Getters e Setters:
    std::string getName() const { return name; }
    Color getColor() const { return color; }
    std::string getColorName() const { return color.getName(); }
    std::string getColorHexCode() const { return color.getHexCode(); }

    void setName(const std::string& name) { this->name = name; }
    void setColor(const Color& color) { this->color = color; }
};

#endif
