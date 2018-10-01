# 3D-Game-Programming-With-DirectX-11
http://www.d3dcoder.net/d3d11.htm 에서 다운로드 받은 Introduction to 3D GAME PROGRAMMING WITH DIRECTX 11 도서의 소스 코드를 VC++ 2008 에서 빌드할 수 있도록 수정하는 프로젝트입니다.

http://www.d3dcoder.net/d3d11.htm 에서 다운로드 받은 Introduction to 3D GAME PROGRAMMING WITH DIRECTX 11 도서의 소스 코드는 VC++ 2010 에서 빌드할 수 있도록 개발된 것 같고 VC++ 2008 에서 빌드하려면 빌드 환경을 다시 구성해야 하므로 VC++ 2008 에서 빌드할 수 있도록 빌드 환경을 다시 구성하는 프로젝트를 시작하게 되었습니다.

수작업으로 VC++ 2008 솔루션 및 프로젝트를 생성하고 빌드 환경을 구성하는 것은 다소 번거로움이 있어서 소스 코드 폴더를 지정하면 해당 소스 코드 폴더에 VC++ 2008 술루션 파일 및 프로젝트 파일을 자동으로 생성하고 빌드 환경을 구성해 주는 CreateVC2008Project 프로그램을 개발하였습니다. CreateVC2008Project 프로그램의 소스 코드는 CreateVC2008Project 폴더를 참고하세요.

본 프로젝트의 소스 코드를 빌드하려면 DirectX SDK(June 2010) 이 설치되어 있어야 하고 DirectX SDK(June 2010) 의 기본 설치 폴더인 "C:\Program Files (x86)\Microsoft DirectX SDK (June 2010)" 폴더에 설치되어 있어야 합니다. 또한 VC++ 2008 이 설치되어 있어야 합니다.

현재까지 아래의 폴더의 소스 코드를 VC++ 2008 에서 빌드할 수 있도록 수정하였습니다.

* Chapter 4 Direct3D Initialization
* Chapter 6 Drawing in Direct3D
* Chapter 7 Lighting
* Chapter 8 Texturing
* Chapter 9 Blending
* Chapter 10 Stenciling
* Chapter 11 The Geometry Shader
* Chapter 12 The Compute Shader
* Chapter 13 The Tessellation Stages
* Chapter 14 Building a First Person Camera
* Chapter 15 Instancing and Frustum Culling
* Chapter 16 Picking
* Chapter 17 Cube Mapping
* Chapter 18 Normal and Displacement Mapping
* Chapter 19 Terrain Rendering
* Chapter 20 Particle Systems
* Chapter 21 Shadow Mapping

본 프로젝트를 진행하는 개발자 정보는 다음과 같습니다.

* 개발자 블로그: http://blog.naver.com/websearch
