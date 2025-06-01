## Files comparison output on CMD:
To compare between two files, we do this:
```cpp
string command = "fc " + (checkDirectory+checkFileName) + " " + (FILENAME+".inp");
if (!SHOW_COMPARE_ON_CMD)
	command += ">nul 2>nul";
```
See the line `command += ">nul 2>nul";` ? It adds `">nul 2>nul"` to the end of the command string:
- `>nul` silences normal output (result that two files are identical or not)
- `2>nul` silences error output (such as file not found,...)
In default, only `>nul` is added in the code, which let the user still see the error output to know and fix the error by themselves.