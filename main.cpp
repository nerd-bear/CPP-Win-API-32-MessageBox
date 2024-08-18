#include <windows.h>
#include <iostream>
#include <string>


/**
 * @brief String to Wide String Conveter
 * 
 * This function converts a standard C++ String to a WString usint a few clever tenicues
 * 
 * @param s is the string to be converted
 * 
 * @param isUtf8 is true by default and defines weather the UTF8 is enabled
 * 
 * @returns W String
 */
std::wstring StringToWString(const std::string &_string, bool _isUtf8Enabled = true)
{
    int _len;
    int _StringLength = (int)_string.length() + 1;
    _len = MultiByteToWideChar(_isUtf8Enabled ? CP_UTF8 : CP_ACP, 0, _string.c_str(), _StringLength, 0, 0);
    std::wstring buf;
    buf.resize(_len);
    MultiByteToWideChar(_isUtf8Enabled ? CP_UTF8 : CP_ACP, 0, _string.c_str(), _StringLength,
           const_cast<wchar_t *>(buf.c_str()), _len);
    return buf;
}

/**
 * @brief String to LPCWSTR converter
 * 
 * This function converts a standard C++ String to a LPCWSTR String
 * 
 * @param str is the string to be converted
 * 
 * @returns LPCWSTR String
 */
LPCWSTR StringToLPCWSTR(const std::string& _string) {
    std::wstring _wstr = StringToWString(_string);
    return _wstr.c_str();
}

/**
 * @brief Creates a Popup Message
 * 
 * This function creates a simple Popup Message using Windows API 32 bit version. It only works on windows systems.
 * 
 * @note This popup method only allows Maximum 43 Chars for Title and 43 Chars for Contents
 * @note Uses ANSI ENCODING
 * 
 * @param _title is the title of the PopUp
 * 
 * @param _message is the message content of the PopUp
 * 
 * @param _type is the type of the PopUp message
 * 
 *  1-AbortRetryIgnore 
 * 
 *  2-OkCancel 
 * 
 *  3-CancelTryContinue 
 * 
 *  4-YesNoCancel 
 * 
 *  5-YesNo
 * 
 *  6-OK
 * 
 * @returns ID of the option selected (INT)
 * 
 * 1 Ok
 * 
 * 2 Cancel
 * 
 * 3 Abort
 * 
 * 4 Retry
 * 
 * 5 Ignore
 * 
 * 6 Yes
 * 
 * 7 No
 * 
 * 10 Try
 * 
 * 11 Continue
 */
int CreateWinAPI32PopupMSG(std::string _title, std::string _message, int _type)
{
    LPCWSTR _szTitle = StringToLPCWSTR(_title);
    LPCWSTR _szMessage = StringToLPCWSTR(_message);
    UINT _popupType;

    switch (_type)
    {
        case 1: _popupType = MB_ABORTRETRYIGNORE; break;
        case 2: _popupType = MB_OKCANCEL; break;
        case 3: _popupType = MB_CANCELTRYCONTINUE; break;
        case 4: _popupType = MB_YESNOCANCEL; break;
        case 5: _popupType = MB_YESNO; break;
        case 6: _popupType = MB_OK; break;
        default: std::cout << _type << " : Unknown Windows API 32-BIT-VERSION POPUP MESSAGE type '" << _type << "' !\n"; exit(1); break;
    }

    std::cout << _popupType;

    int _msgboxID = MessageBoxW(NULL, _szMessage, _szTitle, _popupType);

    return _msgboxID;
}
