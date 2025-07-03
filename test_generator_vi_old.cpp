#include <bits/stdc++.h>
#define boostcode ios_base::sync_with_stdio(0); cin.tie(0);
#define openf freopen("BAI1.inp", "r", stdin); freopen("BAI1.out", "w", stdout);
#include <io.h> // To be able to use mkdir()
#include <sys/stat.h> // To check if file exists

using namespace std;
typedef long long ll;

/* || CÁC HÀM CÀI ĐẶT SẴN HỖ TRỢ NGƯỜI DÙNG || */
/**
 * Tạo một số ngẫu nghiên trong phạm vi từ l đến r
 */
mt19937_64 rd(time(0));
ll randNum(ll l, ll r) {
    return rd()%(r-l+1) + l;
}





  /*------------------------------------------------*/
 /* VIẾT CODE SINH GIÁ TRỊ TEST TRONG HÀM Ở DƯỚI!! */
/*------------------------------------------------*/

// Đây là code mẫu sinh giá trị test cho bài 2 của kỳ thi
// Tin học trẻ tỉnh Phú Yên năm 2024-2025, bảng C2
void funcInput(ofstream& inp) {
    int n = randNum(1, 5);
    inp << n << '\n';
    for (int i = 1; i <= n; i++) {
        inp << randNum(1, 5) << ' ' << randNum(1, 20) << '\n';
    }
}

  /*------------------------------------------------*/
 /* VIẾT CODE SINH GIÁ TRỊ TEST TRONG HÀM Ở TRÊN!! */
/*------------------------------------------------*/

/* || CÀI ĐẶT & TÙY CHỌN NGƯỜI DÙNG || */
// Thông tin chung của bộ test:
/**
 * Tên bộ test
 */
const string FILENAME = "BAI2";
/**
 * Thứ tự test bắt đầu
 */
const int TEST_START = 1;
/**
 * Thứ tự test kết thúc
 */
const int TEST_END = 20;
/**
 * Hàm sinh giá trị test
 * (có thể gắn với các hàm khác ngoài funcInput theo ý muốn)
 */
const function<void(ofstream& inp)> FUNC_INPUT = funcInput;

// Các tùy chọn sinh dữ liệu input & output:
/**
 * Cho phép sinh dữ liệu output cho từng test
 */
bool GENERATE_OUTPUT = true;
/**
 * Cho phép phân loại từng test vào từng thư mục được đánh dấu
 */
bool SEPERATE_EACH_TEST = true;
/**
 * Cho phép hệ thống kiểm tra và tránh những test sinh giá trị bị trùng lặp
 * | TÙY CHỌN NÀY KHÔNG ĐƯỢC KHUYẾN KHÍCH SỬ DỤNG VÌ CÓ THỂ LÀM CHẬM QUÁ TRÌNH SINH TEST! |
 * (Với những bộ test nhỏ thì có thể cho phép tùy chọn này, nhưng với bộ test lớn thì hãy cân nhắc kỹ.)
 * Giá trị mặc định: false
 */
const bool PREVENT_IDENTICAL_TESTS = false;
// - Những tùy chọn cần phải cân nhắc trước khi dùng:
/**
 * Cho phép viết test đè lên test cũ nếu bị trùng tên
 * Giá trị mặc định: true
 */
const bool OVERWRITE_OLD_TESTS = true;
/**
 * Cho phép hệ thống xóa hoàn toàn thư mục chứa bộ test trước khi thực hiện sinh test
 * Giá trị mặc định: false
 */
const bool CLEAN_ROOT_FOLDER = false;

// Các tùy chọn so test giữa các file code bài làm:
/**
 * Cho phép thực hiện so test sau khi dữ liệu input (và output) được sinh
 */
bool STRESS_TEST = false;
// - Những tùy chọn sau nên đều được đặt giá trị thành false nếu để tùy chọn
// STRESS_TEST = false để tránh những lỗi không đáng có:
/**
 * Cho phép lặp lại quá trình so test liên tục cho đến khi có dữ liệu test làm kết quả
 * giữa 2 file code bài làm là khác nhau
 * Giá trị mặc định: true
 */
bool STRESS_TEST_REPEAT_UNTIL_WA = false;
/**
 * Cho phép trình sinh test buộc dừng lại khi có dữ liệu test được sinh ra làm kết quả
 * giữa 2 file code bài làm là khác nhau
 * Giá trị mặc định: true
 */
bool STRESS_TEST_FORCE_STOP = false;
/**
 * Cho phép viết lại kết quả so kết quả giữa 2 file code bài làm sau mỗi test
 * (dữ liệu báo cáo sẽ được ghi lại vào file "stress_test_log.txt")
 * Giá trị mặc định: true
 */
bool STRESS_TEST_WRITE_REPORT = false;
/**
 * Cho phép lưu kết quả các file code bài làm xuất ra với test mới sinh vào thư mục
 * chứa test đó
 * Giá trị mặc định: false
 */
bool STRESS_TEST_MOVE_WA_OUTPUT_TO_DIRECTORY = false;
/**
 * Chỉ cho phép trình so test lưu lại những test bị WA do kết quả từ 2 file
 * code bài làm là khác nhau
 * Giá trị mặc định: false
 */
bool STRESS_TEST_KEEP_WA_TEST_ONLY = false;
// - Những tùy chọn cần phải cân nhắc trước khi dùng:
/**
 * Cho phép viết lên console thông tin so sánh trong quá trình chạy so test
 * Giá trị mặc định: false
 */
const bool SHOW_COMPARE_ON_CMD = true;




/* || CÁC BIẾN CHO HỆ THỐNG || */
bool stopLoop;

ofstream LOG("LOG.txt");
bool errorFlag;

ofstream inp;
string directory;
string inputFileName, outputFileName;

ofstream stressTestLog;
string solutionOutputFileName;
bool wrongSolutionOutput;


/* || CÁC HÀM XỬ LÍ HỆ THỐNG || */
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
