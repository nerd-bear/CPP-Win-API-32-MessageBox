# Windows API 32 Message Box Utility

This C++ code provides utility functions for creating message boxes using the Windows API. The functions are specifically designed to convert standard C++ strings to wide strings and LPCWSTR, which are then used to display a popup message. This utility only works on Windows systems.

## Table of Contents

1. [Introduction](#introduction)
2. [Functions](#functions)
    - [StringToWString](#stringtowstring)
    - [StringToLPCWSTR](#stringtolpcwstr)
    - [CreateWinAPI32PopupMSG](#createwinapi32popupmsg)
3. [Usage](#usage)
4. [Examples](#examples)
5. [Notes](#notes)

## Introduction

The provided C++ code includes functions to:
- Convert a standard C++ string to a wide string (WString).
- Convert a standard C++ string to LPCWSTR (Long Pointer to a Constant Wide String).
- Create a popup message using the Windows API.

These utilities are helpful when working with Windows-specific applications, particularly when there's a need to display message boxes with various options.

## Functions

### StringToWString

```cpp
std::wstring StringToWString(const std::string &_string, bool _isUtf8Enabled = true);
```

**Description**:  
Converts a standard C++ string (`std::string`) to a wide string (`std::wstring`). This is necessary when dealing with Windows API functions that require wide strings.

**Parameters**:
- `_string`: The string to be converted.
- `_isUtf8Enabled`: Boolean flag to determine if UTF-8 encoding is enabled (default is `true`).

**Returns**:  
A wide string (`std::wstring`).

### StringToLPCWSTR

```cpp
LPCWSTR StringToLPCWSTR(const std::string& _string);
```

**Description**:  
Converts a standard C++ string (`std::string`) to an LPCWSTR string. This is a long pointer to a constant wide string and is used in Windows API functions.

**Parameters**:
- `_string`: The string to be converted.

**Returns**:  
A wide string pointer (`LPCWSTR`).

### CreateWinAPI32PopupMSG

```cpp
int CreateWinAPI32PopupMSG(std::string _title, std::string _message, int _type);
```

**Description**:  
Creates a popup message using the Windows API 32-bit version. The function allows various types of message boxes depending on the user's requirements.

**Parameters**:
- `_title`: The title of the popup message (maximum 43 characters).
- `_message`: The content of the popup message (maximum 43 characters).
- `_type`: The type of popup message to be displayed. Supported types:
  - `1`: Abort-Retry-Ignore
  - `2`: OK-Cancel
  - `3`: Cancel-Try-Continue
  - `4`: Yes-No-Cancel
  - `5`: Yes-No
  - `6`: OK

**Returns**:  
An integer representing the user's response to the popup:
- `1`: OK
- `2`: Cancel
- `3`: Abort
- `4`: Retry
- `5`: Ignore
- `6`: Yes
- `7`: No
- `10`: Try
- `11`: Continue

## Usage

To use this utility in your project, include the header files for Windows API (`windows.h`) and standard libraries (`iostream`, `string`). The functions provided will help you create user-friendly popup messages in your Windows applications.

### Example Usage

```cpp
#include <windows.h>
#include <iostream>
#include <string>

// Function definitions...

int main() {
    int response = CreateWinAPI32PopupMSG("Example Title", "This is an example message.", 2);
    std::cout << "User selected option ID: " << response << std::endl;
    return 0;
}
```

## Examples

### Example 1: Simple OK-Cancel Popup

```cpp
int response = CreateWinAPI32PopupMSG("Confirmation", "Are you sure you want to continue?", 2);
```

### Example 2: Yes-No Popup

```cpp
int response = CreateWinAPI32PopupMSG("Exit", "Do you really want to exit?", 5);
```

### Example 3: Abort-Retry-Ignore Popup

```cpp
int response = CreateWinAPI32PopupMSG("Error", "An error occurred. What would you like to do?", 1);
```

## Notes

- This code is specific to Windows systems and uses the Windows API, so it won't work on other platforms.
- The maximum length for the title and message content is 43 characters due to the limitations of the Windows API message box.
- The `CreateWinAPI32PopupMSG` function uses ANSI encoding by default.
