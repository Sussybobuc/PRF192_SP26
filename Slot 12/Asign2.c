#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN  50
#define MAX_RECORDS   100

/* ─────────────────────────────────────────────
   Function Prototypes  (exactly as in the image)
───────────────────────────────────────────── */
void addStudent(const char *filename);
void displayStudents(const char *filename);
void searchStudentById(const char *filename, int id);
void searchStudentByLastName(const char *filename, const char *lastName);
void sortStudentsByLastName(const char *filename);

/* ═══════════════════════════════════════════════════════════════
   INTERNAL HELPERS
═══════════════════════════════════════════════════════════════ */

/* Load every record from the file into arr[].
   Returns the number of records loaded (0 if file doesn't exist). */
static int loadStudents(const char *filename,
                        int ids[], char firstNames[][MAX_NAME_LEN],
                        char lastNames[][MAX_NAME_LEN], float gpas[])
{
    FILE *fp = fopen(filename, "r");
    if (!fp) return 0;          /* file may not exist yet – that is fine */

    int count = 0;
    while (count < MAX_RECORDS &&
           fscanf(fp, "%d,%49[^,],%49[^,],%f\n",
                  &ids[count],
                  firstNames[count],
                  lastNames[count],
                  &gpas[count]) == 4)
    {
        count++;
    }
    fclose(fp);
    return count;
}

/* Write the whole array back to the file (overwrites). */
static int saveStudents(const char *filename,
                        int ids[], char firstNames[][MAX_NAME_LEN],
                        char lastNames[][MAX_NAME_LEN], float gpas[],
                        int count)
{
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("[ERROR] Cannot open '%s' for writing.\n", filename);
        return -1;
    }
    for (int i = 0; i < count; i++)
        fprintf(fp, "%d,%s,%s,%.2f\n",
                ids[i], firstNames[i], lastNames[i], gpas[i]);
    fclose(fp);
    return 0;
}

/* Formatted table helpers */
static void printDivider(void) {
    printf("+--------+--------------------+--------------------+-------+\n");
}
static void printHeader(void) {
    printDivider();
    printf("| %-6s | %-18s | %-18s | %-5s |\n",
           "ID", "First Name", "Last Name", "GPA");
    printDivider();
}
static void printRow(int id, const char *fn, const char *ln, float gpa) {
    printf("| %-6d | %-18s | %-18s | %-5.2f |\n", id, fn, ln, gpa);
}

/* ══════════════════════════════════════════════════════════��════
   STAGE 1 – Basic Functionality
═══════════════════════════════════════════════════════════════ */

/* ── addStudent ────────────────────────────────────────────── */
void addStudent(const char *filename)
{
    int   ids[MAX_RECORDS];
    char  firstNames[MAX_RECORDS][MAX_NAME_LEN];
    char  lastNames [MAX_RECORDS][MAX_NAME_LEN];
    float gpas[MAX_RECORDS];

    int count = loadStudents(filename, ids, firstNames, lastNames, gpas);

    if (count >= MAX_RECORDS) {
        printf("[ERROR] Maximum student capacity (%d) reached.\n", MAX_RECORDS);
        return;
    }

    int   newId;
    char  newFirst[MAX_NAME_LEN], newLast[MAX_NAME_LEN];
    float newGpa;

    printf("\n--- Add New Student ---\n");

    /* ID */
    printf("  Enter Student ID   : ");
    if (scanf("%d", &newId) != 1) {
        printf("[ERROR] Invalid ID.\n");
        while (getchar() != '\n');
        return;
    }
    /* Duplicate-ID guard */
    for (int i = 0; i < count; i++) {
        if (ids[i] == newId) {
            printf("[WARNING] Student with ID %d already exists.\n", newId);
            while (getchar() != '\n');
            return;
        }
    }

    /* First name */
    printf("  Enter First Name   : ");
    if (scanf("%49s", newFirst) != 1) {
        printf("[ERROR] Invalid first name.\n");
        while (getchar() != '\n');
        return;
    }

    /* Last name */
    printf("  Enter Last Name    : ");
    if (scanf("%49s", newLast) != 1) {
        printf("[ERROR] Invalid last name.\n");
        while (getchar() != '\n');
        return;
    }

    /* GPA */
    printf("  Enter GPA (0.0 – 4.0): ");
    if (scanf("%f", &newGpa) != 1 || newGpa < 0.0f || newGpa > 4.0f) {
        printf("[ERROR] GPA must be between 0.0 and 4.0.\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');   /* flush trailing newline */

    /* Append */
    ids[count]  = newId;
    strcpy(firstNames[count], newFirst);
    strcpy(lastNames [count], newLast);
    gpas[count] = newGpa;
    count++;

    if (saveStudents(filename, ids, firstNames, lastNames, gpas, count) == 0)
        printf("[SUCCESS] Student %s %s (ID: %d) added successfully.\n",
               newFirst, newLast, newId);
}

/* ── displayStudents ───────────────────────────────────────── */
void displayStudents(const char *filename)
{
    int   ids[MAX_RECORDS];
    char  firstNames[MAX_RECORDS][MAX_NAME_LEN];
    char  lastNames [MAX_RECORDS][MAX_NAME_LEN];
    float gpas[MAX_RECORDS];

    int count = loadStudents(filename, ids, firstNames, lastNames, gpas);

    printf("\n--- Student List ---\n");
    if (count == 0) {
        printf("  No student records found.\n");
        return;
    }

    printHeader();
    for (int i = 0; i < count; i++)
        printRow(ids[i], firstNames[i], lastNames[i], gpas[i]);
    printDivider();
    printf("  Total records: %d\n", count);
}

/* ═══════════════════════════════════════════════════════════════
   STAGE 2 – Search Operations
═══════════════════════════════════════════════════════════════ */

/* ── searchStudentById ─────────────────────────────────────── */
void searchStudentById(const char *filename, int id)
{
    int   ids[MAX_RECORDS];
    char  firstNames[MAX_RECORDS][MAX_NAME_LEN];
    char  lastNames [MAX_RECORDS][MAX_NAME_LEN];
    float gpas[MAX_RECORDS];

    int count = loadStudents(filename, ids, firstNames, lastNames, gpas);

    printf("\n--- Search by ID: %d ---\n", id);
    int found = 0;

    for (int i = 0; i < count; i++) {
        if (ids[i] == id) {
            printHeader();
            printRow(ids[i], firstNames[i], lastNames[i], gpas[i]);
            printDivider();
            found = 1;
            break;          /* IDs are unique */
        }
    }

    if (!found)
        printf("  No student found with ID %d.\n", id);
}

/* ── searchStudentByLastName ───────────────────────────────── */
void searchStudentByLastName(const char *filename, const char *lastName)
{
    int   ids[MAX_RECORDS];
    char  firstNames[MAX_RECORDS][MAX_NAME_LEN];
    char  lastNames [MAX_RECORDS][MAX_NAME_LEN];
    float gpas[MAX_RECORDS];

    int count = loadStudents(filename, ids, firstNames, lastNames, gpas);

    printf("\n--- Search by Last Name: \"%s\" ---\n", lastName);
    int found = 0;

    for (int i = 0; i < count; i++) {
        /* Case-insensitive comparison */
        char a[MAX_NAME_LEN], b[MAX_NAME_LEN];
        strncpy(a, lastNames[i], MAX_NAME_LEN - 1); a[MAX_NAME_LEN-1] = '\0';
        strncpy(b, lastName,     MAX_NAME_LEN - 1); b[MAX_NAME_LEN-1] = '\0';

        for (int k = 0; a[k]; k++) if (a[k]>='A'&&a[k]<='Z') a[k]+=32;
        for (int k = 0; b[k]; k++) if (b[k]>='A'&&b[k]<='Z') b[k]+=32;

        if (strcmp(a, b) == 0) {
            if (!found) printHeader();
            printRow(ids[i], firstNames[i], lastNames[i], gpas[i]);
            found++;
        }
    }

    if (found) {
        printDivider();
        printf("  %d match(es) found.\n", found);
    } else {
        printf("  No student found with last name \"%s\".\n", lastName);
    }
}

/* ═══════════════════════════════════════════════════════════════
   STAGE 3 – Sorting Functionality
═══════════════════════════════════════════════════════════════ */

/* ── sortStudentsByLastName ────────────────────────────────── */
void sortStudentsByLastName(const char *filename)
{
    int   ids[MAX_RECORDS];
    char  firstNames[MAX_RECORDS][MAX_NAME_LEN];
    char  lastNames [MAX_RECORDS][MAX_NAME_LEN];
    float gpas[MAX_RECORDS];

    int count = loadStudents(filename, ids, firstNames, lastNames, gpas);

    if (count == 0) {
        printf("\n  No student records to sort.\n");
        return;
    }

    /* ── Bubble Sort (ascending by last name) ── */
    for (int i = 0; i < count - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(lastNames[j], lastNames[j+1]) > 0) {
                /* Swap IDs */
                int tmpId    = ids[j];
                ids[j]       = ids[j+1];
                ids[j+1]     = tmpId;
                /* Swap first names */
                char tmpName[MAX_NAME_LEN];
                strcpy(tmpName,        firstNames[j]);
                strcpy(firstNames[j],  firstNames[j+1]);
                strcpy(firstNames[j+1],tmpName);
                /* Swap last names */
                strcpy(tmpName,       lastNames[j]);
                strcpy(lastNames[j],  lastNames[j+1]);
                strcpy(lastNames[j+1],tmpName);
                /* Swap GPAs */
                float tmpGpa = gpas[j];
                gpas[j]      = gpas[j+1];
                gpas[j+1]    = tmpGpa;

                swapped = 1;
            }
        }
        if (!swapped) break;    /* early-exit optimisation */
    }

    /* Save sorted order back to file */
    if (saveStudents(filename, ids, firstNames, lastNames, gpas, count) == 0)
        printf("[SUCCESS] Records sorted by last name and saved.\n");
}

/* ═══════════════════════════════════════════════════════════════
   STAGE 4 – Menu & Error Handling
   Structure matches the image exactly:
     do-while  +  switch  +  system("pause")
═══════════════════════════════════════════════════════════════ */

int main()
{
    const char *filename = "students.txt";
    int  choice, id;
    char lastName[MAX_NAME_LEN];

    do {
        /* ── Menu (matches image lines 21-27) ── */
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Search Student by ID\n");
        printf("3. Search Student by Last Name\n");
        printf("4. Display Students Sorted by Last Name\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        /* ── Input guard ── */
        if (scanf("%d", &choice) != 1) {
            printf("[ERROR] Invalid input. Please enter a number (1-5).\n");
            while (getchar() != '\n');  /* flush bad input */
            choice = 0;                 /* force loop to continue */
            continue;
        }
        while (getchar() != '\n');      /* flush trailing newline */

        /* ── Switch (matches image lines 30-53) ── */
        switch (choice) {
            case 1:
                addStudent(filename);
                break;

            case 2:
                printf("Enter Student ID to search: ");
                if (scanf("%d", &id) == 1) {
                    while (getchar() != '\n');
                    searchStudentById(filename, id);
                } else {
                    printf("[ERROR] Invalid ID input.\n");
                    while (getchar() != '\n');
                }
                break;

            case 3:
                printf("Enter Last Name to search: ");
                if (scanf("%49s", lastName) == 1) {
                    while (getchar() != '\n');
                    searchStudentByLastName(filename, lastName);
                } else {
                    printf("[ERROR] Invalid input.\n");
                    while (getchar() != '\n');
                }
                break;

            case 4:
                sortStudentsByLastName(filename);   /* sort first … */
                displayStudents(filename);          /* … then display */
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 5);

    system("pause");    /* matches image line 56 */
    return 0;
}