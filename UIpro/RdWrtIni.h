#ifndef __RDWRTINI_H__
#define __RDWRTINI_H__

#define DIM(a)  sizeof(a)/sizeof(a[0])

//////////////////////////////////////////////////////////////////////////
// º¯ÊýÉùÃ÷
int  ReadIniFile(LPCWSTR lpFileName);
DWORD GetLine(LPWSTR pLine, DWORD dwOffset, DWORD dwSize);
BOOL IsComment(LPCWSTR pLine);
BOOL IsSection(LPCWSTR pLine);
BOOL IsSectionName(LPCWSTR pLine, LPCWSTR pSection);
BOOL IsKey(LPCWSTR pLine , LPCWSTR pKeyName, LPWSTR* pValue, DWORD* dwValLen );
void WriteValue(HANDLE m_hOutput , LPCWSTR pAppName, LPCWSTR pKeyName, LPCWSTR pString);
DWORD GetString(LPCWSTR lpAppName,LPCWSTR lpKeyName,LPWSTR lpReturnedString,DWORD nSize,LPCWSTR lpFileName );
BOOL WINAPI WritePrivateProfileInt(LPCTSTR lpAppName,LPCTSTR lpKeyName,INT Value,LPCTSTR lpFileName);
DWORD LSQ_GetPrivateProfileString(LPCWSTR lpAppName,LPCWSTR lpKeyName,LPCWSTR lpDefault, LPWSTR  lpReturnedString,DWORD   Size,LPCWSTR lpFileName );
UINT LSQ_GetPrivateProfileInt(LPCTSTR lpAppName,LPCTSTR lpKeyName, INT nDefault,LPCTSTR lpFileName );
#endif//__RDWRTINI_H__

