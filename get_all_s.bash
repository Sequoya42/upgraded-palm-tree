
# if [[ $# != 1 ]] ; then
#    echo -e " directory to be created for testing ${NC}"
#     exit 1
# fi

mkdir -p ceci

echo $1
test=`find "$1/" -type f -exec echo '{}' \;`
for i in $test; do
EXT=$(echo "$i" | rev | cut -d . -f1 | rev)
	if [ "$EXT" = "s" ];
	then
	cp $i "ceci"
fi
done