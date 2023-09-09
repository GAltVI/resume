path=$1
if test -e "$path"; then
 numberOfRecords=$((`wc -l $path | awk '{print $1}'`))
 numberOfUniq=$((`awk '{print $1}' $path | uniq | wc -l`))
 numberOfHashChanges=$(($numberOfRecords - $numberOfUniq))
 echo "$numberOfRecords $numberOfUniq $numberOfHashChanges"
else
 echo "file $path is not found"
fi
