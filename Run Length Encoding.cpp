#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void compressFile(const char* inputFileName, const char* outputFileName);
void decompressFile(const char* inputFileName, const char* outputFileName);

int main() {
    int choice;
    char inputFile[100], outputFile[100];

    printf("Run-Length Encoding (RLE) Tool\n");
    printf("------------------------------\n");
    printf("1. Compress a file\n");
    printf("2. Decompress a file\n");
    printf("3. Exit\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the input file name to compress: ");
                scanf("%s", inputFile);
                printf("Enter the output file name for compressed data: ");
                scanf("%s", outputFile);
                compressFile(inputFile, outputFile);
                printf("File compressed successfully.\n");
                break;

            case 2:
                printf("Enter the input file name to decompress: ");
                scanf("%s", inputFile);
                printf("Enter the output file name for decompressed data: ");
                scanf("%s", outputFile);
                decompressFile(inputFile, outputFile);
                printf("File decompressed successfully.\n");
                break;

            case 3:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Function to compress a file using RLE
void compressFile(const char* inputFileName, const char* outputFileName) {
    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "w");
    if (inputFile == NULL || outputFile == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    char currentChar, prevChar;
    int count = 1;

    prevChar = fgetc(inputFile);
    while ((currentChar = fgetc(inputFile)) != EOF) {
        if (currentChar == prevChar) {
            count++;
        } else {
            fprintf(outputFile, "%c%d", prevChar, count);
            prevChar = currentChar;
            count = 1;
        }
    }
    // Write the last character and its count
    fprintf(outputFile, "%c%d", prevChar, count);

    fclose(inputFile);
    fclose(outputFile);
}

// Function to decompress a file using RLE
void decompressFile(const char* inputFileName, const char* outputFileName) {
    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "w");
    if (inputFile == NULL || outputFile == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    char ch;
    int count;

    while (fscanf(inputFile, "%c%d", &ch, &count) == 2) {
        for (int i = 0; i < count; i++) {
            fputc(ch, outputFile);
        }
    }

    fclose(inputFile);
    fclose(outputFile);
}

