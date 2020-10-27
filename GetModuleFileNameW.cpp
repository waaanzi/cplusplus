/*
https://docs.microsoft.com/zh-cn/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulefilenamew

GetModuleFileNameW
获取当前进程已加载模块的文件的完整路径，该模块必须由当前进程加载。
如果想要获取其他进程已加载模块的文件路径，可以使用GetModuleFileNameEx函数。

DWORD GetModuleFileNameW(
HMODULE hModule,
LPWSTR  lpFilename,
DWORD   nSize
);

hModule:
A handle to the loaded module whose path is being requested. If this parameter is NULL,
GetModuleFileName retrieves the path of the executable file of the current process.
一个模块的句柄。可以是一个DLL模块，或者是一个应用程序的实例句柄。如果该参数为NULL，
该函数返回该应用程序全路径。

lpFilename:
A pointer to a buffer that receives the fully qualified path of the module.
If the length of the path is less than the size that the nSize parameter specifies,
the function succeeds and the path is returned as a null-terminated string.

If the length of the path exceeds the size that the nSize parameter specifies,
the function succeeds and the string is truncated to nSize characters including the terminating null character.

nSize:
The size of the lpFilename buffer, in TCHARs.

return value:
If the function succeeds, the return value is the length of the string that is copied to the buffer,
in characters, not including the terminating null character.
If the buffer is too small to hold the module name, the string is truncated to nSize characters
including the terminating null character, the function returns nSize,
and the function sets the last error to ERROR_INSUFFICIENT_BUFFER.
*/

#include <Windows.h>
#include <iostream>
#include <string>

int main() {

  wchar_t szExeFile[MAX_PATH];
  GetModuleFileNameW(NULL, szExeFile, MAX_PATH);
  std::wstring path(szExeFile);

  //std::cout << std::to_string(path) << std::endl;
  getchar();
  return 0;
}