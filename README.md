# Codtech-internship-Advanced-Task4
# Run-Length Encoding (RLE) Compression Program

## Overview
This program implements a **Run-Length Encoding (RLE)** compression algorithm in C. RLE is a simple form of data compression where consecutive repeated characters (runs) are replaced by a single character and its count. This program allows users to **compress** and **decompress** text data using RLE, helping to reduce the size of text files with repetitive characters.

## Features
- **Compression**: Converts a given string or file into a compressed format using the RLE algorithm.
- **Decompression**: Restores the original string or file from its compressed RLE format.
- **File Handling**: Supports file reading and writing for both compression and decompression.
- **Menu-Driven Interface**: A user-friendly interface that prompts the user to choose between compression or decompression options.

---

## Instructions

### **Menu Options**:
The program provides a menu with the following options:
- **1. Compress File**: Compresses a text file using the RLE algorithm and writes the compressed data to a new file.
- **2. Decompress File**: Decompresses a previously compressed RLE file and restores the original text.
- **3. Exit**: Exits the program.

### **Input Format**:
- For **compression**, the program accepts an input text file containing the data to be compressed.
- For **decompression**, the program accepts a compressed RLE file.

### **RLE Compression**:
In RLE compression, consecutive repeating characters are stored as a single character followed by the count of repetitions. For example:
- Input: `AAABBBCCCC`
- Output: `3A3B4C`

### **RLE Decompression**:
In RLE decompression, the program reads the character and its count from the compressed file and reconstructs the original text. For example:
- Input (Compressed): `3A3B4C`
- Output (Decompressed): `AAABBBCCCC`

---

## How to Use
1. **Compress a File**:
   - Select option `1` to compress a text file.
   - Provide the **input file** and the **output file** where the compressed data will be saved.
   - The program will compress the contents of the input file and save the result in the output file.

2. **Decompress a File**:
   - Select option `2` to decompress a file.
   - Provide the **input compressed file** and the **output file** where the decompressed data will be saved.
   - The program will decompress the data and restore it to its original form.

3. **Exit**:
   - Select option `3` to exit the program.

---

## Compilation and Execution
1. Save the program code in a file named `rle_compression.c`.
2. Open a terminal and compile the program:
   ```bash
   gcc rle_compression.c -o rle_compression
   ```
3. Run the program:
   ```bash
   ./rle_compression
   ```

---

## Sample Screenshots

### **Main Menu**
The user is prompted with a menu to choose between compression or decompression.

![Main Menu Screenshot](https://via.placeholder.com/600x200.png?text=Main+Menu+Example)

### **Compressing a File**
Input Example:  
```
Enter the name of the file to compress: input.txt
Enter the name of the output compressed file: compressed.txt
```

Output:
```
Compression successful! Compressed data saved to compressed.txt
```

### **Decompressing a File**
Input Example:
```
Enter the name of the file to decompress: compressed.txt
Enter the name of the output decompressed file: decompressed.txt
```

Output:
```
Decompression successful! Decompressed data saved to decompressed.txt
```

---

## Code Walkthrough

1. **Main Program Flow**:
   - The program displays a menu and takes user input to select the desired operation (compression or decompression).
   - Based on the user's choice, the program calls either the **compress()** or **decompress()** function to process the input file.

2. **Compression Function**:
   - **compress()**: This function reads the input file, processes the data character by character, and encodes consecutive characters as their counts followed by the character itself. It then writes the compressed data to the output file.

3. **Decompression Function**:
   - **decompress()**: This function reads the compressed file, decodes the character and count pairs, and reconstructs the original string. It then writes the decompressed data to the output file.

4. **Error Handling**:
   - The program checks for common errors such as file not found, empty files, and invalid file formats, ensuring smooth user experience.

---

## Example

### **Compression**:
- Input text: `"AAAABBBCCCCDDDD"`
- Compressed output: `"4A3B4C4D"`

### **Decompression**:
- Compressed input: `"4A3B4C4D"`
- Decompressed output: `"AAAABBBCCCCDDDD"`

---

## Future Enhancements
1. **Support for Binary Files**: Extend the program to compress and decompress binary files, not just text files.
2. **Improved File Handling**: Handle large files more efficiently by processing them in chunks instead of reading the entire file at once.
3. **Error Handling**: Enhance error handling for edge cases such as file permissions, corrupted files, and invalid inputs.

---

## License
This project is released under the MIT License.

---

## Contributions
Feel free to contribute by submitting pull requests, issues, or suggestions.

---


This **README** provides an overview of the **Run-Length Encoding (RLE) Compression** program, its functionality, and the usage instructions. Feel free to modify or expand the README as per your project requirements.
