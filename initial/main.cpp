/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2025
* Date: 07.02.2025
*/

//The library here is concretely set, students are not allowed to include any other libraries.

#include "tay_nguyen_campaign.h"

using namespace std;

void tnc_tc_01() {
    cout << "----- Sample Testcase 01 -----" << endl;
    string input_file("tnc_tc_01_input");
    int LF1[17], LF2[17], EXP1, EXP2, T1, T2, E;
    if (!readFile(input_file, LF1, LF2, EXP1, EXP2, T1, T2, E)) {
        return;
    }

    cout << "LF1[0]: " << LF1[0] << ", LF2[0]: " << LF2[0] << endl;
    int result = gatherForces(LF1, LF2);
    cout << "Result: " << result << endl;
}

void testcase(){
    cout << "----- Sample Testcase 01 -----" << endl;
{
  string input_file("tnc_tc_01_input");
  int LF1[17], LF2[17], EXP1, EXP2, T1, T2, E;

  if (!readFile(input_file, LF1, LF2, EXP1, EXP2, T1, T2, E))
  {
    cout << "Error: Could not read file." << endl;
    return;
  }

  // Print all elements of LF1
  cout << "LF1: ";
  for (int i = 0; i < 17; i++)
    cout << LF1[i] << " ";
  cout << endl;

  // Print all elements of LF2
  cout << "LF2: ";
  for (int i = 0; i < 17; i++)
    cout << LF2[i] << " ";
  cout << endl;

  // Print other values
  cout << "EXP1: " << EXP1 << ", EXP2: " << EXP2 << endl;
  cout << "T1: " << T1 << ", T2: " << T2 << endl;
  cout << "E: " << E << endl;
}
}

void testcase2() {
    // Testcase 2
cout << "----- Sample Testcase 02 -----" << endl;
{
  string input_file("tnc_tc_01_input");
  int LF1[17], LF2[17], EXP1, EXP2, T1, T2, E;

  if (!readFile(input_file, LF1, LF2, EXP1, EXP2, T1, T2, E))
  {
    cout << "Error: Could not read file." << endl;
    return;
  }

  // Print all elements of LF1
  cout << "LF1: ";
  for (int i = 0; i < 17; i++)
    cout << LF1[i] << " ";
  cout << endl;

  // Print all elements of LF2
  cout << "LF2: ";
  for (int i = 0; i < 17; i++)
    cout << LF2[i] << " ";
  cout << endl;

  // Print other values
  cout << "EXP1: " << EXP1 << ", EXP2: " << EXP2 << endl;
  cout << "T1: " << T1 << ", T2: " << T2 << endl;
  cout << "E: " << E << endl;

  // Test gatherForces
  int result = gatherForces(LF1, LF2);
  cout << "Result: " << result << endl;
}
}

int main(int argc, const char * argv[]) {
    tnc_tc_01();
    //testcase2();

    return 0;
}
