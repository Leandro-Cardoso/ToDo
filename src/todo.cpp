#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Category {
    std::string name;
    std::string color;
}

struct Task {
    std::string name;
    std::string description;
    Category category;
    Task subTasks;
    bool isDone;
};

// Carregar:
void loadTasks(std::vector<Task>& tasks) {
    std::ifstream file("tasks.bin", std::ios::binary);
    if (!file) return;

    while (file.peek() != EOF) {
        Task t;
        size_t size;

        // 1. Ler o status
        file.read(reinterpret_cast<char*>(&t.isDone), sizeof(t.isDone));

        // 2. Ler o tamanho da string
        file.read(reinterpret_cast<char*>(&size), sizeof(size));

        // 3. Redimensionar a string e ler os caracteres
        t.description.resize(size);
        file.read(&t.description[0], size);

        tasks.push_back(t);
    }
    file.close();
}

// Salvar:
void saveTasks(const std::vector<Task>& tasks) {
    std::ofstream file("tasks.bin", std::ios::binary);

    for (const auto& t : tasks) {
        // 1. Salvar o status (bool)
        file.write(reinterpret_cast<const char*>(&t.isDone), sizeof(t.isDone));

        // 2. Salvar o tamanho da string
        size_t size = t.description.size();
        file.write(reinterpret_cast<const char*>(&size), sizeof(size));

        // 3. Salvar os caracteres da string
        file.write(t.description.c_str(), size);
    }
    file.close();
}
