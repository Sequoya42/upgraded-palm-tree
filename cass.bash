GRN="\033[0;32m"
YEL="\033[0;33m"
BLU="\033[0;34m"
RED="\033[0;35m"
NC="\033[0m"

if [[ $# < 2 ]] ; then
    echo -e "${GRN}[2 args needed]\n"
    echo "Supply directory with source [.s] and"
   echo -e " directory to be created for testing ${NC}"
    exit 1
fi

args=("$@")

arg1=${args[0]}
arg2=${args[1]}


ZAZ="/nfs/2014/r/rbaum/corewar_ressources/asm"

ME=$PWD"/asm"

cp -R $arg1 $arg2

for OUTPUT in $(ls $arg1)
do
	SUB=$(echo $OUTPUT | cut -d '.' -f 1)
	EXT=$(echo $OUTPUT | cut -d '.' -f 2)
	RET=$arg2"/"$OUTPUT
	if [ "$EXT" = "s" ];
	then
		FIRST=$arg1"/"$OUTPUT
		SEC=$RET
		if [[ ${args[2]} ]];
		then
			$ZAZ $FIRST > /dev/null 2>&1
			$ME $SEC > /dev/null 2>&1
		else
			echo -e "${YEL}" "\n"
			$ZAZ $FIRST 
			echo -e "${GRN}"  "\n"
			$ME $SEC
		fi
	fi
done
	
for OUTPUT in $(ls $arg1)
do
	SUB=$(echo $OUTPUT | cut -d '.' -f 1)
	EXT=$(echo $OUTPUT | cut -d '.' -f 2)
	if [ "$EXT" = "cor" ];
	then
		FILE_ONE=$arg1"/"$OUTPUT
		FILE_TWO=$arg2"/"$OUTPUT
		# echo -e "${RED} $FILE_ONE \n"
		# echo -e "${BLU} $FILE_TWO \n"
		echo -en "${RED}"
		diff $FILE_ONE $FILE_TWO
	fi
done