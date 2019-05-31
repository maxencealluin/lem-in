# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    script.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnussbau <fnussbau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/08 09:59:50 by fnussbau          #+#    #+#              #
#    Updated: 2019/03/20 14:56:54 by fnussbau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#!/bin/bash

##
##              Comments


echo "\x1B[36m";
echo "\x1B[36m";
echo "\n--- [ ANALYSING LEM_IN] ---";
echo "\x1B[0m";

read -p "Choose map: flow-one (f1) / flow-ten (f10) / flow-thousand (ft) / big (b) / big-super (bs): " TYPE
read -p "How many loop : " LOOP
read -p "Limit max to test: " LIM
read -p "See details ? (y/n) " DET
if [[ $TYPE = "" ]];
then
	TYPE="f1";
fi
if [[ $DET = "" ]];
then
	DET="y";
fi
if [[ $LOOP = "" ]];
then
	LOOP="10";
fi
if [[ $LIM = "" ]];
then
	LIM="10";
fi

MAX=0;
MIN=0;
AV=0
COUNT=0
RE=0
LOG=time.log
MS=0
SEC=0
TIME=0
RESTIME=0
TIMEMAX=0
TIMEMIN=0
TIMEAV=0

if [ $TYPE == 'f1' ] || [ $TYPE == 'f10' ] || [ $TYPE == 'ft' ] || [ $TYPE == 'b' ] || [ $TYPE == 'bs' ]
then
	printf "\n\x1B[36mTesting : $TYPE - $LOOP times\x1B[0m\n\n";
else
	printf "\nInvalid map name\n";
	exit 0;
fi

if [ $TYPE == 'f1' ]
then
	OPT="--flow-one";
elif [ $TYPE == 'f10' ]
then
	OPT="--flow-ten";
elif [ $TYPE == 'ft' ]
then
	OPT="--flow-thousand";
elif [ $TYPE == 'b' ]
then
	OPT="--big";
elif [ $TYPE == 'bs' ]
then
	OPT="--big-superposition";
else
	OPT="--help";
fi

if [[ $DET == "y" ]]
then
	printf "%-15s -- %-15s -- %-15s --\n" "    Generator" "    Lem_in" "Comparison"
fi

	while [[ $LOOP -gt 0 ]];
	do
		./testing/generator_eval $OPT > $TYPE
		REF=$(cat $TYPE | sed -n '$p' | cut -d ' ' -f8);
		TMP=$( (./lem-in < $TYPE | grep L | wc -l) 2>&1 | tee $LOG )
		OUT=$( cat $LOG | head -n1 | sed 's/      //')
		SEC=$( cat $LOG | sed -n '3p' | cut -d ' ' -f2 | cut -d '.' -f1 | cut -d 'm' -f2)
		MS=$( cat $LOG | sed -n '3p' | cut -d ' ' -f2 | cut -d '.' -f2 | cut -d 's' -f1)
		RES=$(( $OUT - $REF ))
		AV=$(( $AV + $RES ))
		if [[ $RES>$MAX ]]
		then
			MAX=$RES
		fi
		if [[ $RES<$MIN ]]
		then
			MIN=$RES
		fi
		if [[ $TIME>$TIMEMAX ]]
		then
			TIMEMAX=$TIME
		fi
		if [[ $TIME<$TIMEMIN ]]
		then
			TIMEMIN=$TIME
		fi
		if [ $RES -gt $LIM ]
		then
			if [[ $DET == "y" ]]
			then
				printf "     %-10d --      %-10d --      \e[31m%-5d\e[39m\n -\n" $REF $OUT $RES
			else
				printf "\e[31m▓\e[39m"
			fi
		else
			if [[ $DET == "y" ]]
			then
				printf "     %-10d --      %-10d --      \e[32m%-5d\e[39m \n" $REF $OUT $RES
			else
				printf "\e[32m▓\e[39m"
			fi
		fi
		rm $TYPE
		LOOP=$(( $LOOP - 1 ));
		COUNT=$(( $COUNT + 1 ));
	done

rm $LOG

AV=$(( $AV / $COUNT ))
printf "\n\n--- %-20s%-20s ---\n" " " "SUMMARY"
printf "%-40s \e[31m% 5d\e[39m\n" "Highest score:" $MAX
printf "%-40s \e[32m% 5d\e[39m\n" "Best score:" $MIN
printf "%-40s % 5d \n" "Average score:" $AV
