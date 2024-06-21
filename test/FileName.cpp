#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Worker {
    char name[15];        // 姓名
    char department[18];  // 单位
    char gender[3];       // 性别
    unsigned int age;     // 年龄
    unsigned long telephone; // 电话
    unsigned long wage;      // 工资
    unsigned long num;       // 职工号
    struct Worker* next;
} Worker;

void InsertWorker(Worker** head) {
    Worker* new_worker = (Worker*)malloc(sizeof(Worker));
    if (!new_worker) {
        printf("内存分配失败\n");
        return;
    }

    printf("请输入职工号: ");
    while (scanf("%lu", &new_worker->num) != 1) {
        printf("无效输入，请输入数字: ");
        while (getchar() != '\n'); 
    }

    printf("请输入姓名: ");
    scanf("%s", new_worker->name);

    printf("请输入单位: ");
    scanf("%s", new_worker->department);

    printf("请输入性别(男/女): ");
    while (scanf("%s", new_worker->gender) != 1 || (strcmp(new_worker->gender, "男") != 0 && strcmp(new_worker->gender, "女") != 0)) {
        printf("无效输入，请输入 男 或 女: ");
        while (getchar() != '\n');
    }

    printf("请输入年龄(18-65): ");
    while (scanf("%u", &new_worker->age) != 1 || new_worker->age < 18 || new_worker->age > 65) {
        printf("无效输入，请输入18到65之间的年龄: ");
        while (getchar() != '\n'); 
    }

    printf("请输入电话: ");
    while (scanf("%lu", &new_worker->telephone) != 1) {
        printf("无效输入，请输入数字: ");
        while (getchar() != '\n'); 
    }

    printf("请输入工资: ");
    while (scanf("%lu", &new_worker->wage) != 1) {
        printf("无效输入，请输入数字: ");
        while (getchar() != '\n'); 
    }

    new_worker->next = *head;
    *head = new_worker;

    printf("提示：添加成功\n");
}

void DisplayWorkers(const Worker* head) {
    if (!head) {
        printf("提示:没有任何职工记录\n");
        return;
    }

    printf("------------------------------------------------------------------------\n");
    printf("| %8s | %14s | %16s | %4s | %4s | %10s | %8s |\n", "职工号", "姓名", "单位", "性别", "年龄", "电话", "工资");
    printf("------------------------------------------------------------------------\n");

    const Worker* p = head;
    while (p) {
        printf("| %8lu | %14s | %16s | %4s | %4u | %10lu | %8lu |\n",
            p->num, p->name, p->department, p->gender, p->age, p->telephone, p->wage);
        p = p->next;
    }

    printf("------------------------------------------------------------------------\n");
}

void DeleteWorker(Worker** head) {
    if (!*head) {
        printf("提示:没有任何职工记录\n");
        return;
    }

    unsigned long num;
    printf("请输入要删除的职工号: ");
    while (scanf("%lu", &num) != 1) {
        printf("无效输入，请输入数字: ");
        while (getchar() != '\n');
    }

    Worker* prev = NULL, * curr = *head;
    while (curr && curr->num != num) {
        prev = curr;
        curr = curr->next;
    }

    if (!curr) {
        printf("提示:指定的职工记录不存在\n");
        return;
    }

    if (!prev) {
        *head = curr->next;
    }
    else {
        prev->next = curr->next;
    }

    free(curr);
    printf("提示:删除成功\n");
}

void ModifyWorker(Worker* head) {
    if (!head) {
        printf("提示:没有任何职工记录\n");
        return;
    }

    unsigned long num;
    printf("请输入要修改的职工号: ");
    while (scanf("%lu", &num) != 1) {
        printf("无效输入，请输入数字: ");
        while (getchar() != '\n'); 
    }

    Worker* p = head;
    while (p && p->num != num) {
        p = p->next;
    }

    if (!p) {
        printf("提示:指定的职工记录不存在\n");
        return;
    }

    printf("请输入新的姓名: ");
    scanf("%s", p->name);

    printf("请输入新的单位: ");
    scanf("%s", p->department);

    printf("请输入新的性别(男/女): ");
    while (scanf("%s", p->gender) != 1 || (strcmp(p->gender, "男") != 0 && strcmp(p->gender, "女") != 0)) {
        printf("无效输入，请输入 男 或 女: ");
        while (getchar() != '\n'); 
    }

    printf("请输入新的年龄(18-65): ");
    while (scanf("%u", &p->age) != 1 || p->age < 18 || p->age > 65) {
        printf("无效输入，请输入18到65之间的年龄: ");
        while (getchar() != '\n'); 
    }

    printf("请输入新的电话: ");
    while (scanf("%lu", &p->telephone) != 1) {
        printf("无效输入，请输入数字: ");
        while (getchar() != '\n'); 
    }

    printf("请输入新的工资: ");
    while (scanf("%lu", &p->wage) != 1) {
        printf("无效输入，请输入数字: ");
        while (getchar() != '\n'); 
    }

    printf("提示:修改成功\n");
}

void FindWorker(const Worker* head) {
    if (!head) {
        printf("提示:没有任何职工记录\n");
        return;
    }

    unsigned long num;
    printf("请输入要查找的职工号: ");
    while (scanf("%lu", &num) != 1) {
        printf("无效输入，请输入数字: ");
        while (getchar() != '\n'); 
    }

    const Worker* p = head;
    while (p && p->num != num) {
        p = p->next;
    }

    if (!p) {
        printf("提示:指定的职工记录不存在\n");
        return;
    }

    printf("------------------------------------------------------------------------\n");
    printf("| %8s | %14s | %16s | %4s | %4s | %10s | %8s |\n", "职工号", "姓名", "单位", "性别", "年龄", "电话", "工资");
    printf("------------------------------------------------------------------------\n");
    printf("| %8lu | %14s | %16s | %4s | %4u | %10lu | %8lu |\n",
        p->num, p->name, p->department, p->gender, p->age, p->telephone, p->wage);
    printf("------------------------------------------------------------------------\n");
}

void SortByWage(Worker* head) {
    if (!head) {
        printf("提示:没有任何职工记录\n");
        return;
    }

    // 简单的冒泡排序
    for (Worker* i = head; i->next != NULL; i = i->next) {
        for (Worker* j = head; j->next != NULL; j = j->next) {
            if (j->wage > j->next->wage) {
                Worker temp = *j;
                *j = *(j->next);
                *(j->next) = temp;

                Worker* tempNext = j->next->next;
                j->next->next = j->next->next->next;
                j->next->next = tempNext;
            }
        }
    }

    printf("提示:按工资递增排序完毕\n");
}

void CalculateAverageWage(const Worker* head) {
    if (!head) {
        printf("提示:没有任何职工记录\n");
        return;
    }

    unsigned long totalWage = 0;
    unsigned int count = 0;
    const Worker* p = head;
    while (p) {
        totalWage += p->wage;
        count++;
        p = p->next;
    }

    double averageWage = (double)totalWage / count;
    printf("职工的平均工资为: %.2f\n", averageWage);
}

void DestroyWorkers(Worker* head) {
    Worker* p = head;
    while (p) {
        Worker* next = p->next;
        free(p);
        p = next;
    }
}

int main() {
    Worker* workers = NULL;
    int choice;

    do {
        printf("\n职工管理系统\n");
        printf("1. 添加职工信息\n");
        printf("2. 显示职工信息\n");
        printf("3. 删除职工信息\n");
        printf("4. 修改职工信息\n");
        printf("5. 查找职工信息\n");
        printf("6. 按工资排序\n");
        printf("7. 计算平均工资\n");
        printf("0. 退出\n");
        printf("请选择操作: ");

        while (scanf("%d", &choice) != 1) {
            printf("无效输入，请输入数字: ");
            while (getchar() != '\n'); 
        }

        switch (choice) {
        case 1:
            InsertWorker(&workers);
            break;
        case 2:
            DisplayWorkers(workers);
            break;
        case 3:
            DeleteWorker(&workers);
            break;
        case 4:
            ModifyWorker(workers);
            break;
        case 5:
            FindWorker(workers);
            break;
        case 6:
            SortByWage(workers);
            break;
        case 7:
            CalculateAverageWage(workers);
            break;
        case 0:
            DestroyWorkers(workers);
            printf("退出系统\n");
            break;
        default:
            printf("无效的选择，请重新选择\n");
            break;
        }
    } while (choice != 0);

    return 0;
}
