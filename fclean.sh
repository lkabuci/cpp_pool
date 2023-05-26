listToClean="
  lCpp
  build
  Makefile
  CMakeFiles
  CMakeCache.txt
  cmake-build-debug
  cmake_install.cmake
"

for i in $listToClean; do
	rm -rf $PWD/$i
done

make --no-print-directory -C $PWD/module00/ex00 clean
make --no-print-directory -C $PWD/module00/ex01 clean
