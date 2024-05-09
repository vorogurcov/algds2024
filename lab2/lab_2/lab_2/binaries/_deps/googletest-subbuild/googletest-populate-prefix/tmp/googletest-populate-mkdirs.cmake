# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/VisualStudio/ProgrammingProjects/algds2024/lab2/lab_2/lab_2/binaries/_deps/googletest-src"
  "D:/VisualStudio/ProgrammingProjects/algds2024/lab2/lab_2/lab_2/binaries/_deps/googletest-build"
  "D:/VisualStudio/ProgrammingProjects/algds2024/lab2/lab_2/lab_2/binaries/_deps/googletest-subbuild/googletest-populate-prefix"
  "D:/VisualStudio/ProgrammingProjects/algds2024/lab2/lab_2/lab_2/binaries/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "D:/VisualStudio/ProgrammingProjects/algds2024/lab2/lab_2/lab_2/binaries/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "D:/VisualStudio/ProgrammingProjects/algds2024/lab2/lab_2/lab_2/binaries/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "D:/VisualStudio/ProgrammingProjects/algds2024/lab2/lab_2/lab_2/binaries/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/VisualStudio/ProgrammingProjects/algds2024/lab2/lab_2/lab_2/binaries/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/VisualStudio/ProgrammingProjects/algds2024/lab2/lab_2/lab_2/binaries/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
