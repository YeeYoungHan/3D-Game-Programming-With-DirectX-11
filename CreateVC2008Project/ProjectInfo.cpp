/* 
 * Copyright (C) 2012 Yee Young Han <websearch@naver.com> (http://blog.naver.com/websearch)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA 
 */

#include "ProjectInfo.h"
#include <objbase.h>

#pragma comment(lib,"ole32.lib")

bool GetGUID( std::string & strGUID )
{
	GUID	sttGUID;
	HRESULT	hr;
	bool bRes = false;

	hr = ::CoInitialize(0);
	if( FAILED(hr) )
	{
		return false;
	}

	hr = ::CoCreateGuid( &sttGUID );
	if( SUCCEEDED(hr) )
	{
		char szGUID[51];

		_snprintf( szGUID, sizeof(szGUID), "{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}", sttGUID.Data1, sttGUID.Data2, sttGUID.Data3
			, sttGUID.Data4[0], sttGUID.Data4[1], sttGUID.Data4[2], sttGUID.Data4[3], sttGUID.Data4[4], sttGUID.Data4[5], sttGUID.Data4[6], sttGUID.Data4[7] );
		strGUID = szGUID;
		bRes = true;
	}

	::CoUninitialize();

	return bRes;
}

bool SetFxFileList( const char * pszFolder, STRING_LIST & clsList )
{
	char			szPath[2048];
	HANDLE		hSearch;
	BOOL			fisOk = TRUE;
	WIN32_FIND_DATA wfd;

	_snprintf( szPath, sizeof(szPath), "%s\\*.*", pszFolder );

	memset( &wfd, 0, sizeof(wfd) );
	hSearch = FindFirstFile( szPath, &wfd );
	if( hSearch == INVALID_HANDLE_VALUE )
	{
		return false;
	}
	
	while( fisOk )
	{
		if( strcmp( wfd.cFileName, "." ) && strcmp( wfd.cFileName, ".." ) )
		{
			if( strstr( wfd.cFileName, ".fx" ) && strstr( wfd.cFileName, ".fxo" ) == NULL )
			{
				clsList.push_back( wfd.cFileName );
			}
		}

		fisOk = FindNextFile( hSearch, &wfd );
	}

	FindClose(hSearch);

	return true;
}

bool CProjectInfo::SetFolder( const char * pszFolder )
{
	m_strFolder = pszFolder;

	int iLen = strlen(pszFolder);
	for( int i = iLen - 1; i > 0; --i )
	{
		if( pszFolder[i] == '\\' )
		{
			m_strName = pszFolder + i + 1;
			break;
		}
	}

	if( m_strName.empty() ) return false;
	if( GetGUID( m_strSolutionGUID ) == false ) return false;
	if( GetGUID( m_strProjectGUID ) == false ) return false;

	char			szPath[2048], szFileName[2048];
	HANDLE		hSearch;
	BOOL			fisOk = TRUE;
	WIN32_FIND_DATA wfd;

	_snprintf( szPath, sizeof(szPath), "%s\\*.*", pszFolder );

	m_clsFileList.clear();
	m_clsFxFileList.clear();

	memset( &wfd, 0, sizeof(wfd) );
	hSearch = FindFirstFile( szPath, &wfd );
	if( hSearch == INVALID_HANDLE_VALUE )
	{
		return false;
	}
	
	while( fisOk )
	{
		if( strcmp( wfd.cFileName, "." ) && strcmp( wfd.cFileName, ".." ) )
		{
			if( strstr( wfd.cFileName, ".h" ) || strstr( wfd.cFileName, ".cpp" ) )
			{
				m_clsFileList.push_back( wfd.cFileName );
			}
			else if( wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY )
			{
				if( !strcmp( wfd.cFileName, "FX" ) )
				{
					_snprintf( szFileName, sizeof(szFileName), "%s\\%s", pszFolder, wfd.cFileName );
					SetFxFileList( szFileName, m_clsFxFileList );
				}
			}
		}

		fisOk = FindNextFile( hSearch, &wfd );
	}

	FindClose(hSearch);

	return true;
}
