Codeforces style:
```cpp
GENERATE_OUTPUT = false;
SEPERATE_EACH_TEST = false;
STRESS_TEST = false;
```
VNOJ style (or DMOJ or other CSM styles):
```cpp
GENERATE_OUTPUT = true;
SEPERATE_EACH_TEST = true;
STRESS_TEST = false;
```
Stress test (between only two solutions of the same name):
```cpp
STRESS_TEST = true;
const vector<string> STRESS_TEST_SOLUTIONS = {
    FILENAME
};
```
Stress test (between multiple solutions):
```cpp
STRESS_TEST = true;
const vector<string> STRESS_TEST_SOLUTIONS = {
    solutionName1,
    solutionName2,
    ... // Add more strings of solution names here
};
```
Stress test (only stress test, don't generate test cases):
```cpp
STRESS_TEST = true;
bool STRESS_TEST_FORCE_STOP = true;
bool STRESS_TEST_KEEP_WA_TEST_ONLY = true;
```
Stress test (keep WA tests only, put WA outputs into each test folder):
```cpp
STRESS_TEST = true;
bool STRESS_TEST_MOVE_WA_OUTPUT_TO_DIRECTORY = true;
bool STRESS_TEST_KEEP_WA_TEST_ONLY = true;
```
Stress test (Write out report about stress test results in each test case):
```cpp
STRESS_TEST = true;
bool STRESS_TEST_WRITE_REPORT = true;
```


Example: ![[Frame 18.png]]