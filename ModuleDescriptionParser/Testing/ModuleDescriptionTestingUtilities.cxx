/*==============================================================================

  Program: 3D Cjyx

  Copyright (c) Kitware Inc.

  See COPYRIGHT.txt
  or http://www.cjyx.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Jean-Christophe Fillion-Robin, Kitware Inc.
  and was partially funded by NIH grant 1U24CA194354-01

==============================================================================*/

#include "ModuleDescriptionTestingUtilities.h"

// STD includes
#include <cstring>
#include <iostream>

namespace ModuleDescriptionTestingUtilities
{

//----------------------------------------------------------------------------
template<typename TYPE>
bool Check(int line, const std::string& description,
           TYPE current, TYPE expected,
           const std::string& _testName,
           bool errorIfDifferent = true)
{
  std::string testName = _testName.empty() ? "Check" : _testName;
  if (errorIfDifferent)
    {
    if(current != expected)
      {
      std::cerr << "\nLine " << line << " - " << description
                << " : " << testName << " failed"
                << "\n\tcurrent :" << current
                << "\n\texpected:" << expected
                << std::endl;
      return false;
      }
    }
  else
    {
    if(current == expected)
      {
      std::cerr << "\nLine " << line << " - " << description
                << " : " << testName << " failed"
                << "\n\tcurrent :" << current
                << "\n\texpected to be different from:" << expected
                << std::endl;
      return false;
      }
    }
  return true;
}

//----------------------------------------------------------------------------
bool CheckInt(int line, const std::string& description,
              int current, int expected)
{
  return Check<int>(line, description, current, expected, "CheckInt");
}

//----------------------------------------------------------------------------
bool CheckNotNull(int line, const std::string& description,
                  const void* pointer)
{
  if(!pointer)
    {
    std::cerr << "\nLine " << line << " - " << description
              << " : CheckNotNull failed"
              << "\n\tpointer:" << pointer
              << std::endl;
    return false;
    }
  return true;
}

//----------------------------------------------------------------------------
bool CheckNull(int line, const std::string& description, const void* pointer)
{
  if(pointer)
    {
    std::cerr << "\nLine " << line << " - " << description
              << " : CheckNull failed"
              << "\n\tpointer:" << pointer
              << std::endl;
    return false;
    }
  return true;
}

//----------------------------------------------------------------------------
bool CheckPointer(int line, const std::string& description,
                  void* current, void* expected, bool errorIfDifferent /* = true */)
{
  return Check<void*>(line, description, current, expected, "CheckPointer", errorIfDifferent);
}

//----------------------------------------------------------------------------
bool CheckString(int line, const std::string& description,
                 const char* current, const char* expected, bool errorIfDifferent /* = true */)
{
  std::string testName = "CheckString";

  bool different = true;
  if (current == 0 || expected == 0)
    {
    different = !(current == 0 && expected == 0);
    }
  else if(strcmp(current, expected) == 0)
    {
    different = false;
    }
  if(different == errorIfDifferent)
    {
    std::cerr << "\nLine " << line << " - " << description
              << " : " << testName << "  failed"
              << "\n\tcurrent :" << (current ? current : "<null>")
              << "\n\texpected:" << (expected ? expected : "<null>")
              << std::endl;
    return false;
    }
  return true;
}

}
