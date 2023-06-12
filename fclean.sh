listToClean=(
  .cmake
  .cache
  build
  Makefile
  CMakeFiles
  CMakeCache.txt
  cmake-build-debug
  cmake_install.cmake
)

for i in "${listToClean[@]}"; do
  rm -rf "$i"
done

exercises=(
  "CPP00/ex00"
  "CPP00/ex01"
  "CPP01/ex00"
  "CPP01/ex01"
  "CPP01/ex02"
  "CPP01/ex03"
  "CPP01/ex04"
  "CPP01/ex05"
  "CPP02/ex00"
  "CPP02/ex01"
  "CPP02/ex02"
  "CPP02/ex03"
  "CPP03/ex00"
  "CPP03/ex01"
  "CPP03/ex02"
)

for exercise in "${exercises[@]}"; do
  make --no-print-directory -C "$exercise" clean 2> /dev/null
done

find . -name '.DS*' -type f -delete &> /dev/null
find . -name 'a.out' -type f -delete &> /dev/null
find . -name '*.replace' -type f -delete &> /dev/null
