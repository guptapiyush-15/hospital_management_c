#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int total_cases = 0, Normal = 0, Emergency = 0;
int opt;
struct pa_node 
{
    char name[69], mode_of_admission[57], gender[17];
    char mobile[10];
    char email[87], med[78], drugs[56], other[77], operations[100], dia[100], current[100], doctor_visit[100], modeofconsultation[100], year[4];
    int height, weight, token;
    struct pa_node *pat1;
    struct doc_node *doctor;
} * t, *tem, *head = NULL;
struct doc_node 
{
    char name[100], dept[100];

    struct doc_node *pat, *id;
    struct pa_node *pat1;
} * p, *temp;
struct doc_node *a[26];
void make_it_NULL()  
{
    int i;
    for (i = 0; i < 26; i++)
        a[i] = NULL;
}
void new_doctor_entry(char a1[])  
{
    int m;
    struct doc_node *newnode, *p;
    newnode = (struct doc_node *)(malloc(sizeof(struct doc_node)));
    newnode->pat = NULL;
    newnode->pat1 = NULL;
    printf("Department of work: ");
    scanf("%s", newnode->dept);
    printf("Hi Doctor\n");
    strcpy(newnode->name, a1);
    m = a1[0] - 97;  
    if (a[m] == NULL)
    {
        a[m] = newnode;
    }
    else
    {
        p = a[m];
        while (p->pat != NULL)
            p = p->pat;
        p->pat = newnode;
    }

    printf("Doc.. This is your doc ID: %x %s\n", newnode, newnode->name);
}

struct doc_node *doctor_find()  
{
    int m, asd;
    char a1[100];
    int flag = 0, flag1;
    struct doc_node *aacc;
    printf("SEARCH\n1:byname\n2:by doc id");
    scanf("%d", &flag1);
    if (flag1 == 1)
    {

        printf("Enter name of the Doctor\n");
        scanf("%s", a1);
        m = a1[0] - 97;
        if (a[m] == NULL)
        {
            printf("Doctor Not found\n1.Do you want to try again\n2.exit");

            scanf("%d", &asd);
            if (asd == 1)
                doctor_find();
            else
                return NULL;
        }
        else
        {
            p = a[m];
            while (p->pat != NULL)
            {
                if (strcmp(p->name, a1) == 0)
                {
                    printf("%s %s %x\n", p->name, p->dept, p);
                    flag++;
                }
                p = p->pat;
            }
            if (strcmp(p->name, a1) == 0)
            {
                printf("%s %s %x\n", p->name, p->dept, p);
                flag++;
            }
            if (flag == 0)
            {
                printf("The doctor doesn't exist");
                printf("\n1.Do you want to try again\n2.exit");
                scanf("%d", &asd);
                if (asd == 1)
                    doctor_find();
                else
                {
                    if (asd == 2)
                        return NULL;
                }
            }

            else
            {
                printf("Enter the doc id");
                scanf("%x", &aacc);
                return aacc;
            }
        }
    }
    else
    {
        if (flag1 == 2)

            printf("Enter the doc id");
        scanf("%x", &aacc);
        return aacc;
    }
}
void doc_status(struct doc_node *doctor)  
{
    struct pa_node *coun_pa, *patient;
    printf("Doctor's Name :   %s\n", doctor->name);
    printf("doc id :   %x\n", doctor);
    p = doctor;
    coun_pa = p->pat1;
    int m = 0;
    while (coun_pa != NULL && p != NULL && p->pat1 != NULL)
    {
        coun_pa = coun_pa->pat1;
        m++;
    }
    printf("\nThe remaining number of patients are %d", m);
}
void patient_log(struct doc_node *doctor)  
{
    struct pa_node *coun_pa, *patient;
    printf("Doctor's Name   %s", doctor->name);
    printf("doc id :   %x\n", doctor);
    p = doctor;
    coun_pa = p->pat1;
    int m = 0;
    while (coun_pa != NULL && p != NULL && p->pat1 != NULL)
    {
        printf("%s %x\n", coun_pa->name, coun_pa);
        coun_pa = coun_pa->pat1;
    }
}

void pat_entry_doctor()  
{
    char a[100], b[100];
    struct pa_node *patient;
    struct doc_node *l;
    patient = (struct pa_node *)(malloc(sizeof(struct pa_node)));
    t = (struct pa_node *)(malloc(sizeof(struct pa_node)));
    patient->pat1 = NULL;
    printf("\n----------PATIENT's INFORMATION----------\n");
    printf("Enter your name : ");
    scanf("%s", patient->name);
    printf("\n");
    printf("Enter your gender:");
    scanf("%s", patient->gender);
    printf("\n");
    printf("Enter your mobile number");
    scanf("%s", patient->mobile);
    printf("\n");
    printf("Enter your email:(optional)\n");
    scanf("%s", patient->email);
    printf("Enter DOB : ");
    scanf("%s", patient->year);
    printf("\n");
    printf("Type of consultation\n1.Normal\n2.Emergency\nEnter your choice:");
    int as;
    scanf("%d", &as);
    if (as == 1)
    {
        patient->doctor = doctor_find();
        l = patient->doctor;

        if (l != NULL)
        {
            strcpy(patient->doctor_visit, patient->doctor->name);
            t = l->pat1;
            if (t == NULL)
            {
                t = patient;
                l->pat1 = t;
                printf("The patient's id: %x\n", patient);
                Normal++;
            }
            else
            {
                while (t->pat1 != NULL)
                    t = t->pat1;
                t->pat1 = patient;
                printf("The patient mem id: %x\n", patient);
                Normal++;
            }
        }
        else
            printf("doctor doesn't exist\n");
    }
    else
    {
        Emergency++;
        if (head == NULL)
        {
            head = patient;
        }
        else
        {
            tem = head;
            while (tem->pat1 != NULL)
                tem = tem->pat1;
            tem->pat1 = patient;
        }
    }
}
void delete(struct doc_node *doctor)  
{

    struct pa_node *node;
    if (doctor->pat1 == NULL)
        printf("The queue is Empty");
    else
    {
        node = doctor->pat1;
        doctor->pat1 = node->pat1;
        free(node);
    }
}

int main()
{
    int choice;
    char g[117];
    make_it_NULL();
    printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\n\n                             WELCOME TO HOSPITAL MANAGEMENT SYSTEM                        \n");
    printf("\n                                MEDICITY HOSPITAL, SHAHJAHANPUR                     \n");
    do
    {
        total_cases = Normal + Emergency;
        printf("\n\nTotal number of consultations in OPD = %d\nTotal number of active cases = %d\nTotal Number of Emergency = %d\n", Normal, total_cases, Emergency);
        printf("\n\nProceed below for Appointment Booking... :)                 ");
        printf("\n\nPress 1 : Patient's admission\nPress 2 : Doctor's Entry\nPress 3 : Status\nPress 4 : exit\nEnter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Welcome to patient's admission portal: ");
            pat_entry_doctor();
            break;
        case 2:
            printf("Welcome to Medicity hospital\n");
            printf("Enter your name Doctor\n");
            scanf("%s", g);
            new_doctor_entry(g);
            break;
        case 3:
            printf("Enter patient's id:\n");
            struct pa_node *coun_pa, *patient;
            scanf("%x", &patient);
            printf("\nPatient's Name :%s\nGender :%s\nMobile number :%s\nEmail:%s\n DOB :%s \nDoctor :%s\nDoctor's id:%x\n", patient->name, patient->gender, patient->mobile, patient->email,
                   patient->year, patient->doctor_visit, patient->doctor);
            p = patient->doctor;
            coun_pa = p->pat1;
            int m = 0;
            while (coun_pa != patient && p != NULL && p->pat1 != NULL)
            {
                coun_pa = coun_pa->pat1;

                m++;
            }
            printf("Token number %d\n", m);
            break;
        case 4:
            printf("Have a great day!!!..\n");
            break;
         
        case 5:  
            printf("Hello doc...I'm Assistant.. How may I help you??\n");
            int dec = 0;
            do
            {
                printf("\n1:Consultation completion\n2:remaining number\n3:patient log for remaining patients\n4:exit");
                scanf("%d", &dec);
                printf("Enter id\n");
                scanf("%x", &temp);
                switch (dec)
                {
                case 1:
                    delete(temp);
                    Normal--;
                    break;

                case 2:
                    doc_status(temp);
                    break;
                case 3:
                    patient_log(temp);
                    break;
                case 4:
                    printf("Thank ayou!! Visit again...\n");
                    break;
                }
            } while (dec != 4);
        }
    } while (choice != 4);
    
    return 0;
}