#include <iostream>
#include "time_for_registration.h"
#include "time_for_registration.cpp"
#include "FIO.h"
#include "FIO.cpp"
#include "calendar_of_dates.h"
#include "calendar_of_dates.cpp"
#include "client's_documents.h"
#include "client's_documents.cpp"
#include "doctors.h"
#include "doctors.cpp"
#include "client.h"
#include "client.cpp"
#include "employee.h"
#include "employee.cpp"
#include "visiting.cpp"
#include "visiting.h"
#include "date.h"
#include "date.cpp"
#include "cabinet.cpp"
#include "cabinet.h"
#include "equipment.cpp"
#include "equipment.h"
#include "schedule.cpp"
#include "schedule.h"
#include "tvector.cpp"
#include "tvector.h"


#include <cstdio>
#include <Windows.h>

void set_color(int text_color, int bg_color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bg_color << 4) | text_color);
}

namespace TestSystem {
    int count_success = 0, count_failed = 0;

    void start_test(bool(*test)(), const char* name_of_test) {
        set_color(2, 0);
        std::cout << "[ RUN      ]";
        set_color(7, 0);
        std::cout << name_of_test << std::endl;

        bool status = test();

        if (status == true) {
            set_color(2, 0);
            std::cout << "[       OK ]" << std::endl;
            count_success++;
        }
        else {
            set_color(4, 0);
            std::cout << "[  FAILED  ]" << std::endl;
            count_failed++;
        }
        set_color(7, 0);
    }

    template <class T>
    bool check(const T& expected, const T& actual) {
        if (expected == actual) {
            return true;
        }
        else {
            std::cerr << "Expected result is " << expected << ", but actual is " << actual << "." << std::endl;
            return false;
        }
    }

    void print_init_info() {
        set_color(2, 0);
        std::cout << "[==========] " << std::endl;
        set_color(7, 0);
    }

    void print_final_info() {
        set_color(2, 0);
        std::cout << "[==========] ";
        set_color(7, 0);
        std::cout << count_success + count_failed << " test" << (count_success + count_failed > 1 ? "s" : "") << " ran." << std::endl;
        set_color(2, 0);
        std::cout << "[  PASSED  ] ";
        set_color(7, 0);
        std::cout << count_success << " test" << (count_success > 1 ? "s" : "") << std::endl;
        if (count_failed > 0) {
            set_color(4, 0);
            std::cout << "[  FAILED  ] ";
            set_color(7, 0);
            std::cout << count_failed << " test" << (count_failed > 1 ? "s." : ".") << std::endl;
        }
    }
};

// Тест конструктора по умолчанию
bool test_1_default_constructor() {
    TVector<int> vec;
    bool expected_result = true;
    bool actual_result = (vec.get_size() == 0 && vec.get_capacity() == 0);
    return TestSystem::check(expected_result, actual_result);
}

// Тест конструктора с начальным размером
bool test_2_size_constructor() {
    TVector<int> vec(5);
    bool expected_result = true;
    bool actual_result = (vec.get_size() == 5 && vec.get_capacity() == 5);
    return TestSystem::check(expected_result, actual_result);
}

// Тест конструктора копирования
bool test_3_copy_constructor() {
    TVector<int> original;
    original.push_back(1);
    original.push_back(2);
    original.push_back(3);

    TVector<int> copy(original);
    bool expected_result = true;
    bool actual_result = (copy.get_size() == original.get_size() &&
        copy.get_capacity() == original.get_capacity() &&
        copy[0] == original[0] &&
        copy[1] == original[1] &&
        copy[2] == original[2]);
    return TestSystem::check(expected_result, actual_result);
}

// Тест оператора присваивания
bool test_4_assignment_operator() {
    TVector<int> original;
    original.push_back(1);
    original.push_back(2);
    original.push_back(3);

    TVector<int> copy;
    copy = original;
    bool expected_result = true;
    bool actual_result = (copy.get_size() == original.get_size() &&
        copy.get_capacity() == original.get_capacity() &&
        copy[0] == original[0] &&
        copy[1] == original[1] &&
        copy[2] == original[2]);
    return TestSystem::check(expected_result, actual_result);
}

// Тест метода push_back
bool test_5_push_back() {
    TVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    bool expected_result = true;
    bool actual_result = (vec.get_size() == 3 &&
        vec[0] == 1 &&
        vec[1] == 2 &&
        vec[2] == 3);
    return TestSystem::check(expected_result, actual_result);
}

// Тест метода pop_back
bool test_6_pop_back() {
    TVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.pop_back();

    bool expected_result = true;
    bool actual_result = (vec.get_size() == 2 &&
        vec[0] == 1 &&
        vec[1] == 2);
    return TestSystem::check(expected_result, actual_result);
}

// Тест метода clear
bool test_7_clear() {
    TVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.clear();

    bool expected_result = true;
    bool actual_result = (vec.get_size() == 0);
    return TestSystem::check(expected_result, actual_result);
}

// Тест метода empty
bool test_8_empty() {
    TVector<int> vec;
    bool expected_result = true;
    bool actual_result = vec.empty();

    vec.push_back(1);
    bool expected_result2 = false;
    bool actual_result2 = vec.empty();

    return TestSystem::check(expected_result, actual_result) &&
        TestSystem::check(expected_result2, actual_result2);
}

// Тест оператора []
bool test_9_operator_brackets() {
    TVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    bool expected_result = true;
    bool actual_result = (vec[0] == 1 &&
        vec[1] == 2 &&
        vec[2] == 3);

    // Проверка изменения элементов
    vec[0] = 10;
    vec[1] = 20;
    vec[2] = 30;

    bool expected_result2 = true;
    bool actual_result2 = (vec[0] == 10 &&
        vec[1] == 20 &&
        vec[2] == 30);

    return TestSystem::check(expected_result, actual_result) &&
        TestSystem::check(expected_result2, actual_result2);
}

// Тест метода at
bool test_10_at() {
    TVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    bool expected_result = true;
    bool actual_result = (vec.at(0) == 1 &&
        vec.at(1) == 2 &&
        vec.at(2) == 3);

    // Проверка изменения элементов
    vec.at(0) = 10;
    vec.at(1) = 20;
    vec.at(2) = 30;

    bool expected_result2 = true;
    bool actual_result2 = (vec.at(0) == 10 &&
        vec.at(1) == 20 &&
        vec.at(2) == 30);

    return TestSystem::check(expected_result, actual_result) &&
        TestSystem::check(expected_result2, actual_result2);
}

// Тест метода reserve
bool test_11_reserve() {
    TVector<int> vec;
    vec.reserve(10);

    bool expected_result = true;
    bool actual_result = (vec.get_capacity() >= 10);

    // Проверка, что размер не изменился
    bool expected_result2 = true;
    bool actual_result2 = (vec.get_size() == 0);

    return TestSystem::check(expected_result, actual_result) &&
        TestSystem::check(expected_result2, actual_result2);
}

// Тест метода get_capacity
bool test_12_get_capacity() {
    TVector<int> vec;
    bool expected_result = true;
    bool actual_result = (vec.get_capacity() == 0);

    vec.reserve(5);
    bool expected_result2 = true;
    bool actual_result2 = (vec.get_capacity() >= 5);

    return TestSystem::check(expected_result, actual_result) &&
        TestSystem::check(expected_result2, actual_result2);
}

int main() {
    TestSystem::print_init_info();

    TestSystem::start_test(test_1_default_constructor, "TVector.test_1_default_constructor");
    TestSystem::start_test(test_2_size_constructor, "TVector.test_2_size_constructor");
    TestSystem::start_test(test_3_copy_constructor, "TVector.test_3_copy_constructor");
    TestSystem::start_test(test_4_assignment_operator, "TVector.test_4_assignment_operator");
    TestSystem::start_test(test_5_push_back, "TVector.test_5_push_back");
    TestSystem::start_test(test_6_pop_back, "TVector.test_6_pop_back");
    TestSystem::start_test(test_7_clear, "TVector.test_7_clear");
    TestSystem::start_test(test_8_empty, "TVector.test_8_empty");
    TestSystem::start_test(test_9_operator_brackets, "TVector.test_9_operator_brackets");
    TestSystem::start_test(test_10_at, "TVector.test_10_at");
    TestSystem::start_test(test_11_reserve, "TVector.test_11_reserve");
    TestSystem::start_test(test_12_get_capacity, "TVector.test_12_get_capacity");

    TestSystem::print_final_info();
    system("pause");
    return 0;
}
