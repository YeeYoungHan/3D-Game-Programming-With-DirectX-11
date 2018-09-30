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

#include "CreateVC2008Project.h"

bool CreateSolution( CProjectInfo & clsPI )
{
	std::string strFileName = clsPI.m_strFolder;
	strFileName.append( "\\" );
	strFileName.append( clsPI.m_strName );
	strFileName.append( ".sln" );

	FILE * fd = fopen( strFileName.c_str(), "wb" );
	if( fd == NULL )
	{
		printf( "%s fopen(%s) error\n", __FUNCTION__, strFileName.c_str() );
		return false;
	}

	unsigned char szBOM[3] = { 0xEF, 0xBB, 0xBF };

	fwrite( szBOM, 1, 3, fd );

	fprintf( fd, "\r\n" );
	fprintf( fd, "Microsoft Visual Studio Solution File, Format Version 10.00\r\n" );
	fprintf( fd, "# Visual Studio 2008\r\n" );
	fprintf( fd, "Project(\"%s\") = \"%s\", \"%s.vcproj\", \"%s\"\r\n"
		, clsPI.m_strSolutionGUID.c_str(), clsPI.m_strName.c_str(), clsPI.m_strName.c_str(), clsPI.m_strProjectGUID.c_str() );

	fprintf( fd, "	ProjectSection(ProjectDependencies) = postProject\r\n" );
	fprintf( fd, "		{5C9DF018-9495-4C20-BE26-E830A0AB3D08} = {5C9DF018-9495-4C20-BE26-E830A0AB3D08}\r\n" );
	fprintf( fd, "		{DF460EAB-570D-4B50-9089-2E2FC801BF38} = {DF460EAB-570D-4B50-9089-2E2FC801BF38}\r\n" );
	fprintf( fd, "	EndProjectSection\r\n" );
	fprintf( fd, "EndProject\r\n" );
	fprintf( fd, "Project(\"%s\") = \"Common\", \"..\\..\\Common\\Common.vcproj\", \"{5C9DF018-9495-4C20-BE26-E830A0AB3D08}\"\r\n", clsPI.m_strSolutionGUID.c_str() );
	fprintf( fd, "EndProject\r\n" );
	fprintf( fd, "Project(\"%s\") = \"Effects11\", \"..\\..\\Effects11\\Effects11_2008.vcproj\", \"{DF460EAB-570D-4B50-9089-2E2FC801BF38}\"\r\n", clsPI.m_strSolutionGUID.c_str() );
	fprintf( fd, "EndProject\r\n" );
	fprintf( fd, "Global\r\n" );
	fprintf( fd, "	GlobalSection(SolutionConfigurationPlatforms) = preSolution\r\n" );
	fprintf( fd, "		Debug|Win32 = Debug|Win32\r\n" );
	fprintf( fd, "		Debug|x64 = Debug|x64\r\n" );
	fprintf( fd, "		Release|Win32 = Release|Win32\r\n" );
	fprintf( fd, "		Release|x64 = Release|x64\r\n" );
	fprintf( fd, "	EndGlobalSection\r\n" );
	fprintf( fd, "	GlobalSection(ProjectConfigurationPlatforms) = postSolution\r\n" );
	fprintf( fd, "		%s.Debug|Win32.ActiveCfg = Debug|Win32\r\n", clsPI.m_strProjectGUID.c_str() );
	fprintf( fd, "		%s.Debug|Win32.Build.0 = Debug|Win32\r\n", clsPI.m_strProjectGUID.c_str() );
	fprintf( fd, "		%s.Debug|x64.ActiveCfg = Debug|Win32\r\n", clsPI.m_strProjectGUID.c_str() );
	fprintf( fd, "		%s.Release|Win32.ActiveCfg = Release|Win32\r\n", clsPI.m_strProjectGUID.c_str() );
	fprintf( fd, "		%s.Release|Win32.Build.0 = Release|Win32\r\n", clsPI.m_strProjectGUID.c_str() );
	fprintf( fd, "		%s.Release|x64.ActiveCfg = Release|Win32\r\n", clsPI.m_strProjectGUID.c_str() );
	fprintf( fd, "		{5C9DF018-9495-4C20-BE26-E830A0AB3D08}.Debug|Win32.ActiveCfg = Debug|Win32\r\n" );
	fprintf( fd, "		{5C9DF018-9495-4C20-BE26-E830A0AB3D08}.Debug|Win32.Build.0 = Debug|Win32\r\n" );
	fprintf( fd, "		{5C9DF018-9495-4C20-BE26-E830A0AB3D08}.Debug|x64.ActiveCfg = Debug|Win32\r\n" );
	fprintf( fd, "		{5C9DF018-9495-4C20-BE26-E830A0AB3D08}.Release|Win32.ActiveCfg = Release|Win32\r\n" );
	fprintf( fd, "		{5C9DF018-9495-4C20-BE26-E830A0AB3D08}.Release|Win32.Build.0 = Release|Win32\r\n" );
	fprintf( fd, "		{5C9DF018-9495-4C20-BE26-E830A0AB3D08}.Release|x64.ActiveCfg = Release|Win32\r\n" );
	fprintf( fd, "		{DF460EAB-570D-4B50-9089-2E2FC801BF38}.Debug|Win32.ActiveCfg = Debug|Win32\r\n" );
	fprintf( fd, "		{DF460EAB-570D-4B50-9089-2E2FC801BF38}.Debug|Win32.Build.0 = Debug|Win32\r\n" );
	fprintf( fd, "		{DF460EAB-570D-4B50-9089-2E2FC801BF38}.Debug|x64.ActiveCfg = Debug|x64\r\n" );
	fprintf( fd, "		{DF460EAB-570D-4B50-9089-2E2FC801BF38}.Debug|x64.Build.0 = Debug|x64\r\n" );
	fprintf( fd, "		{DF460EAB-570D-4B50-9089-2E2FC801BF38}.Release|Win32.ActiveCfg = Release|Win32\r\n" );
	fprintf( fd, "		{DF460EAB-570D-4B50-9089-2E2FC801BF38}.Release|Win32.Build.0 = Release|Win32\r\n" );
	fprintf( fd, "		{DF460EAB-570D-4B50-9089-2E2FC801BF38}.Release|x64.ActiveCfg = Release|x64\r\n" );
	fprintf( fd, "		{DF460EAB-570D-4B50-9089-2E2FC801BF38}.Release|x64.Build.0 = Release|x64\r\n" );
	fprintf( fd, "	EndGlobalSection\r\n" );
	fprintf( fd, "	GlobalSection(SolutionProperties) = preSolution\r\n" );
	fprintf( fd, "		HideSolutionNode = FALSE\r\n" );
	fprintf( fd, "	EndGlobalSection\r\n" );
	fprintf( fd, "EndGlobal\r\n" );

	fclose( fd );

	return true;
}


