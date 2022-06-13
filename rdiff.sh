#!/bin/bash

if ! [ -d "test_output" ] ; then
    echo "ERROR: no test_output directory found"
    exit 1
fi

if ! [ -d "tests" ] ; then
    echo "ERROR: no tests directory found"
    exit 1
fi

compare()
{
    echo ''; echo "DIFF: $1 $2"
    diff "$1" "$1"
}

if [ "$(ls "./test_output")" ]; then
	for test in "./test_output"/*; do
        compare "$test" ./tests/"$(basename "$test")"
    done
fi