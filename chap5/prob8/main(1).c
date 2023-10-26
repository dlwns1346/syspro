#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;
    char savedText[10][100];
    char buf;
    int lineCount = 0;

    // Open the text file for reading
    file = fopen("test.txt", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    // Read and save each line from the text file
    int row = 0;
    int col = 0;
    while (fread(&buf, 1, 1, file) == 1) {
        if (buf != '\n') {
            savedText[row][col++] = buf;
        } else {
            savedText[row][col] = '\0';
            row++;
            col = 0;
        }
    }
    lineCount = row;
    fclose(file);

    printf("File read success\n");
    printf("Total Line : %d\n", lineCount);
    printf("You can choose 1 ~ %d Line\n", lineCount);

    char input[100];
    int selectedLines[10];  // To store selected line numbers
    int selectedCount = 0;  // To keep track of how many lines are selected

    // Prompt the user for input
    printf("Pls 'Enter' the line to select: ");
    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, ",\n");
    int i;

    while (token != NULL) {
        if (strcmp(token, "*") == 0) {
            // Select all lines
            for (i = 1; i <= lineCount; i++) {
                selectedLines[selectedCount++] = i;
            }
        } else if (strchr(token, '-') != NULL) {
            // Handle range of lines (e.g., n-m)
            int start, end;
            if (sscanf(token, "%d-%d", &start, &end) == 2) {
                for (i = start; i <= end && i <= lineCount; i++) {
                    selectedLines[selectedCount++] = i;
                }
            }
        } else {
            // Handle single line selection
            int line = atoi(token);
            if (line >= 1 && line <= lineCount) {
                selectedLines[selectedCount++] = line;
            }
        }
        token = strtok(NULL, ",\n");
    }

    // Print the selected lines
    for (i = 0; i < selectedCount; i++) {
        int line = selectedLines[i];
        if (line >= 1 && line <= lineCount) {
            printf("%s\n", savedText[line - 1]);
        }
    }

    return 0;
}
