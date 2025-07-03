#include <bits/stdc++.h>
#define boostcode ios_base::sync_with_stdio(0); cin.tie(0);
#define openf freopen("BAI1.inp", "r", stdin); freopen("BAI1.out", "w", stdout);
#include <io.h> // To be able to use mkdir()
#include <sys/stat.h> // To check if file exists

using namespace std;
typedef long long ll;

// || SYSTEM PRE-INITIALIZERS ||
// CONSTANT VARIABLES:
const ll TEST_INFINITY = LONG_LONG_MAX;

// SUBTASK STRUCTURE:
ll SUBTASK_START;
ll SUBTASK_END;
vector<ll> SUBTASK_LIMITS;

struct Subtask {
    ll startIndex, endIndex;
    vector<ll> limits;

    // Default constructor
    Subtask(ll val_startIndex, ll val_endIndex, vector<ll> limits) : startIndex(val_startIndex), endIndex(val_endIndex) {
        addLimits(limits);
    }

    void addLimits(vector<ll> limits) {
        this->limits.insert(this->limits.end(), limits.begin(), limits.end());
    }
};
vector<Subtask> subtasks;

void addSubtask(ll startIndex, ll endIndex, vector<ll> limits) {
    subtasks.push_back(Subtask(startIndex, endIndex, limits));
}
void addSubtask(ll startIndex, ll endIndex) {
    addSubtask(startIndex, endIndex, {});
}





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
const function<void(ofstream& inp)> FUNC_INPUT = funcInput;

// Options to generate input & output tests:
bool GENERATE_OUTPUT = true;
bool SEPERATE_EACH_TEST = true;
const bool PREVENT_IDENTICAL_TESTS = false; // By default: false
// THIS OPTION IS NOT RECOMMENDED SINCE IT DRAMATICALLY SLOWS DOWN THE GENERATING PROCESS
// (With small test cases, set it true. With large test cases, set it false.)
// - Options that has to be careful with:
const bool OVERWRITE_OLD_TESTS = true; // By default: true
const bool CLEAN_ROOT_FOLDER = false; // By default: false

// Options to stress test between two solution files:
bool STRESS_TEST = true;
// - Code files to do stress test with:
const vector<string> STRESS_TEST_SOLUTIONS = {
    FILENAME,
    "other_solution"
};
// - The following options should be all set to false if STRESS_TEST = false to prevent errors:
bool STRESS_TEST_FORCE_STOP = false; // By default: true
bool STRESS_TEST_WRITE_REPORT = true; // By default: true
bool STRESS_TEST_MOVE_WA_OUTPUT_TO_DIRECTORY = true; // By default: false
bool STRESS_TEST_KEEP_WA_TEST_ONLY = true;
// - Options that has to be careful with:
const bool SHOW_COMPARE_ON_CMD = true; // By default: false
const bool SHOW_PROCESS_ON_CMD = true; // By default: true


/* || USER FUNCTIONS || */
// This method initializes subtasks (FOR USERS)
void initializeSubtasks() {
    addSubtask(1, 10);
    addSubtask(11, 20);
}





/* || SYSTEM VARIABLES || */
bool stopLoop;

ofstream LOG("LOG.txt");
bool errorFlag;

ofstream inp;
string directory;
string inputFileName, outputFileName;

ofstream stressTestLog;
string solutionName;
string solutionExeFileName;
string solutionOutputFileName;
bool wrongSolutionOutput;


/* || SYSTEM FUNCTIONS || */
// Enables error flag to report to the user at the end of the program
void logError(int test, string line) {
    LOG << "Test " << test << " || " << line << '\n';
    errorFlag = true;
}

// Shows message on console if SHOW_PROCESS_ON_CMD = true
void showMsg(string message) {
    if (SHOW_PROCESS_ON_CMD) cout << message;
}

// Compiles and create an executable file of code file that makes the output
void compileExecutable(string fileName) {
    showMsg("COMPILING OUTPUT FILE...\n");
    string command = "g++ " + fileName + ".cpp" + " -O3 -o " + fileName;
    int result = system(command.c_str());
    if (!result) showMsg("Compile successful!\n\n");
    else showMsg("Compile unsuccessful... (output may not be generated in the process)\n\n");
}

void compileExecutables() {
    compileExecutable(FILENAME);
    for (string solutionName : STRESS_TEST_SOLUTIONS) {
        string solutionCppFileName = solutionName;
        if (solutionName == FILENAME)
            solutionCppFileName += "_test";
        compileExecutable(solutionCppFileName);
    }
}

// Generates directory path
void generateDirectory(int test, string& directory) {
    if (SEPERATE_EACH_TEST)
        directory = FILENAME+"\\test"+to_string(test)+"\\";
    else
        directory = FILENAME+"\\";
}

// Generates input file name
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
// Generates output file name
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


// Generates solution .exe file name:
void generateSolutionExeFileName() {
    // Case if the solution name is identical to the main file name
    if (solutionName == FILENAME)
        solutionExeFileName = FILENAME + "_test.exe";
    else
        solutionExeFileName = solutionName + ".exe";
}
// Generates solution output file name
void generateSolutionOutputFileName(int test) {
    // Case if the solution name is identical to the main file name
    if (solutionName == FILENAME) {
        if (SEPERATE_EACH_TEST)
            solutionOutputFileName = FILENAME+".ans";
        else
            solutionOutputFileName = "test"+to_string(test)+".ans";
        return;
    }
    // Else
    if (SEPERATE_EACH_TEST)
        solutionOutputFileName = solutionName + ".ans";
    else
        solutionOutputFileName = "test"+to_string(test)+"_"+solutionName+".ans";

}
// Moves solution output file
void moveSolutionOutputFile() {
    if (OVERWRITE_OLD_TESTS)
        remove((directory+solutionOutputFileName).c_str()); // Delete old files first before moving new files into
    rename((solutionName+".ans").c_str(), (directory+solutionOutputFileName).c_str()); // Move output file into correct directory
}
bool generateSolutionOutput(int test) {
    if (!fileExist(solutionExeFileName)) {
        logError(test, ".exe file for the OTHER solution code \""+solutionExeFileName+"\" doesn't exist!! Stress test process won't be executed.");
        return false;
    }
    system(solutionExeFileName.c_str());
    return true;
}


// Stress test between two solution files
void stressTest(int test) {
    if (!fileExist(FILENAME+".exe")) {
        logError(test, ".exe file for the solution code doesn't exist!! Stress test process won't be executed.");
        return;
    }
    generateSolutionExeFileName();
    if (!generateSolutionOutput(test))
        return;
    // Compares result between two generated output files:
    solutionOutputFileName = solutionName + ".ans";
    wrongSolutionOutput = false;
    string command = "fc " + (FILENAME+".out") + " " + solutionOutputFileName;
    if (!SHOW_COMPARE_ON_CMD)
        command += ">nul";
    bool identical = !system(command.c_str());
    // CASE GOT IDENTICAL COMPARISON (AC OUTPUT):
    if (identical) {
        if (STRESS_TEST_WRITE_REPORT) {
            stressTestLog << "Test " << test << " (comparing \"" << solutionName << "\") : AC!" << '\n';
        }
        return;
    }
    // CASE GOT DIFFERENT COMPARISON (WA OUTPUT):
    if (STRESS_TEST_WRITE_REPORT)
        stressTestLog << "Test " << test << " (comparing \"" << solutionName << "\") : WA.." << '\n';
    if (STRESS_TEST_MOVE_WA_OUTPUT_TO_DIRECTORY) {
        generateSolutionOutputFileName(test);
        moveSolutionOutputFile();
    }
    wrongSolutionOutput = true;
    if (STRESS_TEST_FORCE_STOP)
        stopLoop = true;
}
// Perform stress test between multiple solution files:
void stressTests(int test) {
    for (int i = 0; i < STRESS_TEST_SOLUTIONS.size(); i++) {
        solutionName = STRESS_TEST_SOLUTIONS[i];
        stressTest(test);
        if (solutionName != FILENAME)
            showMsg("Done stress test between \""+FILENAME+"\" and \""+solutionName+"\".\n");
        else
            showMsg("Done stress test between \""+FILENAME+"\" and \""+solutionName+"_test\".\n");
    }
    showMsg("DONE STRESS TEST!\n\n");
}


// Checks and stops test generating loop if it's true
void stopLoopCheck(int test) {
    // Default configuration:
    if (test > SUBTASK_END) stopLoop = true;
}
// Check and return whether there is identical test to test with given index
bool checkIdenticalTest(int test) {
    for (int i = SUBTASK_START; i < test; i++) {
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
        stressTests(test);
    if (!STRESS_TEST_KEEP_WA_TEST_ONLY ||
        (STRESS_TEST_KEEP_WA_TEST_ONLY && wrongSolutionOutput)) {
        moveInputFile(test);
        moveOutputFile(test);
    }
}
// Generates full tests
void generateTests() {
    stopLoop = false;
    for (int test = SUBTASK_START;;) {
        stopLoopCheck(test);
        if (stopLoop) break;
        generateTest(test);
        increaseTestIndex(test);
    }
}


void generateTestSet() {
    if (CLEAN_ROOT_FOLDER)
        system(("rmdir /s /q " + FILENAME).c_str());

    mkdir(FILENAME.c_str()); // Create tests root folder

    for (int i = 1; i <= subtasks.size(); i++) {
        if (STRESS_TEST_WRITE_REPORT)
            stressTestLog.open("stress_test_log_subtask" + to_string(i) + ".txt"); //THIS IS NEEDED IN CHECKING OUTPUT RESULTS BETWEEN TWO CODE FILES
        Subtask subtask = subtasks[i-1];
        SUBTASK_START = subtask.startIndex;
        SUBTASK_END = subtask.endIndex;
        SUBTASK_LIMITS = subtask.limits;
        generateTests();
        showMsg("\n-----------------------------------------\n");
        showMsg("DONE SUBTASK " + to_string(i) + "! Test index from " + to_string(SUBTASK_START) + " to " + to_string(SUBTASK_END) + "\n");
        showMsg("-----------------------------------------\n\n");

        if (STRESS_TEST_WRITE_REPORT)
            stressTestLog.close();
    }
}





int main() {
    //cin.tie(0);
    //boostcode;
    //openf;

    //ofstream OUTPUT("TEST_OUTPUT.out"); //THIS IS NEEDED IN CHECKING OUTPUT RESULTS BETWEEN TWO CODE FILES
    if (GENERATE_OUTPUT) compileExecutables();
    initializeSubtasks();
    generateTestSet();

    cout << "\n || DONE GENERATING TESTS!! ||\n";
    cout << "(Have a nice day! :D)\n\n";

    if (errorFlag)
        cout << "There were errors while generating tests which made some things go wrong (not generating things, stress test not working,...)!\nPlease check detail in LOG.txt!!";

    cout << '\n';

    return 0;
}
