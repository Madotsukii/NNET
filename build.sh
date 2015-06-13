#!/bin/bash

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
	RELEASE=true
fi

[ ! -d build/release ] || [ ! -d build/debug ] || [ ! -d build/unittest ] && RENEW=true

if [ $RENEW = true ]; then
	[ -d build ] && rm -r build
	mkdir -p build/{release,debug,unittest}
fi

if [ $RELEASE = true ]; then
	cd build/release
	[ ! -f Makefile ] && cmake -DCMAKE_BUILD_TYPE=Release ../..
	make
	cd ../..
fi

if [ $DEBUG = true ]; then
	cd build/debug
	[ ! -f Makefile ] && cmake -DCMAKE_BUILD_TYPE=Debug ../..
	make
	cd ../..
fi

if [ $UNITTEST = true ]; then
	cd build/unittest
	[ ! -f Makefile ] && cmake -DCMAKE_BUILD_TYPE=Debug -DBUILD_TEST=ON ../..
	make
	cd ../..
fi
