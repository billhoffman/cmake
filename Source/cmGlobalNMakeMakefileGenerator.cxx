/*=========================================================================

  Program:   CMake - Cross-Platform Makefile Generator
  Module:    $RCSfile$
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) 2002 Kitware, Inc., Insight Consortium.  All rights reserved.
  See Copyright.txt or http://www.cmake.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include "cmGlobalNMakeMakefileGenerator.h"
#include "cmLocalUnixMakefileGenerator.h"
#include "cmMakefile.h"


cmGlobalNMakeMakefileGenerator::cmGlobalNMakeMakefileGenerator()
{
  m_FindMakeProgramFile = "CMakeNMakeFindMake.cmake";
}

void cmGlobalNMakeMakefileGenerator::EnableLanguage(const char* l,
                                                    cmMakefile *mf)
{
  // pick a default 
  mf->AddDefinition("CMAKE_GENERATOR_CC", "cl");
  mf->AddDefinition("CMAKE_GENERATOR_CXX", "cl");
  this->cmGlobalUnixMakefileGenerator::EnableLanguage(l, mf);
}

///! Create a local generator appropriate to this Global Generator
cmLocalGenerator *cmGlobalNMakeMakefileGenerator::CreateLocalGenerator()
{
  cmLocalUnixMakefileGenerator *lg = new cmLocalUnixMakefileGenerator;
  lg->SetWindowsShell(true);
  lg->SetMakeSilentFlag("/nologo");
  lg->SetGlobalGenerator(this);
  return lg;
}
