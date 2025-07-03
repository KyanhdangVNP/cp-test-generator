
---

## 📘 **User Options Guide for Test Generator Program**

This guide explains each configurable option in the code that controls how the test generation and stress testing operate.

---

### 🧾 Section: Input Generator Configuration

```cpp
void funcInput(ofstream& inp)
```

This function is where **you define how a single input test case should be generated**. You use helper functions like `randNum(l, r)` to generate random values.

> ✅ **How to use**:  
> Edit `funcInput(...)` to output random input matching your problem constraints.  
> Example:

```cpp
int n = randNum(1, 100);
inp << n << '\n';
for (int i = 0; i < n; i++)
    inp << randNum(1, 1000) << ' ';
```

---

## 🛠️ Section: User Settings & Options

### 🔹 `const string FILENAME = "BAI2";`

Sets the **basename** of all input/output/stress-test files and directories.

- Example: input will be saved as `BAI2.inp`, output as `BAI2.out`.
    

---

### 🔹 `const int TEST_START = 1;`

### 🔹 `const int TEST_END = 20;`

Controls the range of test indices.

- This will generate 20 test cases
    

---

### 🔹 `const function<void(ofstream&)> FUNC_INPUT = funcInput;`

Specifies the function used to **generate input**.

- Keep this unchanged unless you define another input generator function.
    

---

## ⚙️ Options for Generating Input & Output

### ✅ `bool GENERATE_OUTPUT = true;`

- **true**: Automatically runs your `.exe` solution to generate output files after each input file.
    
- **false**: Only generates `.inp` files, skips generating `.out`.
    

---

### 📁 `bool SEPERATE_EACH_TEST = false;`

- **true**: Creates a folder for each test: `BAI2/test1/`, `BAI2/test2/`, etc.
    
- **false**: All files will go directly into the `BAI2/` folder as `test1.inp`, `test1.out`, etc.
    

---

### 🚫 `const bool PREVENT_IDENTICAL_TESTS = false;`

- **true**: Compares each new input with all previous ones. If it's identical, it regenerates.
    
- **false**: Allows duplicated test cases.
    

⚠️ **Warning**: Setting this to `true` is very slow when generating large numbers of tests.

---

### 🔁 `const bool OVERWRITE_OLD_TESTS = true;`

- **true**: Overwrites old test files with the same name.
    
- **false**: Keeps old files and skips writing if they already exist.
    

---

### 🧹 `const bool CLEAN_ROOT_FOLDER = false;`

- **true**: Deletes the entire folder (`BAI2/`) before starting.
    
- **false**: Keeps existing folder and files.
    

---

## 🧪 Stress Test Options

Use this section when comparing two different solution implementations (e.g., brute force vs optimized).

### 🔂 `bool STRESS_TEST = false;`

- **true**: Enables stress testing. It generates input and compares outputs from two executables:
    
    - `BAI2.exe` — the main solution.
        
    - `BAI2_test.exe` — the brute force or test solution.
        
- **false**: Disables stress testing. Recommended unless you're debugging.
    

---

#### 🔁 `bool STRESS_TEST_REPEAT_UNTIL_WA = false;`

- **true**: Keeps generating tests forever **until a wrong answer is found**.
    
- **false**: Runs until `TEST_END`.
    

> ⚠ Only applies when `STRESS_TEST = true`.

---

#### ⛔ `bool STRESS_TEST_FORCE_STOP = false;`

- **true**: Immediately stops the program if a wrong answer (WA) is found.
    
- **false**: Continues stress testing all tests even if there is a WA.
    

---

#### 📝 `bool STRESS_TEST_WRITE_REPORT = false;`

- **true**: Writes "AC"/"WA" status for each test to `stress_test_log.txt`.
    
- **false**: Skips logging.
    

---

#### 📦 `bool STRESS_TEST_MOVE_WA_OUTPUT_TO_DIRECTORY = false;`

- **true**: Saves the `*.ans` output of the brute force solution to the test folder on WA.
    
- **false**: Discards the `.ans` file.
    

Useful to analyze which test caused the bug.

---

#### 🧪 `bool STRESS_TEST_KEEP_WA_TEST_ONLY = false;`

- **true**: Keeps only the test cases that caused wrong answers.
    
- **false**: Keeps all generated test cases.
    

---

### 📋 `const bool SHOW_COMPARE_ON_CMD = true;`

- **true**: Shows output difference (`fc a.out b.out`) in the console.
    
- **false**: Suppresses comparison output unless there’s a mismatch.
    

---

## ✅ Summary of Recommended Settings for Use Cases

### 🔹 **Use Case 1: Generate Tests Only**

```cpp
GENERATE_OUTPUT = true;
STRESS_TEST = false;
```

### 🔹 **Use Case 2: Stress Test Optimized vs Brute Force**

```cpp
STRESS_TEST = true;
STRESS_TEST_FORCE_STOP = true;
STRESS_TEST_WRITE_REPORT = true;
```

### 🔹 **Use Case 3: Ensure Unique Inputs**

```cpp
PREVENT_IDENTICAL_TESTS = true; // Only for small test ranges
```

### 🔹 **Use Case 4: Clean Up Before Generating**

```cpp
CLEAN_ROOT_FOLDER = true;
```

---

Let me know if you'd like a table or GUI wrapper for easier configuration!