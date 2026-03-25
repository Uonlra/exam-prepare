#include <algorithm>
#include <array>
#include <cmath>
#include <cfloat>
#include <climits>
#include <iomanip>
#include <iostream>
#include <limits>
#include <memory>
#include <string>
using namespace std;

class Exercise {
public:
    virtual ~Exercise() = default;
    virtual void run() = 0;
};

class AverageExercise : public Exercise {
private:
    int a = 0;
    int b = 0;
    int c = 0;

public:
    void run() override {
        cin >> a >> b >> c;
        cout << fixed << setprecision(3) << (a + b + c) / 3.0 << '\n';
    }
};

class TemperatureExercise : public Exercise {
private:
    double fahrenheit = 0.0;

public:
    void run() override {
        cin >> fahrenheit;
        double celsius = 5.0 * (fahrenheit - 32.0) / 9.0;
        cout << fixed << setprecision(3) << celsius << '\n';
    }
};

class SumExercise : public Exercise {
private:
    long long n = 0;

public:
    void run() override {
        cin >> n;
        cout << n * (n + 1) / 2 << '\n';
    }
};

class TrigonometryExercise : public Exercise {
private:
    static constexpr double pi = 3.14159265358979323846;
    double degree = 0.0;

public:
    void run() override {
        cin >> degree;
        double radian = degree * pi / 180.0;
        cout << fixed << setprecision(6) << sin(radian) << ' ' << cos(radian) << '\n';
    }
};

class DiscountExercise : public Exercise {
private:
    static constexpr double unit_price = 95.0;
    static constexpr double discount_rate = 0.85;
    int count = 0;

public:
    void run() override {
        cin >> count;
        double total = count * unit_price;
        if (total >= 300.0) {
            total *= discount_rate;
        }
        cout << fixed << setprecision(2) << total << '\n';
    }
};

class TriangleExercise : public Exercise {
private:
    array<int, 3> sides{};

    bool isTriangle() {
        sort(sides.begin(), sides.end());
        return sides[0] + sides[1] > sides[2];
    }

    bool isRightTriangle() const {
        return sides[0] * sides[0] + sides[1] * sides[1] == sides[2] * sides[2];
    }

public:
    void run() override {
        cin >> sides[0] >> sides[1] >> sides[2];
        if (!isTriangle()) {
            cout << "not a triangle\n";
        } else if (isRightTriangle()) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
};

class YearExercise : public Exercise {
private:
    int year = 0;

    bool isLeapYear() const {
        return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    }

public:
    void run() override {
        cin >> year;
        cout << (isLeapYear() ? "yes" : "no") << '\n';
    }
};

class ExtraNotesExercise : public Exercise {
public:
    void run() override {
        cout << "int min = " << INT_MIN << ", int max = " << INT_MAX << '\n';
        cout << "double digits10 = " << numeric_limits<double>::digits10 << '\n';
        cout << "double max = " << DBL_MAX << '\n';
        cout << "double min positive = " << DBL_MIN << '\n';
        cout << "Operator priority: ! > && > ||" << '\n';
        cout << "Dangling else: else matches the nearest unmatched if." << '\n';
    }
};

class ExerciseFactory {
public:
    static unique_ptr<Exercise> create(const string& id) {
        if (id == "1-1") return make_unique<AverageExercise>();
        if (id == "1-2") return make_unique<TemperatureExercise>();
        if (id == "1-3") return make_unique<SumExercise>();
        if (id == "1-4") return make_unique<TrigonometryExercise>();
        if (id == "1-5") return make_unique<DiscountExercise>();
        if (id == "1-6") return make_unique<TriangleExercise>();
        if (id == "1-7") return make_unique<YearExercise>();
        if (id == "extra") return make_unique<ExtraNotesExercise>();
        return nullptr;
    }
};

int main() {
    string id;
    cin >> id;

    unique_ptr<Exercise> exercise = ExerciseFactory::create(id);
    if (exercise != nullptr) {
        exercise->run();
    }
    return 0;
}
