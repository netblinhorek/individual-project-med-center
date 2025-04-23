#pragma once
#include <string>

class Equipment {
private:
    int id;
    std::string name;
    std::string description;
    bool isAvailable;

public:
    // ������������
    Equipment();
    Equipment(int id, const std::string& name, const std::string& description);

    // �������
    int getId() const;
    std::string getName() const;
    std::string getDescription() const;
    bool getIsAvailable() const;

    // �������
    void setId(int id);
    void setName(const std::string& name);
    void setDescription(const std::string& description);
    void setIsAvailable(bool isAvailable);

    // ������
    std::string getInfo() const;
};
