#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int get_student_variant(int number_of_variants, string student_name);

int main() {
    int number_of_variants;
    cout << "Enter the number of variants: ";
    cin >> number_of_variants;

    string student_name;
    cout << "Enter the student name: ";
    cin >> student_name;

    int student_variant = get_student_variant(number_of_variants, student_name);

    cout << "The " << student_name << "'s variant is " << student_variant << endl;

    return 0;
}

int get_student_variant(int number_of_variants, string student_name) {
    return student_name[0] % number_of_variants + 1;
}
