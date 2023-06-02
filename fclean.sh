listToClean="
  .cmake
  build
  Makefile
  CMakeFiles
  CMakeCache.txt
  cmake-build-debug
  cmake_install.cmake
"

for i in $listToClean; do
	rm -rf "$i"
done

exercises="
	module00/ex00
	module00/ex01
	module00/ex02
	module01/ex00
	module01/ex01
"
for exercise in $exercises; do
	make --no-print-directory -C "$exercise" clean &> /dev/null
done

find . -name '.DS*' -type f -delete
find . -name 'a.out' -type f -delete

