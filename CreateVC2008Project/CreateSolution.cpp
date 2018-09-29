#include "CreateVC2008Project.h"

bool CreateSolution( CProjectInfo & clsPI )
{
	std::string strFileName = clsPI.m_strFolder;
	strFileName.append( "\\" );
	strFileName.append( clsPI.m_strName );
	strFileName.append( ".sln" );

	FILE * fd = fopen( strFileName.c_str(), "w, ccs=UTF-8" );
	if( fd == NULL )
	{
		printf( "%s fopen(%s) error\n", __FUNCTION__, strFileName.c_str() );
		return false;
	}

	fprintf( fd, "\r\n" );
	fprintf( fd, "Microsoft Visual Studio Solution File, Format Version 10.00\r\n" );
	fprintf( fd, "# Visual Studio 2008\r\n" );
	fprintf( fd, "Project(\"{8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942}\") = \"Box\", \"Box.vcproj\", \"{B7A65481-BECF-4EFD-918E-8AAB34416D52}\"\r\n" );
	fprintf( fd, "	ProjectSection(ProjectDependencies) = postProject\r\n" );
	fprintf( fd, "		{5C9DF018-9495-4C20-BE26-E830A0AB3D08} = {5C9DF018-9495-4C20-BE26-E830A0AB3D08}\r\n" );
	fprintf( fd, "		{DF460EAB-570D-4B50-9089-2E2FC801BF38} = {DF460EAB-570D-4B50-9089-2E2FC801BF38}\r\n" );
	fprintf( fd, "	EndProjectSection\r\n" );
	fprintf( fd, "EndProject\r\n" );
	fprintf( fd, "Project(\"{8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942}\") = \"Common\", \"..\\..\\Common\\Common.vcproj\", \"{5C9DF018-9495-4C20-BE26-E830A0AB3D08}\"\r\n" );
	fprintf( fd, "EndProject\r\n" );
	fprintf( fd, "Project(\"{8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942}\") = \"Effects11\", \"..\\..\\Effects11\\Effects11_2008.vcproj\", \"{DF460EAB-570D-4B50-9089-2E2FC801BF38}\"\r\n" );
	fprintf( fd, "EndProject\r\n" );
	fprintf( fd, "Global\r\n" );
	fprintf( fd, "	GlobalSection(SolutionConfigurationPlatforms) = preSolution\r\n" );
	fprintf( fd, "		Debug|Win32 = Debug|Win32\r\n" );
	fprintf( fd, "		Debug|x64 = Debug|x64\r\n" );
	fprintf( fd, "		Release|Win32 = Release|Win32\r\n" );
	fprintf( fd, "		Release|x64 = Release|x64\r\n" );
	fprintf( fd, "	EndGlobalSection\r\n" );
	fprintf( fd, "	GlobalSection(ProjectConfigurationPlatforms) = postSolution\r\n" );
	fprintf( fd, "		{B7A65481-BECF-4EFD-918E-8AAB34416D52}.Debug|Win32.ActiveCfg = Debug|Win32\r\n" );
	fprintf( fd, "		{B7A65481-BECF-4EFD-918E-8AAB34416D52}.Debug|Win32.Build.0 = Debug|Win32\r\n" );
	fprintf( fd, "		{B7A65481-BECF-4EFD-918E-8AAB34416D52}.Debug|x64.ActiveCfg = Debug|Win32\r\n" );
	fprintf( fd, "		{B7A65481-BECF-4EFD-918E-8AAB34416D52}.Release|Win32.ActiveCfg = Release|Win32\r\n" );
	fprintf( fd, "		{B7A65481-BECF-4EFD-918E-8AAB34416D52}.Release|Win32.Build.0 = Release|Win32\r\n" );
	fprintf( fd, "		{B7A65481-BECF-4EFD-918E-8AAB34416D52}.Release|x64.ActiveCfg = Release|Win32\r\n" );
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


