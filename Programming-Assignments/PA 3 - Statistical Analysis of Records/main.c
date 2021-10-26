#define _CRT_SECURE_NO_WARNINGS
#include "header.h" // Import header file
#include <stdio.h> // Import standard library
#include <math.h> // Import mathematical library

int main()
{
    FILE* infile = NULL, * outfile = NULL;
    
    int id1 = 0, // Stores the first Student ID read in from a file
        id2 = 0, // Stores the second Student ID read in from a file
        id3 = 0, // Stores the third Student ID read in from a file
        id4 = 0, // Stores the fourth Student ID read in from a file
        id5 = 0, // Stores the fifth Student ID read in from a file
        class1 = 0, // Stores the first class standing read in from a file, to be used in a variety of calculations
        class2 = 0, // Stores the second class standing read in from a file, to be used in a variety of calculations
        class3 = 0, // Stores the third class standing read in from a file, to be used in a variety of calculations
        class4 = 0, // Stores the fourth class standing read in from a file, to be used in a variety of calculations
        class5 = 0, // Stores the fifth class standing read in from a file, to be used in a variety of calculations
        class_sum = 0; // Stores the sum of class standings, to be used in calculating the mean of class standings
    double gpa1 = 0.0, // Stores the first GPA read in from a file
        gpa2 = 0.0, // Stores the second GPA read in from a file
        gpa3 = 0.0, // Stores the third GPA read in from a file
        gpa4 = 0.0, // Stores the fourth GPA read in from a file
        gpa5 = 0.0, // Stores the fifth GPA read in from a file
        age1 = 0.0, // Stores the first age read in from a file
        age2 = 0.0, // Stores the second age read in from a file
        age3 = 0.0, // Stores the third age read in from a file
        age4 = 0.0, // Stores the fourth age read in from a file
        age5 = 0.0, // Stores the fifth age read in from a file
        gpa_sum = 0.0, // Stores the sum of GPA's, to be used in calculating the mean of GPA's
        age_sum = 0.0, // Stores the sum of age's, to be used in calculating the mean of age's
        gpa_mean = 0.0, // Stores the mean of GPA's, to be written to a file
        class_mean = 0.0, // Stores the mean of class standing's, to be written to a file
        age_mean = 0.0, // Stores the mean of age's, to be written to a file
        dev1 = 0.0, // Stores the first deviation, used to calculate variance
        dev2 = 0.0, // Stores the second deviation, used to calculate variance
        dev3 = 0.0, // Stores the third deviation, used to calculate variance
        dev4 = 0.0, // Stores the fourth deviation, used to calculate variance
        dev5 = 0.0, // Stores the fifth deviation, used to calculate variance
        variance = 0.0, // Stores the variance, used to calculate a standard deviation
        std_dev = 0.0, // Stores the standard deviation, to be written to a file
        max = 0.0, // Stores a maximum GPA value, to be written to a file
        min = 0.0; // Stores a minimum GPA value, to be written to a file

    infile = fopen("input.dat", "r"); // Open a file to be processed
    outfile = fopen("output.dat", "w"); // Open a file to be written to

    // The following 20 lines of code process a file
    id1 = read_integer(infile);
    gpa1 = read_double(infile);
    class1 = read_integer(infile);
    age1 = read_double(infile);
    id2 = read_integer(infile);
    gpa2 = read_double(infile);
    class2 = read_integer(infile);
    age2 = read_double(infile);
    id3 = read_integer(infile);
    gpa3 = read_double(infile);
    class3 = read_integer(infile);
    age3 = read_double(infile);
    id4 = read_integer(infile);
    gpa4 = read_double(infile);
    class4 = read_integer(infile);
    age4 = read_double(infile);
    id5 = read_integer(infile);
    gpa5 = read_double(infile);
    class5 = read_integer(infile);
    age5 = read_double(infile);

    gpa_sum = calculate_sum((double)gpa1, (double)gpa2, (double)gpa3, (double)gpa4, (double)gpa5); // Calculate sum of GPA's and store
    class_sum = calculate_sum((int)class1, (int)class2, (int)class3, (int)class4, (int)class5); // Calculate sum of class standing's and store
    age_sum = calculate_sum((double)age1, (double)age2, (double)age3, (double)age4, (double)age5); // Calculate sum of age's and store

    gpa_mean = calculate_mean((double)gpa_sum, (int)5); // Calculate mean of GPA's
    print_double(outfile, (double)gpa_mean); // Write mean of GPA's to a file
    class_mean = calculate_mean((double)class_sum, (int)5); // Calculate mean of class standing's
    print_double(outfile, (double)class_mean); // Write mean of class standing's to a file
    age_mean = calculate_mean((double)age_sum, (int)5); // Calculate mean of age's
    print_double(outfile, (double)age_mean); // Write mean of age's to a file

    dev1 = calculate_deviation((double)gpa1, (double)gpa_mean); // Calculate deviation 1 and store
    dev2 = calculate_deviation((double)gpa2, (double)gpa_mean); // Calculate deviation 2 and store
    dev3 = calculate_deviation((double)gpa3, (double)gpa_mean); // Calculate deviation 3 and store
    dev4 = calculate_deviation((double)gpa4, (double)gpa_mean); // Calculate deviation 4 and store
    dev5 = calculate_deviation((double)gpa5, (double)gpa_mean); // Calculate deviation 5 and store

    variance = calculate_variance((double)dev1, (double)dev2, (double)dev3, (double)dev4, (double)dev5, (int)5); // Calcualte variance and store

    std_dev = calculate_standard_deviation((double)variance); // Calculate standard deviation and store
    print_double(outfile, (double)std_dev); // Write standard devaiation to a file

    min = find_min((double)gpa1, (double)gpa2, (double)gpa3, (double)gpa4, (double)gpa5); // Calculate the minimum GPA
    print_double(outfile, (double)min); // Write minimum GPA to a file
    max = find_max((double)gpa1, (double)gpa2, (double)gpa3, (double)gpa4, (double)gpa5); // Calculate the maximum GPA
    print_double(outfile, (double)max); // Write maximum GPA to a file

    fclose(infile); // Closes the file for reading
    fclose(outfile); // Closes the file for writing

    return 0;
}
