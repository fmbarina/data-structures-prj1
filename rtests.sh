#!/bin/bash

if ! [ -e "edcare.out" ] ; then
    echo "Running makefile..."
    make
fi

[ -d ./test_output ] && rm -rf ./test_output

mkdir -p ./test_output

test()
{
    echo "RUNNING TEST: $1"
    mkdir -p ./test_output/"$(basename "$1")"
    ./edcare.out "$1"  
}

if [ "$(ls "./tests")" ]; then
	for testdir in "./tests"/*; do
        test "$testdir"
    done
fi

#valgrind --leak-check=full --track-origins=yes ./edcare.out !$