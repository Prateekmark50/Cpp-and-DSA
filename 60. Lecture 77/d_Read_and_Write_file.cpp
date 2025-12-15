// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main() {
//     vector<int> numbers;
//     int num;

//     // Open input file
//     ifstream fin;
//     fin.open("homework.txt");

//     // Read numbers from input.txt
//     while (fin >> num) {
//         numbers.push_back(num);
//     }

//     for(int i = 0; i < numbers.size(); i++){
//         cout << numbers[i] << " ";
//     }
//     fin.close();

//     // Sort the numbers
//     sort(numbers.begin(), numbers.end());

//     // Write sorted numbers to output.txt
//     ofstream fout;
//     fout.open("homework.txt");
//     fout << "Sorted Numbers:\n";
//     for (int i = 0; i < numbers.size(); i++) {
//         fout << numbers[i] << " ";
//     }
//     fout.close();
// }

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> original;
    int num;

    // Step 1: Read numbers from file
    ifstream fin("homework.txt");
    if (!fin) {
        cerr << "Error: Cannot open homework.txt for reading.\n";
        return 1;
    }

    while (fin >> num) {
        original.push_back(num);
    }
    fin.close();

    // Step 2: Create a copy for sorting
    vector<int> sorted = original;
    sort(sorted.begin(), sorted.end());

    // Step 3: Overwrite the same file with both original and sorted data
    ofstream fout("homework.txt");
    if (!fout) {
        cerr << "Error: Cannot open homework.txt for writing.\n";
        return 1;
    }

    fout << "Original Numbers:\n";
    for (int i = 0; i < original.size(); i++) {
        fout << original[i] << " ";
    }

    fout << "\nSorted Numbers:\n";
    for (int i = 0; i < sorted.size(); i++) {
        fout << sorted[i] << " ";
    }

    fout.close();

    cout << "File updated with original and sorted numbers.\n";
    return 0;
}
