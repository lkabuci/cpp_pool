listToClean="
  .cmake
  build
  Makefile
  CMakeFiles
  CMakeCache.txt
  cmake-build-debug
  cmake_install.cmake
"

for i in "$listToClean"; do
	rm -rf "$i"
done

exercises="
	CPP00/ex00
	CPP00/ex01
	CPP01/ex00
	CPP01/ex01
	CPP01/ex02
	CPP01/ex03
	CPP01/ex04
	CPP01/ex05
"
for exercise in $exercises; do
	make --no-print-directory -C "$exercise" clean &> /dev/null
done

find . -name '.DS*' -type f -delete
find . -name 'a.out' -type f -delete
