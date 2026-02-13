#ifndef TASK_H
#define TASK_H

#include <string>
#include <vector>

#include "Category.hpp"

class Task {
private:
    std::string name;
    std::string description;
    Category category;
    std::vector<Task> subTasks;
    bool isDone;

public:
    Task(
        const std::string& name,
        const std::string description,
        const Category category
    );

    void save() const;
    void del() const;
    void addSubTasks(const Task task) { this->subTasks.insert(task); };
    void done() { this->isDone = true; }

    // Getters e Setters:
    std::string getName() const { return name; }
    std::string getDescription() const { return description; }
    Category getCategory() const { return category; }
    std::vector<Task> getSubTasks() const { return subTasks; }
    bool isDone() const { return isDone; }
};

#endif
