#include "tay_nguyen_campaign.h"

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

const int MAX_LINES = 5;         
const int MAX_LINE_LENGTH = 100;

// Task 0: Read input file ////////////////////////////////////////////////////////////////////////
bool readFile(
    const string &filename,
    int LF1[], int LF2[],
    int &EXP1, int &EXP2,
    int &T1, int &T2, int &E)
{
  char data[MAX_LINES][MAX_LINE_LENGTH];
  int numLines = 0;

  ifstream ifs(filename);
  if (!ifs.is_open())
  {
    return false;
  }

  while (numLines < MAX_LINES && ifs.getline(data[numLines], MAX_LINE_LENGTH))
  {
    numLines++;
  }
  ifs.close();

  if (numLines < MAX_LINES)
  {
    return false;
  }

  // TODO: Extract values from the `data` array and store them in respective variables
  
  // Parse LF1
  string line = data[0];
  line.erase(line.find('['), 1); // Remove '['
  line.erase(line.find(']'), 1); // Remove ']'
  stringstream ss1(line);
  for (int i = 0; i < 17; i++)
  {
      string token;
      getline(ss1, token, ',');
      LF1[i] = stoi(token);
      LF1[i] = max(0, min(LF1[i], 1000)); // Adjust value if out of range
  }

  // Parse LF2
  line = data[1];
  line.erase(line.find('['), 1); // Remove '['
  line.erase(line.find(']'), 1); // Remove ']'
  stringstream ss2(line);
  for (int i = 0; i < 17; i++)
  {
      string token;
      getline(ss2, token, ',');
      LF2[i] = stoi(token);
      LF2[i] = max(0, min(LF2[i], 1000)); // Adjust value if out of range
  }

  // Parse EXP1 and EXP2
  stringstream ss3(data[2]);
  ss3 >> EXP1 >> EXP2;
  EXP1 = max(0, min(EXP1, 600)); // Adjust value if out of range
  EXP2 = max(0, min(EXP2, 600)); // Adjust value if out of range

  // Parse T1 and T2
  stringstream ss4(data[3]);
  ss4 >> T1 >> T2;
  T1 = max(0, min(T1, 3000)); // Adjust value if out of range
  T2 = max(0, min(T2, 3000)); // Adjust value if out of range

  // Parse E
  stringstream ss5(data[4]);
  ss5 >> E;
  E = max(0, min(E, 99)); // Adjust value if out of range

  return true;
}

// Check range
void checkLF(int &val){
  if(val > 1000) val = 1000;
  if(val < 0) val = 0;
}

void checkT(int &val){
  if (val > 3000) val = 3000;
  if (val < 0) val = 0;
}

void checkE (int E){
  if (E < 0 && E > 99)
    cout << "Invalid event code";
}

// Task 1 ////////////////////////////////////////////////////////////////////////
int gatherForces(int LF1[], int LF2[])
{
  int inputSize = 17;
  // TODO: Implement this function
  int id[17] = {1, 2, 3, 4, 5, 7, 8, 9, 10, 12, 15, 18, 20, 30, 40, 50, 70};
  int sum = 0;
  int sum_LF1 = 0, sum_LF2 = 0;

  for (int i = 0; i < inputSize; i++){
    sum_LF1 += LF1[i] * id[i];
  }

  for (int i = 0; i < inputSize; i++){
    sum_LF2 += LF2[i] * id[i];
  }
  
  sum = sum_LF1 + sum_LF2;

  return sum;
}

// Task 2 ////////////////////////////////////////////////////////////////////////
// Task 2.1 ////////////////////////////////////////////////////////////////////////
int max(const int a, const int b, const int c) {
  int max = a;
  if (b > max) max = b;
  if (c > max) max = c;
  return max;
}

bool isDigit(const char c) {
  return (c >= '0' && c <= '9');
}

string determineRightTarget(const string &target)
{
  // TODO: Implement this function
  string result;
  // String extraction
  int num = 0;
  bool isNum = false;
  int arr[3] = {};
  int pos = 0;
  int digitCount = 0;
  for (int i = 0; i <= target.length(); i++) {
      if (isDigit(target[i])) {
          num = num * 10 + (target[i] - '0');
          isNum = true;
      } else if (isNum) {
          arr[pos] = num;
          pos++;
          digitCount++;
          num = 0;
          isNum = false;
      }
  }

  // Case 1 num
  if (digitCount == 1) {
      if (arr[0] < 3) {
          result =  "DECOY";
      }
      if (arr[0] == 3) {
          result = "Buon Ma Thuot";
      }
      if (arr[0] == 4) {
          result = "Duc Lap";
      }
      if (arr[0] == 5) {
          result = "Dak Lak";
      }
      if (arr[0] == 6) {
          result = "National Route 21";
      }
      if (arr[0] == 7) {
          result = "National Route 14";
      }
      if (arr[0] > 7) {
          result = "INVALID";
      }
  }

  // Case 2 num
  if (digitCount == 2) {
      int ID2 = ((arr[0] + arr[1]) % 5) + 3;
      if (ID2 == 3) {
          result = "Buon Ma Thuot";
      }
      if (ID2 == 4) {
          result = "Duc Lap";
      }
      if (ID2 == 5) {
          result = "DakLak";
      }
      if (ID2 == 6) {
          result = "National Route 21";
      }
      if (ID2 == 7) {
          result = "National Route 14";
      }
  }

  // Case 3 num
  if (digitCount == 3) {
      int ID3 = (max(arr[0],arr[1], arr[2]) % 5) + 3;
      // Real target
      if (ID3 == 3) {
          result = "Buon Ma Thuot";
      }
      if (ID3 == 4) {
          result = "Duc Lap";
      }
      if (ID3 == 5) {
          result = "DakLak";
      }
      if (ID3 == 6) {
          result = "National Route 21";
      }
      if (ID3 == 7) {
          result = "National Route 14";
      }
  }

  // More than 3 num or less than 1 num
  if (digitCount > 3 || digitCount < 1 ) {
      result = "INVALID";
  }

  // RESULT string
  return result;
}


// Task 2.2 ////////////////////////////////////////////////////////////////////////
bool isValidString (const string &input) {
  for (char c : input) {
      if ((c >= '0' && c <= '9') ||
          (c >= 'A' && c <= 'Z') ||
          (c >= 'a' && c <= 'z') ||
          (c == ' ')) {
          return true;
      }
  }
  return false;
}

string cipher(const string &message, int EXP1, int EXP2) {
  string result = message;

  // Check if string has valid char
  if (!isValidString(message)) {
      return "INVALID";
  }

  // Process the string
  const int shift = (EXP1 + EXP2) % 26;

  const size_t n = message.length();

  for (int i = 0; i < n; i++) {
      char &c = result[i];
      if (c >= 'A' && c <= 'Z') {
          c = (c - 'A' + shift) % 26 + 'A';
      }
      if (c >= 'a' && c <= 'z') {
          c = (c - 'a' + shift) % 26 + 'a';
      }
  }
  return result;
}

void swapChar (char &a, char &b) {
  const char temp = a;
  a = b;
  b = temp;
}

string reversed(const string &message) {
  string result = message;
  // Check if string has valid char
  if (!isValidString(message)) {
      result = "INVALID";
  }

  // Reverse the string
  const size_t n = result.length();

  for (int i = 0; i < n / 2; i++) {
      swap(result[i], result[n - i - 1]);
  }
  return result;
}

string toLowerCase (const string &input) {
  string result = input;
  for (char &c : result) {
      if (c >= 'A' && c <= 'Z') {
          c = c + ('a' - 'A');
      }
  }
  return result;
}

bool isSameTarget (const string &target, const string &message) {
  return toLowerCase(target) == toLowerCase(message);
}

string decodeTarget(const string &message, int EXP1, int EXP2)
{
  // TODO: Implement this function
  string targetList[] = {"Duc Lap", "Buon Ma Thuot", "Dak Lak", "National Route 21", "National Route 14"};
  string result = message;
  if (EXP1 >= 300 && EXP2 >= 300) {
      result = cipher(message, EXP1, EXP2);
  }
  if (EXP1 < 300 || EXP2 < 300) {
      result = reversed(message);
  }

  // Check if message is align with target
  for (int i = 0; i < sizeof(targetList) / sizeof(targetList[0]); i++) {
      if (isSameTarget(targetList[i], result)) {
          return targetList[i];
      }
  }
  return "INVALID";
}

// Task 3 ////////////////////////////////////////////////////////////////////////
void manageLogistics(int LF1, int LF2, int EXP1, int EXP2, int &T1, int &T2, int E)
{
    // TODO: Implement this function
    if (E == 0) {
      double total = T1 + T2;
      double ratio = static_cast<double>(LF1) / (LF1 + LF2);
      double expFactor = 1 + static_cast<double>(EXP1 - EXP2) / 100.0;
      double deltaT1 = ratio * total * expFactor;
      double deltaT2 = total - deltaT1;

      // Update T1 and T2 with ceiling and clamping
      T1 = static_cast<int>(ceil(T1 + deltaT1));
      T2 = static_cast<int>(ceil(T2 + deltaT2));
    }
    if (E >= 1 && E <= 9) {
      T1 = static_cast<int>(ceil(T1 * (1.0 - E * 0.01)));
      T2 = static_cast<int>(ceil(T2 * (1.0 - E * 0.005)));
    }
    if (E >= 10 && E <= 29) {
        T1 = T1 + (E * 50);
        T2 = T2 + (E * 50);
    }
    if (E >= 30 && E <= 59) {
      T1 = static_cast<int>(ceil(T1 * (1.0 + E * 0.005)));
      T2 = static_cast<int>(ceil(T2 * (1.0 + E * 0.002)));
    }
    checkT(T1);
    checkT(T2);
}

// Task 4 ////////////////////////////////////////////////////////////////////////

int planAttack(int LF1, int LF2, int EXP1, int EXP2, int T1, int T2, int battleField[10][10])
{
    // TODO: Implement this function
    double initS = (LF1 + LF2) + (EXP1 + EXP2) * 5 + (T1 + T2) * 2;

    for (int i = 0; i < 10; i += 2) {
        for (int j = 0; j < 10; j++) {
            initS -= (battleField[i][j] * 2) / 3.0;
        }
    }

    for (int i = 1; i < 10; i += 2) {
       for (int j = 0; j < 10; j++) {
           initS -= (battleField[i][j] * 3) / 2.0;
       }
    }

    return static_cast<int>(ceil(initS));
}

// Task 5 ////////////////////////////////////////////////////////////////////////
void flattenArr(int supply[][5], int flatten[], int rows, int cols) {
  int index = 0;
  for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
          flatten[index++] = supply[i][j];
      }
  }
}

void sortArr (int arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
      for (int j = 0; j < size - i - 1; j++) {
          if (arr[j] > arr[j + 1]) {
              // Swap arr[j] and arr[j + 1]
              int temp = arr[j];
              arr[j] = arr[j + 1];
              arr[j + 1] = temp;
          }
      }
  }
}

int resupply(int shortfall, int supply[5][5])
{
  // TODO: Implement this function
  // flatten the matrix
  int flatten[25];
  flattenArr(supply, flatten, 5, 5);

  // sort the flattened array
  sortArr(flatten, 25);

  // Find the smallest sum
  int smallestSum = 3000;

  int left = 0;
  int right = 4; 

  while (right < 25) {
      int sum = 0;
      for (int i = left; i <= right; i++) {
          sum += flatten[i];
      }

      if (sum >= shortfall) {
          smallestSum = min(smallestSum, sum);

          left++;
          if (left > right) {
              right++;
          }
      } else {
          right++;
      }
  }

  return smallestSum;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
