#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const double EPS = 1e-6;
const char* subjects[] = {"Chinese", "Mathematics", "English", "Programming"};

int n = 0;  // 当前学生数
char sid[MAXN][15];      // 学生ID
int cid[MAXN];           // 班级ID
char name[MAXN][15];     // 姓名
int score[MAXN][4];      // 4门课程成绩
bool removed[MAXN];      // 是否被删除标记

int get_total_score(int i) {
    return score[i][0] + score[i][1] + score[i][2] + score[i][3];
}

double get_avg_score(int i) {
    return get_total_score(i) / 4.0;
}

int get_rank(int i) {
    int rank = 1;
    int total = get_total_score(i);
    for (int j = 0; j < n; j++) {
        if (!removed[j] && j != i && get_total_score(j) > total) {
            rank++;
        }
    }
    return rank;
}

void print_menu() {
    printf("Welcome to Student Performance Management System (SPMS).\n");
    printf("1 - Add\n");
    printf("2 - Remove\n");
    printf("3 - Query\n");
    printf("4 - Show ranking\n");
    printf("5 - Show Statistics\n");
    printf("0 - Exit\n");
}

void add() {
    char buf[15];
    for (;;) {
        printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");
        scanf("%s", buf);
        if (strcmp(buf, "0") == 0) break;
        
        strcpy(sid[n], buf);
        scanf("%d", &cid[n]);
        scanf("%s", name[n]);
        for (int j = 0; j < 4; j++) {
            scanf("%d", &score[n][j]);
        }
        
        // 检查重复SID
        bool dup = false;
        for (int i = 0; i < n; i++) {
            if (strcmp(sid[i], sid[n]) == 0) {
                dup = true;
                break;
            }
        }
        
        if (dup) {
            printf("Duplicated SID.\n");
        } else {
            removed[n] = false;
            n++;
        }
    }
}

void remove_student() {
    char s[15];
    for (;;) {
        printf("Please enter SID or name. Enter 0 to finish.\n");
        scanf("%s", s);
        if (strcmp(s, "0") == 0) break;
        
        int r = 0;
        for (int i = 0; i < n; i++) {
            if (!removed[i] && (strcmp(sid[i], s) == 0 || strcmp(name[i], s) == 0)) {
                removed[i] = true;
                r++;
            }
        }
        printf("%d student(s) removed.\n", r);
    }
}

void query_student() {
    char s[15];
    for (;;) {
        printf("Please enter SID or name. Enter 0 to finish.\n");
        scanf("%s", s);
        if (strcmp(s, "0") == 0) break;
        
        for (int i = 0; i < n; i++) {
            if (!removed[i] && (strcmp(sid[i], s) == 0 || strcmp(name[i], s) == 0)) {
                int total = get_total_score(i);
                double avg = get_avg_score(i);
                printf("%d %s %d %s %d %d %d %d %d %.2f\n", 
                    get_rank(i), sid[i], cid[i], name[i], 
                    score[i][0], score[i][1], score[i][2], score[i][3],
                    total, avg);
            }
        }
    }
}

void show_statistics() {
    for (int subj = 0; subj < 4; subj++) {
        printf("%s\n", subjects[subj]);
        int passed = 0, failed = 0;
        double sum = 0;
        for (int i = 0; i < n; i++) {
            if (!removed[i]) {
                sum += score[i][subj];
                if (score[i][subj] >= 60) passed++;
                else failed++;
            }
        }
        int count = passed + failed;
        double avg = (count > 0) ? (sum / count) : 0;
        printf("Average Score: %.2f\n", avg);
        printf("Number of passed students: %d\n", passed);
        printf("Number of failed students: %d\n", failed);
    }
    
    printf("Overall:\n");
    int pass_all = 0, pass_3 = 0, pass_2 = 0, pass_1 = 0, fail_all = 0;
    
    for (int i = 0; i < n; i++) {
        if (!removed[i]) {
            int pass_count = 0;
            for (int j = 0; j < 4; j++) {
                if (score[i][j] >= 60) pass_count++;
            }
            if (pass_count == 4) pass_all++;
            if (pass_count >= 3) pass_3++;
            if (pass_count >= 2) pass_2++;
            if (pass_count >= 1) pass_1++;
            if (pass_count == 0) fail_all++;
        }
    }
    
    printf("Number of students who passed all subjects: %d\n", pass_all);
    printf("Number of students who passed 3 or more subjects: %d\n", pass_3);
    printf("Number of students who passed 2 or more subjects: %d\n", pass_2);
    printf("Number of students who passed 1 or more subjects: %d\n", pass_1);
    printf("Number of students who failed all subjects: %d\n", fail_all);
}

int main() {
    for (;;) {
        int choice;
        print_menu();
        scanf("%d", &choice);
        if (choice == 0) break;
        if (choice == 1) add();
        if (choice == 2) remove_student();
        if (choice == 3) query_student();
        if (choice == 4) printf("Showing the ranklist hurts students' self-esteem. Don't do that.\n");
        if (choice == 5) show_statistics();
    }
    return 0;
}
