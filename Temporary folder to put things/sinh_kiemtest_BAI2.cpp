#include <bits/stdc++.h>
#define boostcode ios_base::sync_with_stdio(0); cin.tie(0);
#define openf freopen("BAI2.inp", "r", stdin); freopen("BAI2.out", "w", stdout);
#include <io.h> // To be able to use mkdir()

using namespace std;
typedef long long ll;

mt19937_64 rd(time(0));

ll randNum(ll l, ll r) {
    return rd()%(r-l+1) + l;
}

int main() {
    boostcode;
    //openf;

    //ofstream OUTPUT("TEST_OUTPUT.out"); //THIS IS NEEDED IN CHECKING OUTPUT RESULTS BETWEEN TWO CODE FILES

    string filename = "BAI2";

    for (int test = 1; test <= 1000; test++) {
        // Sinh test
        /* VNOI & Themis template:
        string directory = filename+"/test"+to_string(test)+"/";
        mkdir(filename.c_str()); // Create new folder to put test folders
        mkdir(directory.c_str()); // Create new folder to put test
        ofstream inp((filename+".inp").c_str());
        */
        // Codeforces template:
        string directory = filename+"/";
        string output_filename = "test"+to_string(test)+".inp";
        mkdir(filename.c_str()); // Create new folder to put tests
        ofstream inp((filename+".inp").c_str());
        // Variables configuration:
        int n = randNum(1, 5);

        inp.close();
        // Run and move .inp file to each test folder:
        // Codeforces template:
        //remove((directory+output_filename).c_str()); // Delete old files first before moving new files into
        //rename((filename+".inp").c_str(), (directory+output_filename).c_str()); // Move input file into correct directory

        /* VNOI & Themis template:
        remove((directory+filename+".inp").c_str()); // Delete old files first before moving new files into
        rename((filename+".inp").c_str(), (directory+filename+".inp").c_str()); // Move input file into correct directory
        */

        // THE BINDED CODE, WHICH ALLOWS OUTPUT FILES GENERATIONS (AND CHECK OUTPUT RESULTS BETWEEN TWO CODE FILES)
        // GENERATE OUTPUT FILES FROM THE CORRECT SOLUTION FILE CODE:
        // Run and move out file to each test folder:
        system((filename+".exe").c_str());
        remove((directory+filename+".out").c_str()); // Delete old files first before moving new files into
        rename((filename+".out").c_str(), (directory+filename+".out").c_str()); // Move output file into correct directory

        remove((directory+output_filename).c_str()); // Delete old files first before moving new files into
        rename((filename+".inp").c_str(), (directory+output_filename).c_str()); // Move input file into correct directory
        /* Chay 2 file code cho ra file ket qua *.out va *.ans
        system("BAI2.exe");
        system("test_BAI2.exe");

        // CHECK OUTPUT RESULTS BETWEEN TWO CODE FILES:
        // So sanh giua 2 file ket qua
        if (system(("fc " + (filename+".out") + " " + (filename+".ans")).c_str()) == 0) {
            OUTPUT << "AC" << '\n';
        } else {
            OUTPUT << "WA" << '\n';
            return 0;
        }*/
    }

    return 0;
}
