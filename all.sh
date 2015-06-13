#!/bin/bash

./format.sh
./document.sh

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

[ $RENEW = true ] && ./build.sh -rn
[ $UNITTEST = true ] && ./build.sh -u
[ $DEBUG = true ] && ./build.sh -d
[ $RELEASE = true ] && ./build.sh

[ $UNITTEST = true ] && ./run.sh -u
[ $DEBUG = true ] && ./run.sh -d
[ $RELEASE = true ] && ./run.sh
