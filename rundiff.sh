#!/bin/bash

# Notas do autor:
# - Execute esse script na raiz do projeto!
#
# Q: Por que está tudo em inglês?
# A: Porque tenho problema e programo em inglês por automático.

beg="$1"
end="$2"

error=

if ! [ -d "test_output" ] ; then
    echo "ERROR: no test_output directory found. Did you run the tests?"
    exit 1
fi

if ! [ -d "tests" ] ; then
    echo "ERROR: no tests directory found."
    exit 1
fi

do_diff() {
    echo "DIFF: $1"
    dif=$(diff -qur --exclude=Entradas --exclude=Entrada --suppress-common-lines "$1" ./tests/"$(basename "$1")")

    if [ -n "$dif" ]; then
        error=hahayes
        echo "ERROR: test '$(basename "$test")' failed"
        echo "$dif"
    else
        echo 'OK'
    fi
}

if [ -n "$beg" ] ; then
    [ -z "$end" ] && end="$beg"

    for i in $(seq "$beg" "$end") ; do
        do_diff "$i"
    done
else
    for test in "./test_output"/*; do
        do_diff "$test"
    done
fi

echo ''

if [ -n "$error" ] ; then
    echo 'There were differences'.
    exit 1
else
    echo 'There were no differences, all good!'
fi
