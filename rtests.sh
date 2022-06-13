#!/bin/bash

if ! [ -e "edcare.out" ] ; then
    echo "ERROR: edcare.out not found"
    exit 1
fi

[ -d ./test_output ] && rm -rf ./test_output

mkdir -p ./test_output

test()
{
    echo "TEST: $1"
    mkdir -p ./test_output/"$(basename "$1")"
    #./edcare.out "$1" TODO: como leio e pra onde jogo? 
}

if [ "$(ls "./tests")" ]; then
	for testdir in "./tests"/*; do
        test "$testdir"
    done
fi

#valgrind --leak-check=full --track-origins=yes ./edcare.out !$