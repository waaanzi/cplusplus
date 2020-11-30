/*
BOOL GetDiskFreeSpaceA(
  LPCSTR  lpRootPathName,
  LPDWORD lpSectorsPerCluster,
  LPDWORD lpBytesPerSector,
  LPDWORD lpNumberOfFreeClusters,
  LPDWORD lpTotalNumberOfClusters
);

BOOL GetDiskFreeSpaceW(
  LPCWSTR lpRootPathName,
  LPDWORD lpSectorsPerCluster,
  LPDWORD lpBytesPerSector,
  LPDWORD lpNumberOfFreeClusters,
  LPDWORD lpTotalNumberOfClusters
);

BOOL GetDiskFreeSpaceExA(
  LPCSTR          lpDirectoryName,
  PULARGE_INTEGER lpFreeBytesAvailableToCaller,
  PULARGE_INTEGER lpTotalNumberOfBytes,
  PULARGE_INTEGER lpTotalNumberOfFreeBytes
);

BOOL GetDiskFreeSpaceExW(
  LPCWSTR         lpDirectoryName,
  PULARGE_INTEGER lpFreeBytesAvailableToCaller,
  PULARGE_INTEGER lpTotalNumberOfBytes,
  PULARGE_INTEGER lpTotalNumberOfFreeBytes
);

statfs
*/

#include <iostream>
#include <windows.h>

using namespace std;

int main(){
  DWORD sectorsPerCluster = 0;
  DWORD bytesPerSector = 0;
  DWORD numberOfFreeClusters = 0;
  DWORD totalNumberOfClusters = 0;
  if (GetDiskFreeSpace(L"F:", &sectorsPerCluster, &bytesPerSector, 
                       &numberOfFreeClusters, &totalNumberOfClusters)){
    cout << "GetDiskFreeSpace:" << endl;
    cout << "SectorsPerCluster\t " << sectorsPerCluster << endl;
    cout << "BytesPerSector\t " << bytesPerSector << endl;
    cout << "NumberOfFreeClusters\t " << numberOfFreeClusters << endl;
    cout << "TotalNumberOfClusters\t " << totalNumberOfClusters << endl;
  }


  ULARGE_INTEGER avail = {0}; 
  ULARGE_INTEGER total = {0};
  ULARGE_INTEGER free = {0};
  if (GetDiskFreeSpaceEx(L"F:", &avail, &total, &free)) {
    cout << "GetDiskFreeSpaceEx:" << endl;
    cout << "TotalNumberOfBytes\t " << total.QuadPart << endl;
    cout << "TotalNumberOfFreeBytes\t " << free.QuadPart << endl;
    cout << "FreeBytesAvailableToCaller\t " << avail.QuadPart << endl;
  }

  cin.get();
  return 0;
}