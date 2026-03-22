#include <cmath>
#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Exercise {
public:
    virtual ~Exercise() = default;
    virtual void run() = 0;
};

class DaffodilExercise : public Exercise {
public:
    void run() override {
        for (int number = 100; number <= 999; ++number) {
            int a = number / 100;
            int b = number / 10 % 10;
            int c = number % 10;
            if (number == a * a * a + b * b * b + c * c * c) {
                cout << number << '\n';
            }
        }
    }
};

class HanXinExercise : public Exercise {
public:
    void run() override {
        int a = 0;
        int b = 0;
        int c = 0;
        int case_id = 1;
        while (cin >> a >> b >> c) {
            int answer = -1;
            for (int soldiers = 10; soldiers <= 100; ++soldiers) {
                if (soldiers % 3 == a && soldiers % 5 == b && soldiers % 7 == c) {
                    answer = soldiers;
                    break;
                }
            }

            cout << "Case " << case_id << ": ";
            if (answer == -1) {
                cout << "No answer\n";
            } else {
                cout << answer << '\n';
            }
            ++case_id;
        }
    }
};

class TriangleExercise : public Exercise {
public:
    void run() override {
        int n = 0;
        cin >> n;
        for (int row = n; row >= 1; --row) {
            for (int column = 1; column <= 2 * row - 1; ++column) {
                cout << '#';
            }
            cout << '\n';
        }
    }
};

class SubsequenceExercise : public Exercise {
public:
    void run() override {
        int n = 0;
        int m = 0;
        int case_id = 1;
        while (cin >> n >> m && !(n == 0 && m == 0)) {
            double sum = 0.0;
            for (int i = n; i <= m; ++i) {
                sum += 1.0 / (static_cast<double>(i) * i);
            }
            cout << fixed << setprecision(5)
                 << "Case " << case_id << ": " << sum << '\n';
            ++case_id;
        }
    }
};

class DecimalExercise : public Exercise {
public:
    void run() override {
        int a = 0;
        int b = 0;
        int c = 0;
        int case_id = 1;
        while (cin >> a >> b >> c && !(a == 0 && b == 0 && c == 0)) {
            double value = static_cast<double>(a) / b;
            cout << "Case " << case_id << ": " << fixed << setprecision(c)
                 << value << '\n';
            ++case_id;
        }
    }
};

class PermutationExercise : public Exercise {
public:
    void run() override {
        for (int abc = 123; abc <= 329; ++abc) {
            int def = abc * 2;
            int ghi = abc * 3;

            int used[10] = {};
            if (check(abc, used) && check(def, used) && check(ghi, used)) {
                cout << abc << ' ' << def << ' ' << ghi << '\n';
            }
        }
    }

private:
    bool check(int number, int used[]) {
        for (int i = 0; i < 3; ++i) {
            int digit = number % 10;
            if (digit == 0 || used[digit] != 0) {
                return false;
            }
            used[digit] = 1;
            number /= 10;
        }
        return true;
    }
};

class ExtraNotesExercise : public Exercise {
public:
    void run() override {
        cout << "题目1 任务1: 保持 for 条件不变，可把第7行改成 printf(\"%d\\n\", 2 * i);" << '\n';
        cout << "题目1 任务2: 保持 printf 不变，可把第6行改成 for(int i = 2; i <= 2 * n; i += 2)" << '\n';
        cout << "题目2: 这个循环通常不会在 i 恰好等于 10 时结束，因为 0.1 无法被浮点数精确表示。" << '\n';
        cout << "建议把条件改成 i < 10，或改用整数循环后再换算成小数。" << '\n';
    }
};

class ExerciseFactory {
public:
    static unique_ptr<Exercise> create(const string& id) {
        if (id == "2-1") return make_unique<DaffodilExercise>();
        if (id == "2-2") return make_unique<HanXinExercise>();
        if (id == "2-3") return make_unique<TriangleExercise>();
        if (id == "2-4") return make_unique<SubsequenceExercise>();
        if (id == "2-5") return make_unique<DecimalExercise>();
        if (id == "2-6") return make_unique<PermutationExercise>();
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
