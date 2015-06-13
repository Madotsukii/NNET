#!/bin/bash

NAME="NNET"

RELEASE=false
DEBUG=false
UNITTEST=false
RENEW=false

while [[ $# > 0 ]]
do
	key="$1"

	case $key in
		-r | --release)
		RELEASE=true
		;;
		
		-d | --debug)
		DEBUG=true
		;;

		-u | --unittest)
		UNITTEST=true
		;;

		-rn | --renew)
		RENEW=true
		;;
		
		*)
			# Undefined option
		;;
	esac
	shift
done

if [ $DEBUG = false ] && [ $UNITTEST = false ] && [ $RELEASE = false ]; then
	cd build/release
	./$NAME
	cd ../..
fi

if [ $UNITTEST = true ]; then
	cd build/unittest
	make test
	cd ../..
fi

if [ $DEBUG = true ]; then
	cd build/debug
	./$NAME
	cd ../..
fi

if [ $RELEASE = true ]; then
	cd build/release
	./$NAME
	cd ../..
fi
