#ifndef _CREATE_VC2008_PROJECT_H_
#define _CREATE_VC2008_PROJECT_H_

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string>

#define COMMON_GUID			"{5C9DF018-9495-4C20-BE26-E830A0AB3D08}"
#define EFFECTS11_GUID	"{DF460EAB-570D-4B50-9089-2E2FC801BF38}"

class CProjectInfo
{
public:
	std::string m_strFolder;
	std::string m_strName;
	std::string m_strSolutionGUID;
	std::string m_strProjectGUID;
};

bool CreateSolution( CProjectInfo & clsPI );
bool CreateProject( CProjectInfo & clsPI );

#endif
