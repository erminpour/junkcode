#!/bin/bash

usage() {
    echo "Usage:" 
    echo -en "$0 <param>
	     -h|--help
	     -f|--foo
	     -b|--bar
	     -x|--baz\n"
}

__call_print() {
    echo $1
}

if [ $# -eq 0 ]
then
    usage
    exit 1
fi

while (($# > 0)); do
    case $1 in
	    -h|--help) usage; exit 1 ;;
	    -f|--foo) __foo_flag="yes";;
	    -b|--bar) __bar_flag="yes";;
	    -z|--baz) __baz_flag="yes";;
	    -*) printf "\nUnknown option: %s\n\n" "$1" >&2; usage; exit 1;;
	    *) usage ;;
    esac
    shift
done

if [ "$__foo_flag" == "yes" ]
then
    __call_print "foo"
fi

if [ "$__bar_flag" == "yes" ]
then
    __call_print "bar"
fi

if [ "$__baz_flag" == "yes" ]
then
    __call_print "baz"
fi

