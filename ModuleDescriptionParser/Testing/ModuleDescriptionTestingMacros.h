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

#ifndef __ModuleDescriptionTestingMacros_h
#define __ModuleDescriptionTestingMacros_h

/// Convenience macros for unit tests.
///
/// The macro returns from the current method with EXIT_FAILURE if the check fails.
/// Expressions can be passed as arguments, they are guaranteed to be executed only once.
///
/// Example:
///
/// \code{.cpp}
/// int testedFunction(int a, int b) { return a+b; }
///
/// int MyTest1(int , char * [])
/// {
///
///   int current = 40 + 2;
///   int expected = 42;
///   CHECK_INT(current, expected);
///
///   CHECK_INT(testedFunction(40,2), 42);
///   CHECK_INT(testedFunction(35,5), 40);
///
///   return EXIT_SUCCESS;
/// }
///
/// \endcode

// Adapted from vtkMRMLCoreTestingMacros.h

#include "ModuleDescriptionTestingUtilities.h"

/// Verifies that pointer is NULL
#define CHECK_NULL(pointer) \
  { \
  const void* pointerValue = (pointer); \
  if (!ModuleDescriptionTestingUtilities::CheckNull(__LINE__,#pointer " is not NULL", pointerValue)) \
    { \
    return EXIT_FAILURE; \
    } \
  }

/// Verifies that pointer is not NULL
#define CHECK_NOT_NULL(pointer) \
  { \
  if (!ModuleDescriptionTestingUtilities::CheckNotNull(__LINE__,#pointer " is NULL", (pointer))) \
    { \
    return EXIT_FAILURE; \
    } \
  }

/// Verifies that pointer is NULL,
/// if check fails then it calls methodToCallOnFailure before returning with failure
#define CHECK_NOT_NULL_ADD_REPORT(pointer, methodToCallOnFailure) \
  { \
  if (!ModuleDescriptionTestingUtilities::CheckNotNull(__LINE__,#pointer " is NULL", (pointer))) \
    { \
    methodToCallOnFailure; \
    return EXIT_FAILURE; \
    } \
  }

#define CHECK_EXIT_SUCCESS(actual) \
  { \
  if (!ModuleDescriptionTestingUtilities::CheckInt(__LINE__,#actual " != EXIT_SUCCESS", (actual), EXIT_SUCCESS)) \
    { \
    return EXIT_FAILURE; \
    } \
  }

/// Verifies if actual int value is the same as expected
#define CHECK_INT(actual, expected) \
  { \
  if (!ModuleDescriptionTestingUtilities::CheckInt(__LINE__,#actual " != " #expected, (actual), (expected))) \
    { \
    return EXIT_FAILURE; \
    } \
  }

/// Verifies if actual int value is the same as expected,
/// if check fails then it calls methodToCallOnFailure before returning with failure
#define CHECK_INT_ADD_REPORT(actual, expected, methodToCallOnFailure) \
  { \
  if (!ModuleDescriptionTestingUtilities::CheckInt(__LINE__,#actual " != " #expected, (actual), (expected))) \
    { \
    methodToCallOnFailure; \
    return EXIT_FAILURE; \
    } \
  }

/// Verifies if actual pointer value is the same as expected
#define CHECK_POINTER(actual, expected) \
  { \
  if (!ModuleDescriptionTestingUtilities::CheckPointer(__LINE__,#actual " != " #expected, (actual), (expected))) \
    { \
    return EXIT_FAILURE; \
    } \
  }

/// Verifies if actual pointer value is the same as expected
#define CHECK_POINTER_DIFFERENT(actual, expected) \
  { \
  if (!ModuleDescriptionTestingUtilities::CheckPointer(__LINE__,#actual " == " #expected, (actual), (expected), false)) \
    { \
    return EXIT_FAILURE; \
    } \
  }

/// Verifies if actual bool value is the same as expected
#define CHECK_BOOL(actual, expected) \
  { \
  if (!ModuleDescriptionTestingUtilities::CheckInt(__LINE__,#actual " != " #expected, (actual)?1:0, (expected)?1:0)) \
    { \
    return EXIT_FAILURE; \
    } \
  }

/// Verifies if actual const char* value is the same as expected.
/// It can handle NULL pointer inputs.
#define CHECK_STRING(actual, expected) \
  { \
  if (!ModuleDescriptionTestingUtilities::CheckString(__LINE__,#actual " != " #expected, (actual), (expected))) \
    { \
    return EXIT_FAILURE; \
    } \
  }

/// Verifies if actual std::string value is the same as expected.
/// It is safe to use for comparing std::string values.
/// It cannot handle NULL pointer inputs.
#define CHECK_STD_STRING(actual, expected) \
  { \
  std::string a = (actual); \
  std::string e = (expected); \
  if (!ModuleDescriptionTestingUtilities::CheckString(__LINE__,#actual " != " #expected, a.c_str(), e.c_str())) \
    { \
    return EXIT_FAILURE; \
    } \
  }

/// Verifies if actual const char* value is the same as expected,
/// if check fails then it calls methodToCallOnFailure before returning with failure
/// It can handle NULL pointer inputs.
#define CHECK_STRING_ADD_REPORT(actual, expected, methodToCallOnFailure) \
  { \
  if (!ModuleDescriptionTestingUtilities::CheckString(__LINE__,#actual " != " #expected, (actual), (expected))) \
    { \
    methodToCallOnFailure; \
    return EXIT_FAILURE; \
    } \
  }

/// Verifies if actual const char* value is not the same as expected.
/// It can handle NULL pointer inputs.
#define CHECK_STRING_DIFFERENT(actual, expected) \
  { \
  if (!ModuleDescriptionTestingUtilities::CheckString(__LINE__,#actual " != " #expected, (actual), (expected), false)) \
    { \
    return EXIT_FAILURE; \
    } \
  }

/// Verifies if actual std::string value is not the same as expected.
/// It is safe to use for comparing std::string values.
/// It cannot handle NULL pointer inputs.
#define CHECK_STD_STRING_DIFFERENT(actual, expected) \
  { \
  std::string a = (actual); \
  std::string e = (expected); \
  if (!ModuleDescriptionTestingUtilities::CheckString(__LINE__,#actual " != " #expected, a.c_str(), e.c_str(), false)) \
    { \
    return EXIT_FAILURE; \
    } \
  }

#endif
