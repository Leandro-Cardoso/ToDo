#include "Task.hpp"

Task::Task(
    const std::string& name,
    const std::string description,
    const Category category
) : name(name),
    description(description),
    category(category) {
    this->isDone = false;
}

void Task::save() const {
}

void Task::del() const {
}

// TODO: Salvar em binário.
// TODO: Deletar savo.
// TODO: Carregar lista.
