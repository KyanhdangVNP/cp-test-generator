#include <bits/stdc++.h>
#define boostcode ios_base::sync_with_stdio(0); cin.tie(0);
#define openf freopen("BAI1.inp", "r", stdin); freopen("BAI1.out", "w", stdout);
#include <io.h> // To be able to use mkdir()
#include <sys/stat.h> // To check if file exists

using namespace std;
typedef long long ll;

/* || USER SUPPORT's FUNCTIONS || */
// Generate a random number in range between l and r
mt19937_64 rd(time(0));
ll randNum(ll l, ll r) {
    return rd()%(r-l+1) + l;
}





  /*--------------------------------------*/
 /* PUT YOUR GENERATE INPUT CODE BELOW!! */
/*--------------------------------------*/

// This is the generate input code for BAI2 in Phu Yen's Youth Informatics Contest 2024-2025, Division C2
void funcInput(ofstream& inp) {
    int n = randNum(1, 5);
    inp << n << '\n';
    for (int i = 1; i <= n; i++) {
        inp << randNum(1, 5) << ' ' << randNum(1, 20) << '\n';
    }
}

  /*--------------------------------------*/
 /* PUT YOUR GENERATE INPUT CODE ABOVE!! */
/*--------------------------------------*/

/* || USER SETTING & OPTIONS || */
// General test generator information:
const string FILENAME = "BAI2";
const int TEST_START = 1;
const int TEST_END = 20;
const function<void(ofstream& inp)> FUNC_INPUT = funcInput;

// Options to generate input & output tests:
bool GENERATE_OUTPUT = true;
bool SEPERATE_EACH_TEST = false;
const bool PREVENT_IDENTICAL_TESTS = false; // By default: false
// THIS OPTION IS NOT RECOMMENDED SINCE IT DRAMATICALLY SLOWS DOWN THE GENERATING PROCESS
// (With small test cases, set it true. With large test cases, set it false.)
// - Options that has to be careful with:
const bool OVERWRITE_OLD_TESTS = true; // By default: true
const bool CLEAN_ROOT_FOLDER = false; // By default: false

// Options to stress test between two solution files:
bool STRESS_TEST = false;
// - The following options should be all set to false if STRESS_TEST = false to prevent errors:
bool STRESS_TEST_REPEAT_UNTIL_WA = false; // By default: true
bool STRESS_TEST_FORCE_STOP = false; // By default: true
bool STRESS_TEST_WRITE_REPORT = false; // By default: true
bool STRESS_TEST_MOVE_WA_OUTPUT_TO_DIRECTORY = false; // By default: false
bool STRESS_TEST_KEEP_WA_TEST_ONLY = false;
// - Options that has to be careful with:
const bool SHOW_COMPARE_ON_CMD = true; // By default: false




/* || SYSTEM VARIABLES || */
bool stopLoop;

ofstream LOG("LOG.txt");
bool errorFlag;

ofstream inp;
string directory;
string inputFileName, outputFileName;

ofstream stressTestLog;
string solutionOutputFileName;
bool wrongSolutionOutput;


/* || SYSTEM FUNCTIONS || */
// Enables error flag to report to the user at the end of the program
void logError(int test, string line) {
    LOG << "Test " << test << " || " << line << '\n';
    errorFlag = true;
}

// Generates directory path
void generateDirectory(int test, string& directory) {
    if (SEPERATE_EACH_TEST)
        directory = FILENAME+"\\test"+to_string(test)+"\\";
    else
        directory = FILENAME+"\\";
}

// Generates input file's name
void generateInputFileName(int test, string& inputFileName) {
    if (SEPERATE_EACH_TEST)
        inputFileName = FILENAME+".inp";
    else
        inputFileName = "test"+to_string(test)+".inp";
}
// Moves input file
void moveInputFile(int test) {
    generateInputFileName(test, inputFileName);
    if (OVERWRITE_OLD_TESTS)
        remove((directory+inputFileName).c_str()); // Delete old files first before moving new files into
    rename((FILENAME+".inp").c_str(), (directory+inputFileName).c_str()); // Move input file into correct directory
}

// Generates input (.inp) file
void generateInputTest() {
    ofstream inp((FILENAME+".inp").c_str());

    FUNC_INPUT(inp);

    inp.close();
}

inline bool fileExist (const std::string& name) {
    struct stat buffer;
    return (stat (name.c_str(), &buffer) == 0);
}
// Generates output file's name
void generateOutputFileName(int test) {
    if (SEPERATE_EACH_TEST)
        outputFileName = FILENAME+".out";
    else
        outputFileName = "test"+to_string(test)+".out";
}
// Moves output file
void moveOutputFile(int test) {
    generateOutputFileName(test);
    if (OVERWRITE_OLD_TESTS)
        remove((directory+outputFileName).c_str()); // Delete old files first before moving new files into
    rename((FILENAME+".out").c_str(), (directory+outputFileName).c_str()); // Move output file into correct directory
}

// Generates output (.out) file
void generateOutputTest(int test) {
    if (!fileExist(FILENAME+".exe")) {
        logError(test, ".exe file for the solution code doesn't exist!! Output test won't be generated.");
        return;
    }
    system((FILENAME+".exe").c_str());
}


// Generates solution output file's name
void generateSolutionOutputFileName(int test) {
    if (SEPERATE_EACH_TEST)
        solutionOutputFileName = FILENAME+".ans";
    else
        solutionOutputFileName = "test"+to_string(test)+".ans";
}
// Moves solution output file
void moveSolutionOutputFile() {
    if (OVERWRITE_OLD_TESTS)
        remove((directory+solutionOutputFileName).c_str()); // Delete old files first before moving new files into
    rename((FILENAME+".ans").c_str(), (directory+solutionOutputFileName).c_str()); // Move output file into correct directory
}
bool generateSolutionOutput(int test, string solutionFileName) {
    if (!fileExist(solutionFileName)) {
        logError(test, ".exe file for the OTHER solution code doesn't exist!! Stress test process won't be executed.");
        return false;
    }
    system(solutionFileName.c_str());
    return true;
}

// Stress test between two solution files
void stressTest(int test) {
    string solutionFileName = FILENAME+"_test.exe";
    if (!generateSolutionOutput(test, solutionFileName))
        return;

    if (!fileExist(FILENAME+".exe")) {
        logError(test, ".exe file for the solution code doesn't exist!! Stress test process won't be executed.");
        return;
    }
    // Compares result between two generated output files:
    wrongSolutionOutput = false;
    string command = "fc " + (FILENAME+".out") + " " + (FILENAME+".ans");
    if (!SHOW_COMPARE_ON_CMD)
        command += ">nul";
    bool identical = !system(command.c_str());
    if (identical && STRESS_TEST_WRITE_REPORT) {
        stressTestLog << "AC" << '\n';
    } else {
        if (STRESS_TEST_WRITE_REPORT)
            stressTestLog << "WA" << '\n';
        if (STRESS_TEST_MOVE_WA_OUTPUT_TO_DIRECTORY) {
            generateSolutionOutputFileName(test);
            moveSolutionOutputFile();
        }
        wrongSolutionOutput = true;
        if (STRESS_TEST_FORCE_STOP)
            stopLoop = true;
    }
}



// Checks and stops test generating loop if it's true
void stopLoopCheck(int test) {
    // Default configuration:
    if (STRESS_TEST_REPEAT_UNTIL_WA) return;
    if (test > TEST_END) stopLoop = true;
}
// Check and return whether there is identical test to test with given index
bool checkIdenticalTest(int test) {
    for (int i = TEST_START; i < test; i++) {
        string checkDirectory;
        string checkFileName;
        generateDirectory(i, checkDirectory);
        generateInputFileName(i, checkFileName);
        string command = "fc " + (checkDirectory+checkFileName) + " " + (FILENAME+".inp");
        if (!SHOW_COMPARE_ON_CMD)
            command += ">nul";
        bool identical = !system(command.c_str());
        if (identical) return true;
    }
    return false;
}
// Checks and increases the text index by 1
void increaseTestIndex(int& test) {
    if (!(!STRESS_TEST_KEEP_WA_TEST_ONLY ||
        (STRESS_TEST_KEEP_WA_TEST_ONLY && wrongSolutionOutput)))
        return;
    test++;
}
void generateTest(int test) {
    generateDirectory(test, directory);
    mkdir(directory.c_str()); // Create new folder to put test

    generateInputTest();
    if (PREVENT_IDENTICAL_TESTS) {
        while (checkIdenticalTest(test))
            generateInputTest();
    }
    if (GENERATE_OUTPUT)
        generateOutputTest(test);
    if (STRESS_TEST)
        stressTest(test);
    if (!STRESS_TEST_KEEP_WA_TEST_ONLY ||
        (STRESS_TEST_KEEP_WA_TEST_ONLY && wrongSolutionOutput)) {
        moveInputFile(test);
        moveOutputFile(test);
    }
}
// Generates full tests
void generateTests() {

    if (STRESS_TEST_WRITE_REPORT)
        stressTestLog.open("stress_test_log.txt"); //THIS IS NEEDED IN CHECKING OUTPUT RESULTS BETWEEN TWO CODE FILES

    if (CLEAN_ROOT_FOLDER)
        system(("rmdir /s /q " + FILENAME).c_str());

    mkdir(FILENAME.c_str()); // Create tests root folder

    for (int test = TEST_START;;) {
        stopLoopCheck(test);
        if (stopLoop) break;
        generateTest(test);
        increaseTestIndex(test);
    }

    if (STRESS_TEST_WRITE_REPORT)
        stressTestLog.close();
}

int main() {
    boostcode;
    //openf;

    //ofstream OUTPUT("TEST_OUTPUT.out"); //THIS IS NEEDED IN CHECKING OUTPUT RESULTS BETWEEN TWO CODE FILES

    generateTests();

    if (errorFlag)
        cout << "There were errors while generating tests which made some things go wrong (not generating things, stress test not working,...)!\nPlease check detail in LOG.txt!!";

    cout << '\n';

    return 0;
}
