#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Worker {
    char name[15];        // ����
    char department[18];  // ��λ
    char gender[3];       // �Ա�
    unsigned int age;     // ����
    unsigned long telephone; // �绰
    unsigned long wage;      // ����
    unsigned long num;       // ְ����
    struct Worker* next;
} Worker;

void InsertWorker(Worker** head) {
    Worker* new_worker = (Worker*)malloc(sizeof(Worker));
    if (!new_worker) {
        printf("�ڴ����ʧ��\n");
        return;
    }

    printf("������ְ����: ");
    while (scanf("%lu", &new_worker->num) != 1) {
        printf("��Ч���룬����������: ");
        while (getchar() != '\n'); 
    }

    printf("����������: ");
    scanf("%s", new_worker->name);

    printf("�����뵥λ: ");
    scanf("%s", new_worker->department);

    printf("�������Ա�(��/Ů): ");
    while (scanf("%s", new_worker->gender) != 1 || (strcmp(new_worker->gender, "��") != 0 && strcmp(new_worker->gender, "Ů") != 0)) {
        printf("��Ч���룬������ �� �� Ů: ");
        while (getchar() != '\n');
    }

    printf("����������(18-65): ");
    while (scanf("%u", &new_worker->age) != 1 || new_worker->age < 18 || new_worker->age > 65) {
        printf("��Ч���룬������18��65֮�������: ");
        while (getchar() != '\n'); 
    }

    printf("������绰: ");
    while (scanf("%lu", &new_worker->telephone) != 1) {
        printf("��Ч���룬����������: ");
        while (getchar() != '\n'); 
    }

    printf("�����빤��: ");
    while (scanf("%lu", &new_worker->wage) != 1) {
        printf("��Ч���룬����������: ");
        while (getchar() != '\n'); 
    }

    new_worker->next = *head;
    *head = new_worker;

    printf("��ʾ����ӳɹ�\n");
}

void DisplayWorkers(const Worker* head) {
    if (!head) {
        printf("��ʾ:û���κ�ְ����¼\n");
        return;
    }

    printf("------------------------------------------------------------------------\n");
    printf("| %8s | %14s | %16s | %4s | %4s | %10s | %8s |\n", "ְ����", "����", "��λ", "�Ա�", "����", "�绰", "����");
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
        printf("��ʾ:û���κ�ְ����¼\n");
        return;
    }

    unsigned long num;
    printf("������Ҫɾ����ְ����: ");
    while (scanf("%lu", &num) != 1) {
        printf("��Ч���룬����������: ");
        while (getchar() != '\n');
    }

    Worker* prev = NULL, * curr = *head;
    while (curr && curr->num != num) {
        prev = curr;
        curr = curr->next;
    }

    if (!curr) {
        printf("��ʾ:ָ����ְ����¼������\n");
        return;
    }

    if (!prev) {
        *head = curr->next;
    }
    else {
        prev->next = curr->next;
    }

    free(curr);
    printf("��ʾ:ɾ���ɹ�\n");
}

void ModifyWorker(Worker* head) {
    if (!head) {
        printf("��ʾ:û���κ�ְ����¼\n");
        return;
    }

    unsigned long num;
    printf("������Ҫ�޸ĵ�ְ����: ");
    while (scanf("%lu", &num) != 1) {
        printf("��Ч���룬����������: ");
        while (getchar() != '\n'); 
    }

    Worker* p = head;
    while (p && p->num != num) {
        p = p->next;
    }

    if (!p) {
        printf("��ʾ:ָ����ְ����¼������\n");
        return;
    }

    printf("�������µ�����: ");
    scanf("%s", p->name);

    printf("�������µĵ�λ: ");
    scanf("%s", p->department);

    printf("�������µ��Ա�(��/Ů): ");
    while (scanf("%s", p->gender) != 1 || (strcmp(p->gender, "��") != 0 && strcmp(p->gender, "Ů") != 0)) {
        printf("��Ч���룬������ �� �� Ů: ");
        while (getchar() != '\n'); 
    }

    printf("�������µ�����(18-65): ");
    while (scanf("%u", &p->age) != 1 || p->age < 18 || p->age > 65) {
        printf("��Ч���룬������18��65֮�������: ");
        while (getchar() != '\n'); 
    }

    printf("�������µĵ绰: ");
    while (scanf("%lu", &p->telephone) != 1) {
        printf("��Ч���룬����������: ");
        while (getchar() != '\n'); 
    }

    printf("�������µĹ���: ");
    while (scanf("%lu", &p->wage) != 1) {
        printf("��Ч���룬����������: ");
        while (getchar() != '\n'); 
    }

    printf("��ʾ:�޸ĳɹ�\n");
}

void FindWorker(const Worker* head) {
    if (!head) {
        printf("��ʾ:û���κ�ְ����¼\n");
        return;
    }

    unsigned long num;
    printf("������Ҫ���ҵ�ְ����: ");
    while (scanf("%lu", &num) != 1) {
        printf("��Ч���룬����������: ");
        while (getchar() != '\n'); 
    }

    const Worker* p = head;
    while (p && p->num != num) {
        p = p->next;
    }

    if (!p) {
        printf("��ʾ:ָ����ְ����¼������\n");
        return;
    }

    printf("------------------------------------------------------------------------\n");
    printf("| %8s | %14s | %16s | %4s | %4s | %10s | %8s |\n", "ְ����", "����", "��λ", "�Ա�", "����", "�绰", "����");
    printf("------------------------------------------------------------------------\n");
    printf("| %8lu | %14s | %16s | %4s | %4u | %10lu | %8lu |\n",
        p->num, p->name, p->department, p->gender, p->age, p->telephone, p->wage);
    printf("------------------------------------------------------------------------\n");
}

void SortByWage(Worker* head) {
    if (!head) {
        printf("��ʾ:û���κ�ְ����¼\n");
        return;
    }

    // �򵥵�ð������
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

    printf("��ʾ:�����ʵ����������\n");
}

void CalculateAverageWage(const Worker* head) {
    if (!head) {
        printf("��ʾ:û���κ�ְ����¼\n");
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
    printf("ְ����ƽ������Ϊ: %.2f\n", averageWage);
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
        printf("\nְ������ϵͳ\n");
        printf("1. ���ְ����Ϣ\n");
        printf("2. ��ʾְ����Ϣ\n");
        printf("3. ɾ��ְ����Ϣ\n");
        printf("4. �޸�ְ����Ϣ\n");
        printf("5. ����ְ����Ϣ\n");
        printf("6. ����������\n");
        printf("7. ����ƽ������\n");
        printf("0. �˳�\n");
        printf("��ѡ�����: ");

        while (scanf("%d", &choice) != 1) {
            printf("��Ч���룬����������: ");
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
            printf("�˳�ϵͳ\n");
            break;
        default:
            printf("��Ч��ѡ��������ѡ��\n");
            break;
        }
    } while (choice != 0);

    return 0;
}
