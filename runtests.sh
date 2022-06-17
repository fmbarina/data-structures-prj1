#!/bin/bash

DIR_RUN=./entrada
DIR_TEST=./tests_out

if ! [ -e "edcare.out" ] ; then
    echo "Running makefile..."
    make
fi

[ -d "$DIR_TEST" ] && rm -rf "$DIR_TEST"

mkdir -p "$DIR_TEST"

# #de \n 's
get_lines() {
    wc -l <"$1"
}

get_arq_cui() {
    if [ -d "./tests/$1/Entradas" ] ; then
        head -n 1 ./tests/"$1"/Entradas/cuidadores.txt | cut -d ";" -f1    
    else
        head -n 1 ./tests/"$1"/Entrada/cuidadores.txt | cut -d ";" -f1
    fi
}

test()
{
    echo "RUNNING TEST: $(basename "$1")"
    
    [ -d "$DIR_RUN" ] && rm -rf "$DIR_RUN"
    
    mkdir -p "$DIR_RUN"/saida
    mkdir -p "$DIR_TEST"/"$(basename "$1")"
    
    if [ -d "$1/Entradas/" ] ; then
        cp "$1"/Entradas/*.txt "$DIR_RUN"
    else
        cp "$1"/Entrada/*.txt "$DIR_RUN"
    fi

    local arqcuidador
    local linhas

    arqcuidador=$(get_arq_cui "$(basename "$1")")
    linhas="$(get_lines $DIR_RUN/"$arqcuidador".txt)"

    echo "Cuidador: $arqcuidador - Linhas: $linhas"
    
    ./edcare.out "$linhas"

    mv "$DIR_RUN"/saida/*.txt $DIR_TEST/"$(basename "$1")"/
}

if [ "$(ls "./tests")" ]; then
	for testdir in "./tests"/*; do
        test "$testdir"
    done
fi

[ -d "$DIR_RUN" ] && rm -rf "$DIR_RUN"

#valgrind --leak-check=full --track-origins=yes ./edcare.out !$